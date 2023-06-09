#define MOTOR_PIN 6
#define POTENTIOMETER_PIN A1
int potentiometerValue;
int speed;
void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potentiometerValue = analogRead(A1);
  speed = map(potentiometerValue, 0, 1023, 0, 255);
  analogWrite(MOTOR_PIN, speed);
}
