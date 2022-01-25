/**
 *  @file       simple_motors_dc_control.h
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

#include <simple_motor_dc.h>

//Pins Motor
const unsigned int IN1 = 7;
const unsigned int IN2 = 6;

SimpleMotor motor1;

void setup() {
  
  // Used to display information
  Serial.begin(9600);
  motor1.init(IN1, IN2);
  // Wait for Serial Monitor to be opened
  while (!Serial)
  {
    //do nothing
  }

}

void loop() 
{

  // Tell a motor to go forward with PWM equal to 210
  motor1.forward(210);
  Serial.println("Andando para frente");
  // 1 segunds of Delay 
  delay(1000);
  // Stop motor
  motor1.stop();
  delay(1000);

  // Tell a motor to go backward with PWM equal to 210
  motor1.backward(210);
  Serial.println("Andando para trás");
  delay(1000);
  motor1.stop();
  delay(1000);

  // Disable 
  motor1.enableOff();
  Serial.println("Enable off");
  motor1.backward(210);
  // 2 segunds of Delay 
  delay(2000);

  // Enable 
  motor1.enableOn();
  Serial.println("Enable on");
  motor1.backward(210);
  delay(2000);

  motor1.forward(255);
  Serial.print("O PWM atual é de ");
  // Get the current value of PWM
  Serial.println(motor1.getPwm());
  Serial.println("-------------------------------------");
  delay(1000);
}
