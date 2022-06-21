/*
 * Headers.h
 *
 * Created: 6/21/2022 5:15:40 PM
 *  Author: Dell
 */ 


#ifndef HEADERS_H_
#define HEADERS_H_

#define SET_BIT(byte,PINN)   ((byte) |=  (1<<(PINN)))
#define CLEAR_BIT(byte,PINN) ((byte) &= ~(1<<(PINN)))
#define TOGGLE_BIT(byte,PINN)  ((byte) ^=  (1<<(PINN)))
#define READ_BIT(byte,PINN) ((byte) &   (1<<(PINN)))



#endif /* HEADERS_H_ */