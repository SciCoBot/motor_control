/***********************************************************************************
 *  @file       dual_motors.ino
 *  Project     Motor-Control
 *  @brief      Arduino Due library for controlling two DC motors
 *
 * Contains an example using the Dual_Motor_DC library
 *
 *  @author     Otávio Augusto Rocha da Cruz
 *  @bug      	 No known bugs.
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
// IMPORTANT, for debug mode do: #define Simple_Motor_DEBUG 1

// Include the (new) library
#include <dual_motor_dc.h>

//Pin Motor A
const unsigned int IN1_A = 7;
const unsigned int IN2_A = 6;

//Pin Motor B
const unsigned int IN1_B = 5;
const unsigned int IN2_B = 4;

// Initialize both motors
DualMotor motors;

void setup()
{
  // Used to display information
  Serial.begin(9600);
  motors.init(IN1_A, IN2_A, IN1_B, IN2_B);
  // Wait for Serial Monitor to be opened
  while (!Serial)
  {
    //do nothing
  }

}

void loop()
{
  /// Tell the motors to go forward with PWM equal to 255
  motors.bothForward(255);
  Serial.println("Move para frente");
  // 3 segunds of Delay 
  delay(3000);
  // Stop motors
  motors.bothStop();
  
  // Tell the motors to go backward with PWM equal to 255
  motors.bothBackward(255);
  Serial.println("Move para trás");
  // 3 segunds of Delay 
  delay(3000);
  // Stop motors
  motors.bothStop();
  
  // Tell the motor A to go backward with PWM equal to 150
  motors.backwardA(150);
  Serial.println("Move motor A para trás");
  // 3 segunds of Delay 
  delay(3000);
  // Stop motor A
  motors.stopA();
  
  // Tell the motor B to go backward with PWM equal to 150
  motors.backwardB(150);
  Serial.println("Move motor B para trás");
  // 3 segunds of Delay 
  delay(3000);
  // Stop motor B
  motors.stopB();

  // Tell the motor A to go backward with PWM equal to 150
  motors.forwardA(150);
  Serial.println("Move motor A para frente");
  // 3 segunds of Delay 
  delay(3000);
  // Stop motor A
  motors.stopA();
  
  // Tell the motor to go backward with PWM equal to 150
  motors.forwardB(150);
  Serial.println("Move motor B para frente");
  // 3 segunds of Delay 
  delay(3000);
  // Stop motor B
  motors.stopB();
  
  Serial.println("-------------------FIM--------------------");
  // 3 segunds of Delay 
  delay(3000);
}
