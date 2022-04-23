

int wirePin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(wirePin, OUTPUT);
}

void loop() {


  digitalWrite(wirePin, LOW);
  Serial.println("01");
  delay(500);
  digitalWrite(wirePin, HIGH);
  Serial.println("02");
  delay(500);
}
