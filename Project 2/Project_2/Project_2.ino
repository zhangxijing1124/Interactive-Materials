

// Defines ultrasoninc
#define echoPin 7 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 8 //attach pin D3 Arduino to pin Trig of HC-SR04

// Light sensor
const int backsideLedPin = 9;
const int lightSensorPin = A0;

// Defines ultrasoninc variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

// Frontside led arrays
const int redLedPin01 = 11;
const int yellowLedPin01 = 12;
const int greenLedPin01 = 2;
const int yellowLedPin02 = 3;
const int redLedPin02 = 4;
const int negative = 5;

void setup() {

  // Set ultrasoninc
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

  // Light sensor
  pinMode(backsideLedPin, OUTPUT);
  pinMode(lightSensorPin, INPUT);

  // Led arrays frontside
  pinMode(redLedPin01, OUTPUT);
  pinMode(yellowLedPin01, OUTPUT);
  pinMode(greenLedPin01, OUTPUT);
  pinMode(yellowLedPin02, OUTPUT);
  pinMode(redLedPin02, OUTPUT);

  pinMode(negative, OUTPUT);
}

void redLedPin01On() {
  digitalWrite(redLedPin01, HIGH);
  digitalWrite(negative, LOW);
}

void yellowLedPin01On() {
  digitalWrite(yellowLedPin01, HIGH);
  digitalWrite(negative, LOW);
}

void greenLedPin01On() {
  digitalWrite(greenLedPin01, HIGH);
  digitalWrite(negative, LOW);
}

void yellowLedPin02On() {
  digitalWrite(yellowLedPin02, HIGH);
  digitalWrite(negative, LOW);
}

void redLedPin02On() {
  digitalWrite(redLedPin02, HIGH);
  digitalWrite(negative, LOW);
}



void redLedPin01Off() {
  digitalWrite(redLedPin01, LOW);
  digitalWrite(negative, LOW);
}

void yellowLedPin01Off() {
  digitalWrite(yellowLedPin01, LOW);
  digitalWrite(negative, LOW);
}

void greenLedPin01Off() {
  digitalWrite(greenLedPin01, LOW);
  digitalWrite(negative, LOW);
}

void yellowLedPin02Off() {
  digitalWrite(yellowLedPin02, LOW);
  digitalWrite(negative, LOW);
}

void redLedPin02Off() {
  digitalWrite(redLedPin02, LOW);
  digitalWrite(negative, LOW);
}


void loop() {

//  redLedPin01On();
//  yellowLedPin01On();
//  greenLedPin01On();
//  yellowLedPin02On();
//  redLedPin02On();

  // Ultrasoninc ouput code
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Light sensor
  int lightSensorStatus = analogRead(lightSensorPin);

  // When lightSensorStatus <= 18, turn on led, when lightSensorStatus > 18, turn off led
  if (lightSensorStatus <= 18)
  { 
    digitalWrite(backsideLedPin, HIGH);
//    Serial.print("Its Dark, Turn on the LED:");
//    Serial.println(lightSensorStatus);
  } else {
    digitalWrite(backsideLedPin, LOW);
//    Serial.print("Its Bright, Turn off the LED:");
//    Serial.println(lightSensorStatus);
  }

  if (distance >= 150) {
    
    redLedPin01Off();
    yellowLedPin01Off();
    greenLedPin01On();
    yellowLedPin02Off();
    redLedPin02Off();
    
  } else if (distance < 150 && distance >= 50) {
    
    redLedPin01Off();
    yellowLedPin01On();
    greenLedPin01Off();
    yellowLedPin02On();
    redLedPin02Off();
    
  } else {

    redLedPin01On();
    yellowLedPin01Off();
    greenLedPin01Off();
    yellowLedPin02Off();
    redLedPin02On();
  }

  delay(200);

}
