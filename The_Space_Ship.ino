#include <Bounce2.h>

// These are the pins for the red and green LEDS that tell us the hyperdrives state
const int redPin1 = 5;
const int redPin2 = 6;
const int greenPin = 4;

// Set the pin for the button so we can tell the hyperdrive what to do
const int buttonPin = 3;
const int bounceDelay = 5;

// Using the Bounce 2 Library to create a button with debounce functionality
// Read more here:
// https://github.com/thomasfredericks/Bounce2
Bounce hyperButton = Bounce(); // The button will fire up our hyperdrive

void setup() {
  // LED setup
  pinMode(redPin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  // Hyper drive button setup
  hyperButton.attach(buttonPin);
  hyperButton.interval(bounceDelay);
}

// The loop function
void loop() {
  hyperButton.update(); // The value of the Bounce2 button needs to be updated once per loop before reading the value
  int value = hyperButton.read(); // We read the value of the button and pass it to a int called value
  if (value == HIGH) {
    hyperLaunch(); // If the value is HIGH then the hyperdrive is engaged
  } else {
    hyperStandby(); // If the value is LOW then the hyperdrive is in standby
  }
}

// Hyper drive standby function
void hyperStandby() {
  digitalWrite(redPin1, LOW);
  digitalWrite(redPin2, LOW);
  digitalWrite(greenPin, HIGH); // When in standby mode the green LED is on
}

// Hyperdrive engaged functionality
// Flash the red LEDs in sequence to indicate hyperdrive is engaged
void hyperLaunch() {
  digitalWrite(greenPin, LOW); // The green LED must be disabled here
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, LOW);
  delay(100);
  digitalWrite(redPin1, LOW);
  digitalWrite(redPin2, HIGH);
  delay(100);
}

