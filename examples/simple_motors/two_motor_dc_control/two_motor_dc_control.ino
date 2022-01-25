/***********************************************************************************
 *  @file       two_motor_dc_control.h
 *  Project     Motor-Control
 *  @brief      Arduino Due library for controlling two DC motors
 *
 * Contains an example using the Dual_Motor_DC library
 *
 *  @author     Otávio Augusto Rocha da Cruz
 *  @bug        No known bugs.
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
#include <simple_motor_dc.h>

//Pins Motor
const unsigned int IN1_A = 7;
const unsigned int IN2_A = 6;

//Pins Motor
const unsigned int IN1_B = 5;
const unsigned int IN2_B = 4;

SimpleMotor motor1;
SimpleMotor motor2(IN1_B, IN2_B);

void setup() {
  
  // Used to display information
  Serial.begin(9600);
  motor1.begin(IN1_A, IN2_A);
  motor2.begin(IN1_A, IN2_A);
  // Wait for Serial Monitor to be opened
  while (!Serial)
  {
    //do nothing
  }

}

void loop() 
{

  // Tell a motorS to go forward with PWM equal to 210
  motor1.forward(210);
  motor2.forward(210);
  Serial.println("Andando para frente");
  // 1 segunds of Delay 
  delay(1000);
  // Stop motorS
  motor1.stop();
  motor2.stop();
  delay(1000);

  // Tell a motorS to go backward with PWM equal to 210
  motor1.backward(210);
  motor2.backward(210);
  Serial.println("Andando para trás");
  delay(1000);
  motor1.stop();
  motor2.stop();
  delay(1000);

  // Disable motors
  motor1.enableOff();
  motor2.enableOff();
  Serial.println("Enable off");
  motor1.backward(210);
  motor2.backward(210);
  // 2 segunds of Delay 
  delay(2000);

  // Enable motors
  motor1.enableOn();
  motor2.enableOn();
  Serial.println("Enable on");
  motor1.backward(210);
  motor2.backward(210);
  delay(2000);

  motor1.forward(255);
  motor2.forward(255);
  Serial.print("O PWM atual da roda A é ");
  // Get the current value of PWM
  Serial.println(motor1.getPwm());
  Serial.print("O PWM atual da roda B é ");
  // Get the current value of PWM
  Serial.println(motor2.getPwm());
  Serial.println("-------------------------------------");
  delay(1000);
  motor1.stop();
  motor2.stop();
}
