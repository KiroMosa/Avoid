/*
 * avoid.h
 *
 * Created: 01/11/2023 18:48:03
 *  Author: Kirolous Mosa
 */ 


#ifndef AVOID_H_
#define AVOID_H_

#include <Arduino.h>
#include <Servo.h>

class avoid {
	private:
	const int trigPin;		//pin of trigger pin
	const int echoPin;		//pin of echo pin
	const int servoPin;     //pin of servo pin
	Servo servoMotor;
	float getDistance();    //function to get distance
	public:
	avoid(int trigPin, int echoPin, int servoPin);
	void initialize();		//function to pins initialized
	void controlMotor();	//function to pins control Motor
};

#endif /* AVOID_H_ */