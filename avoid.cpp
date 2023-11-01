#include "avoid.h"

avoid::avoid(int trigPin, int echoPin, int servoPin)
: trigPin(trigPin), echoPin(echoPin), servoPin(servoPin), servoMotor() {}
//initialize the pins and setup 
void avoid::initialize() {
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	servoMotor.attach(servoPin);
}
//function to calculate distance
float avoid::getDistance() {
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	long duration = pulseIn(echoPin, HIGH);

	float distance = duration * 0.0344 / 2;
	return distance;
}
//motoring of servo to control motion
void avoid::controlMotor() {
	float distance = getDistance();
	if (distance > 10) {
		servoMotor.write(90);
		} else {
		servoMotor.write(180);
		delay(500);
		servoMotor.write(0);
		delay(500);
	}
}