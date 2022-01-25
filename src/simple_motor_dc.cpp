/***********************************************************************************
 *  @file       simple_motor_dc.cpp
 *  Project     serial_debug
 *  @brief      Arduino Due library for controlling one DC motors.
 *
 *  @author     Otávio Augusto Rocha da Cruz
 *  @bug 		 No known bugs.
 *  License     MIT
 *
 *  @section License
 *
 * Copyright (c) 2021 SciCoBot
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**********************************************************************************/
#include "simple_motor_dc.h"

void SimpleMotor::init(uint8_t pinIN1, uint8_t pinIN2)
{
  _pinIN1 = pinIN1;
  _pinIN2 = pinIN2;
  _pwmVal = 255; 

  pinMode(_pinIN1, OUTPUT);
  pinMode(_pinIN2, OUTPUT);
  
  _enable = true;
  
  #if SIMPLE_MOTOR_DEBUG == 1
	  DEBUG("Pin IN1: ");
	  DEBUGLN(_pinIN1);
	  
	  DEBUG("Pin IN2: ");
	  DEBUGLN(_pinIN2);
	  
	  DEBUGLN("Init sucess");
	  
	  SEPARATOR();
  #endif
}

void SimpleMotor::setEnable(bool enable)
{
   _enable = enable;
}

bool SimpleMotor::getEnable()
{
	return _enable;
}

uint8_t SimpleMotor::getPwm()
{
  return _pwmVal;
}

void SimpleMotor::forward(uint8_t pwmValForward)
{
	if(_enable == false)
	{
		#if SIMPLE_MOTOR_DEBUG == 1
			DEBUGLN("Enable is false, no move forward");
			SEPARATOR();
		#endif

	return ;
	}
	else
	{
		_pwmVal = pwmValForward;
		digitalWrite(_pinIN1, LOW);
		analogWrite(_pinIN2, _pwmVal);

	#if SIMPLE_MOTOR_DEBUG == 1
		DEBUG("Forward with PWM = ");
		DEBUGLN(_pwmVal);
		SEPARATOR();
	#endif
	}
}

void SimpleMotor::backward(uint8_t pwmValBackward)
{
	if(_enable == false)
	{
		#if SIMPLE_MOTOR_DEBUG == 1
			DEBUGLN("Enable is false, no move backward");
			SEPARATOR();
		#endif

	return ;
	}
	else
	{  
		_pwmVal = pwmValBackward;
		analogWrite(_pinIN1, _pwmVal);
		digitalWrite(_pinIN2, LOW);

		#if SIMPLE_MOTOR_DEBUG == 1
			DEBUG("Backward with PWM = ");
			DEBUGLN(_pwmVal);
			SEPARATOR();
		#endif
	}
}

void SimpleMotor::stop()
{
	digitalWrite(_pinIN1, LOW);
	digitalWrite(_pinIN2, LOW);
	

	#if SIMPLE_MOTOR_DEBUG == 1
		DEBUGLN("Stop");
		SEPARATOR();
	#endif
}

void SimpleMotor::enableOff()
{
	digitalWrite(_pinIN1, LOW);
	digitalWrite(_pinIN2, LOW);
	
	this->setEnable(false);
	
	#if SIMPLE_MOTOR_DEBUG == 1
		DEBUG("Enable is ");
		DEBUGLN(_enable);
		SEPARATOR();
	#endif
}

void SimpleMotor::enableOn()
{
	
	this->setEnable(true);
	
	#if SIMPLE_MOTOR_DEBUG == 1
		DEBUG("Enable is ");
		DEBUGLN(_enable);
		SEPARATOR();
	#endif
}



