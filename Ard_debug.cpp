/*
 * Author : Dhimas Prabudi Wicaksa
 * Library made to ease debugging process on Arduino
 * v.1 (07/12/2016)
 */

#include "Debug.h"
#include "Arduino.h"


Debug::Debug()
{
	_debL = !_debL;
	_debP = !_debL;
}

Debug::Debug (String name, bool deb)
{
	if (name == "LEDS")
		_debL = deb; else
	if (name == "PRINT")
		_debP = deb;
}

Debug::Debug (String name)
{
	if (name == "LED")
		_debL = !_debL; else
	if (name == "PRINT")
		_debP = _debP;	
}

Debug::Debug (uint8_t pin)
{
	_pin = pin;
	pinMode(_pin,OUTPUT);
	_debL = !_debL;
}


void Debug::LED()
{
	if (_debL)
	{	
	digitalWrite(_pin,HIGH);
	delay(100);
	digitalWrite(_pin,LOW);
	delay(100);	
	}
}

void Debug::LED(uint8_t pin)
{
	if (_debL)
	{	
	pinMode(pin,OUTPUT);
	digitalWrite(pin,HIGH);
	delay(100);
	digitalWrite(pin,LOW);
	delay(100);
	}
}
void Debug::LED(uint8_t pin, int del)
{
	if (_debL)
	{	
	pinMode(pin,OUTPUT);
	digitalWrite(pin,HIGH);
	delay(del);
	digitalWrite(pin,LOW);
	delay(del);
	}
}	
void Debug::LED(uint8_t pin, int del, uint8_t count)
{
uint8_t i;
	pinMode(pin,OUTPUT);
	if (_debL)
	{	
	for (i=0;i<count;i++)
	{	digitalWrite(pin,HIGH);
		delay(del);
		digitalWrite(pin,LOW);
		delay(del);	
	}
	}
}


int Debug::prints(char *str, ...) 
{
	int i, j, count = 0;
	if(_debP)
	{
		va_list argv;
		va_start(argv, str);
		for(i = 0, j = 0; str[i] != '\0'; i++) 
		{
			if (str[i] == '%') 
			{
			count++;
			Serial.write(reinterpret_cast<const uint8_t*>(str+j), i-j);
			switch (str[++i]) 
				{
				case 'd': Serial.print(va_arg(argv, int));
					break;
				case 'l': Serial.print(va_arg(argv, long));
					break;
				case 'f': Serial.print(va_arg(argv, double));
					break;
				case 'c': Serial.print((char) va_arg(argv, int));
					break;
				case 's': Serial.print(va_arg(argv, char *));
					break;
				case '%': Serial.print("%");
					break;
				default:;
				};
			j = i+1;
			}
		};
	va_end(argv);
	if(i > j) Serial.write(reinterpret_cast<const uint8_t*>(str+j), i-j);
	Serial.println();
	}
	return count;
}

int Debug::prints(uint8_t force,char *str, ...) 
{
	int i, j, count = 0;
	if(force)
	{
		va_list argv;
		va_start(argv, str);
		for(i = 0, j = 0; str[i] != '\0'; i++) 
		{
			if (str[i] == '%') 
			{
			count++;
			Serial.write(reinterpret_cast<const uint8_t*>(str+j), i-j);
			switch (str[++i]) 
				{
				case 'd': Serial.print(va_arg(argv, int));
					break;
				case 'l': Serial.print(va_arg(argv, long));
					break;
				case 'f': Serial.print(va_arg(argv, double));
					break;
				case 'c': Serial.print((char) va_arg(argv, int));
					break;
				case 's': Serial.print(va_arg(argv, char *));
					break;
				case '%': Serial.print("%");
					break;
				default:;
				};
			j = i+1;
			}
		};
	va_end(argv);
	if(i > j) Serial.write(reinterpret_cast<const uint8_t*>(str+j), i-j);
	Serial.println();
	}
	return count;
}


void Debug::setActive(void)
{
	_debP = true;
	_debL = true;
}

void Debug::setUnactive(void)
{
	_debP = false;
	_debL = false;
}