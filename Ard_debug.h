/*
 * Author : Dhimas Prabudi Wicaksa
 * Library made to ease debugging process on Arduino
 * v.1 (07/12/2016)
 */
 
#ifndef Debug_h
#define Debug_h

#include "Arduino.h"

#define on true
#define off false

class Debug
{
  public:
	//print data on DEBUG mode
	int prints(char *str, ...);	
	//force print data, _param_force == 1
	int prints(uint8_t force,char *str, ...);

	//toggle both DEBUG state
	Debug ();
	//toogle DEBUG state of one of the DEBUG mode ("LED" or "PRINT")
	Debug (String name);
	//set certain DEBUG mode to (on) or (off)
	Debug (String name, bool deb);
	//attach LED to DEBUG proccess and toggle "LED" DEBUG state
	Debug (uint8_t pin);
	
	//blink LED on initialized pin on default interval
	void LED();
	//blink LED on _param1 pin on default interval
    void LED(uint8_t pin);
	//blink LED on _param1 pin using _param2 interval	
    void LED(uint8_t pin, int del);
	//blink LED on _param1 pin using _param2 interval, _param3 times.
    void LED(uint8_t pin, int del, uint8_t count);
	
	void setActive(void);
	void setUnactive(void);

  private:
	//attached pin to "LED" DEBUG mode
	uint8_t _pin; 
	//state of "PRINT" and "LED" DEBUG (initial val = false)
	bool _debL = false;
	bool _debP = false;
};

#endif