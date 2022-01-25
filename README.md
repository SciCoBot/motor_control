# motor_control

[![platform badge](https://img.shields.io/badge/platform-Arduino-orange.svg)](https://github.com/arduino)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/SciCoBot/serial_debug/blob/main/LICENSE)

## Conteúdo

- [Sobre](#sobre)
- [Comandos Básicos](#comandos-básicos)
- [Possíveis Atualizações](#possíveis-atualizações)
- [Anotações de Desenvolvimento](#anotações-de-desenvolvimento)


# Sobre

A biblioteca motor_control implementa funções para **uso com L298N Dual H Bridge DC/Stepper Motor Driver e Arduino Due** a fim de movimentar motores DC. 
Ela foi pensada **sem o uso do pino ENABLE**.

## Comandos Básicos
### Definições

- **SIMPLE_MOTOR_DEBUG:** usada para definir o código a ser compilado para *simple_motor_dc.h*, de acordo com a necessidade de debug serial. Evitando uso desnecessário de memória. Use 1 para habilitar. Por default é igual a 0.
- **DUAL_MOTOR_DEBUG:** sada para definir o código a ser compilado para *dual_motor_dc.h*, de acordo com a necessidade de debug serial. Evitando uso desnecessário de memória. Use 1 para habilitar. Por default é igual a 0.
### Funções

SimpleMotor: para controle de um motor DC por vez.

- **SimpleMotor::init(pinIN1, pinIN2):** inicia um objeto para controle de um motor DC a partir dos parâmetros especificados;
- *SimpleMotor::forward(pwmValForward):** envia sinal PWM que rotaciona o motor para frente, caso _enable seja igual a true, com PWM igual a *pwmValForward*;
- **SimpleMotor::backward(pwmValBackward):** envia sinal PWM que rotaciona o motor para trás, caso _enable seja igual a true, com PWM igual a  *pwmValBackward*;
- **SimpleMotor::stop():** para a rotação do motor;
- **SimpleMotor::enableOff():** muda o valor da variável _enable para *false*;
- **SimpleMotor::enableOn():** muda o valor da variável _enable para *true*;
- **SimpleMotor::getEnable():** retorna o valor da variável _enable;
- **SimpleMotor::getPwm():** retorna o valor de PWM em execução no motor;

DualMotor: para controle de dois motores DC por vez.

- **init(pinIN1_A, pinIN2_A, pinIN1_B, pinIN2_B):** inicia um objeto para controle de um motor DC a partir dos parâmetros especificados;
- **getPwmA():** retorna o valor do PWM do motor A;
- **forwardA(pwmValForwardA):** envia sinal PWM que rotaciona o motor A para frente, caso _enable seja igual a true, com PWM igual a *pwmValForwardA*;
- **backwardA(pwmValBackwardA):** envia sinal PWM que rotaciona o motor A para trás, caso _enable seja igual a true, com PWM igual a *pwmValBackwardA*;
- **stopA():** para o motor A;
- **getPwmB():** retorna o valor do PWM do motor B;
- **forwardB(pwmValForwardB):** envia sinal PWM que rotaciona o motor B para frente, caso _enable seja igual a true, com PWM igual a *pwmValForwardB*;
- **backwardB(pwmValBackwardB):** envia sinal PWM que rotaciona o motor B para trás, caso _enable seja igual a true, com PWM igual a *pwmValBackwardB*;
- **stopB():** para o motor B.
- **bothForward(pwmValForwardBoth):** envia sinal PWM que rotaciona os dois motores frente, caso _enable seja igual a true, com PWM igual a *pwmValForwardBoth*;
- **bothBackward(pwmValForwardBoth):** envia sinal PWM que rotaciona os dois motores trás, caso _enable seja igual a true, com PWM igual a *pwmValForwardBoth*;
- **bothStop():** para os dois motores;
- **moveRight(pwmValRight):** rotaciona o robô pela direita;
- **moveLeft(pwmValLeft):** rotaciona o robô pela esquerda;

**O sentido de rotação depende da conexão fisica. Caso o comando não corresponda ao movimento real, troque a conexão dos pinos de entrada.** 

## Possíveis Atualizações



## Anotações de Desenvolvimento

- Avaliar github actions para atualizar a bibliteca debug automaticamente.
