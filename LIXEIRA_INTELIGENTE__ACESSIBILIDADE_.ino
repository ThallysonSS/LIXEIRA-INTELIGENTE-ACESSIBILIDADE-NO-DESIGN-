#include <Servo.h>

const int trigPin = 7;
const int echoPin = 6;

Servo servoMotor;

void setup() {
  servoMotor.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (distance <= 20) {
    servoMotor.write(90); // Abre a tampa
  } else {
    servoMotor.write(0); // Fecha a tampa
  }

  delay(500);
}