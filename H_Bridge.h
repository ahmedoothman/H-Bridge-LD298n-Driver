/*
 * H_Bridge.h
 *
 * Created: 6/21/2022 5:12:25 PM
 *  Author: Ahmed Othman
 */ 

/*

This Driver wrote for atmega328p and for only two motors 
Right Motor Connected to IN1 and IN2 and OC0A
Left Motor Connected to IN3 and IN4 and OC0B

*/

#ifndef H-BRIDGE_H_
#define H-BRIDGE_H_

#define  F_CPU 1000000UL
#define HB_Port DDRD
#define IN1_dir DDD0
#define IN2_dir DDD1
#define IN3_dir DDD2
#define IN4_dir DDD3

#define IN_PORT PORTD
#define IN1 PORTD0
#define IN2 PORTD1
#define IN3 PORTD2
#define IN4 PORTD3

#define EN_PORT DDRD
#define ENA PORTD6 //OC0A
#define ENB PORTD5 //OC0B

void init_HBridge(void);
void set_Motors_Speed(int rightMotor, int leftMotor);
void forward();
void backward();
void right();
void left();
void stop();
void rotate_right();
void rotate_left();
	


#endif /* H-BRIDGE_H_ */