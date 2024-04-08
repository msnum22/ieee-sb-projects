#include <Arduino.h>

#define POWER_PIN 10  // ESP32's pin GPIO10 that provides the power to the rain sensor
#define DO_PIN 5     // ESP32's pin GPIO5 connected to DO pin of the rain sensor
#define AO_PIN 1

void setup() {
  // initialize serial communication
  Serial.begin(9600);
  
  pinMode(POWER_PIN, OUTPUT);  // configure the power pin pin as an OUTPUT
  pinMode(DO_PIN, INPUT);
  pinMode(AO_PIN, INPUT); // initialize the ESP32's pin as an input
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  // turn the rain sensor's power  ON
  delay(10);                      // wait 10 milliseconds

  int rain_state = digitalRead(DO_PIN);
  int rain_amount = map(analogRead(AO_PIN), 8191, 0, 0, 100);
  digitalWrite(POWER_PIN, LOW);  // turn the rain sensor's power OFF
  Serial.print("Rain Percentage: ");
  Serial.println(rain_amount);
  delay(1000);
}