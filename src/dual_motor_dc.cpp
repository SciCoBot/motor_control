/***********************************************************************************
 *  @file       dual_motor_dc.cpp
 *  Project     Motor-Control
 *  @brief      Arduino Due library for controlling two DC motors.
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
 
#include "dual_motor_dc.h"
#include "simple_motor_dc.h"


void DualMotor::init(uint8_t pinIN1_A, uint8_t pinIN2_A,
                 uint8_t pinIN1_B, uint8_t pinIN2_B) 
{
  _motorRight.init(pinIN1_A, pinIN2_A);

  _motorLeft.init(pinIN1_B, pinIN2_B);
  
  #if DUAL_MOTOR_DEBUG == 1
  	DEBUGLN("Init DualMotor sucess");
  #endif
}


//Motor A

uint8_t DualMotor::getPwmA()
{
  return _motorRight.getPwm();
}

void DualMotor::forwardA(uint8_t pwmValForwardA)
{
  _motorRight.forward(pwmValForwardA);
}

void DualMotor::backwardA(uint8_t pwmValBackwardA)
{
  _motorRight.backward(pwmValBackwardA);
}

void DualMotor::stopA()
{
  _motorRight.stop();
}


//Motor B

uint8_t DualMotor::getPwmB()
{
  return _motorLeft.getPwm();
}

void DualMotor::forwardB(uint8_t pwmValForwardB)
{
  _motorLeft.forward(pwmValForwardB);
}
void DualMotor::backwardB(uint8_t pwmValBackwardB)
{
  _motorLeft.backward(pwmValBackwardB);
}

void DualMotor::stopB()
{
  _motorLeft.stop();
}


// Both


void DualMotor::bothForward(uint8_t pwmValForwardBoth)
{
  #if DUAL_MOTOR_DEBUG == 1
  	DEBUGLN("Move both forward");
  #endif
  
   _motorRight.forward(pwmValForwardBoth);
  _motorLeft.forward(pwmValForwardBoth);
}

void DualMotor::bothBackward(uint8_t pwmValForwardBoth)
{
  #if DUAL_MOTOR_DEBUG == 1
  	DEBUGLN("Move both backward");
  #endif
  
  _motorRight.backward(pwmValForwardBoth);
  _motorLeft.backward(pwmValForwardBoth);
}

void DualMotor::bothStop()
{
  #if DUAL_MOTOR_DEBUG == 1
  DEBUGLN("Both stop");
  #endif
  
  _motorRight.stop();
  _motorLeft.stop();
  
}

void DualMotor::moveRight(uint8_t pwmValRight) 
{
  #if DUAL_MOTOR_DEBUG == 1
  	DEBUGLN("Move right");
  #endif

  _motorRight.forward(pwmValRight);
  _motorLeft.backward(pwmValRight);
  
}
void DualMotor::moveLeft(uint8_t pwmValLeft) 
{
  #if DUAL_MOTOR_DEBUG == 1
  	DEBUGLN("Move left");
  #endif
  
  _motorRight.backward(pwmValLeft);
  _motorLeft.forward(pwmValLeft);
}




