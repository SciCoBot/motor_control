/***********************************************************************************
 *  @file       simple_motor_dc.h
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

//Observation: this library no use pin ENABLE 

#ifndef SIMPLE_MOTOR_DC_H
#define SIMPLE_MOTOR_DC_H

#include <Arduino.h>

#define SIMPLE_MOTOR_DEBUG 0 // Debug mode

#if SIMPLE_MOTOR_DEBUG == 1
	#include <serial_debug.h>
#endif

#pragma message("This library was made for architecture for ARDUINO_ARCH_SAM");
	
class SimpleMotor
{
	public:

		void init(uint8_t pinIN1, uint8_t pinIN2);
		uint8_t getPwm();
		void forward(uint8_t pwmValForward = 255);
		void backward(uint8_t pwmValBackward = 255);
		void stop();
		void enableOff();
		void enableOn();
		bool getEnable();
		
		
	private:
		
		void setEnable(bool enable);
		bool _enable = false;
		uint8_t _pinIN1;
		uint8_t _pinIN2;
		uint8_t _pwmVal;
};

#endif //SIMPLE_MOTOR_DC_H

