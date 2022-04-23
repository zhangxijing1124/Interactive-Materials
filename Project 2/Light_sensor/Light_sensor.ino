

const int backsideLedPin = 9;
const int lightSensorPin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(backsideLedPin, OUTPUT);
  pinMode(lightSensorPin, INPUT);
}

void loop() {
  int lightSensorStatus = analogRead(lightSensorPin);

  // When lightSensorStatus <= 18, turn on led, when lightSensorStatus > 18, turn off led
  if (lightSensorStatus <= 18)
  { 
    digitalWrite(backsideLedPin, HIGH);
    Serial.print("Its Dark, Turn on the LED:");
    Serial.println(lightSensorStatus);
  } else {
    digitalWrite(backsideLedPin, LOW);
    Serial.print("Its Bright, Turn off the LED:");
    Serial.println(lightSensorStatus);
  }

}
