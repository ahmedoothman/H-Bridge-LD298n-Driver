/*
 * H_Bridge.c
 *
 * Created: 6/21/2022 5:11:57 PM
 *  Author: Ahmed Othman
 */

#include <avr/io.h>
#include "H_Bridge.h"
#include "Headers.h"

	void init_HBridge(void){
		//set h bridge connected pins to output
		HB_Port |= (1<<IN1_dir) | (1<<IN2_dir) | (1<<IN3_dir) | (1<<IN4_dir);
	}


  //set motor to 100% duty cycle 255
  //set set motor speed to 75% duty cycle 191
  //set set motor speed to 50% duty cycle 127
  //set motor to 25% duty cycle 64
  //used Timer0 as fast PWM to control speed
	void set_Motors_Speed(int rightMotor, int leftMotor){
		//set Enable pins to output
		EN_PORT |= (1<<ENA) | (1<<ENB);

		TCCR0B |=(1<<CS00); // select no PRESCALE
		TCCR0A |=(1<<WGM00) |(1<<WGM01); //select PWM
		TCCR0A |=(1<<COM0A1)|(1<<COM0B1);//non inverting

		OCR0B = leftMotor;
		OCR0A = rightMotor;

	}

	void forward(){
		CLEAR_BIT(IN_PORT,IN1);
		SET_BIT(IN_PORT,IN2);
		CLEAR_BIT(IN_PORT,IN3);
		SET_BIT(IN_PORT,IN4);
	}
	void stop(){
		CLEAR_BIT(IN_PORT,IN1);
		CLEAR_BIT(IN_PORT,IN2);
		CLEAR_BIT(IN_PORT,IN3);
		CLEAR_BIT(IN_PORT,IN4);
	}
	void backward(){
		SET_BIT(IN_PORT,IN1);
		CLEAR_BIT(IN_PORT,IN2);
		SET_BIT(IN_PORT,IN3);
		CLEAR_BIT(IN_PORT,IN4);
	}

	void left(){
		//RIGHT MOTOR FORWARD
		CLEAR_BIT(IN_PORT,IN1);
		SET_BIT(IN_PORT,IN2);
		//LEFT MOTOR STOP
		CLEAR_BIT(IN_PORT,IN3);
		CLEAR_BIT(IN_PORT,IN4);
	}
	void right(){
		//RIGHT MOTOR STOP
		CLEAR_BIT(IN_PORT,IN1);
		CLEAR_BIT(IN_PORT,IN2);
		//LEFT MOTOR FORWARD
		CLEAR_BIT(IN_PORT,IN3);
		SET_BIT(IN_PORT,IN4);
	}
	void rotate_right(){
		//RIGHT MOTOR BACKWARD
		SET_BIT(IN_PORT,IN1);
		CLEAR_BIT(IN_PORT,IN2);
		//LEFT MOTOR FORWARD
		CLEAR_BIT(IN_PORT,IN3);
		SET_BIT(IN_PORT,IN4);
	}
	void rotate_left(){
		//RIGHT MOTOR FORWARD
		CLEAR_BIT(IN_PORT,IN1);
		SET_BIT(IN_PORT,IN2);
		//LEFT MOTOR BACKWARD
		SET_BIT(IN_PORT,IN3);
		CLEAR_BIT(IN_PORT,IN4);
	}
