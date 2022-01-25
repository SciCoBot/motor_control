/***********************************************************************************
 *  @file       dual_motor_dc.h
 *  Project     Motor-Control
 *  @brief      Arduino Due library for controlling two DC motors.
 *
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
 
#ifndef DUAL_MOTOR_DC_H
#define DUAL_MOTOR_DC_H

#include "simple_motor_dc.h"

#define DUAL_MOTOR_DEBUG 0 // Debug mode

#if DUAL_MOTOR_DEBUG == 1
	#include <serial_debug.h>
#endif

#pragma message("This library was made for architecture for ARDUINO_ARCH_SAM");

class DualMotor
{
	public:
		
		//DualMotor();
		void init(uint8_t pinIN1_A, uint8_t pinIN2_A,
			     uint8_t pinIN1_B, uint8_t pinIN2_B);

		//MOTOR A
		uint8_t getPwmA();
		void forwardA(uint8_t pwmValForwardA);
		void backwardA(uint8_t pwmValBackwardA);
		void stopA();

		//MOTOR B
		uint8_t getPwmB();
		void forwardB(uint8_t pwmValForwardB);
		void backwardB(uint8_t pwmValBackwardB);
		void stopB();

		//BOTH
		
		void bothForward(uint8_t pwmValForwardBoth);
		void bothBackward(uint8_t pwmValForwardBoth);
		void bothStop();
		void moveRight(uint8_t pwmValRight);
		void moveLeft(uint8_t pwmValLeft);
		

	private:
		SimpleMotor _motorRight;
		SimpleMotor _motorLeft;

};
	
#endif //DUAL_MOTOR_DC_H

