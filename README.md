![image](https://github.com/scowp/MedidorTemperatura/assets/100418456/fa915d58-9829-4152-a065-b09aa8c80690)

# Documentação do Projeto de Medição de Temperatura com Arduino e LM35

## Visão Geral

Este projeto utiliza o Arduino em conjunto com o sensor de temperatura LM35 para medir a temperatura ambiente. Com base na temperatura medida, três LEDs indicam diferentes faixas de temperatura. O código fornece funcionalidades para a leitura da temperatura, exibição no monitor serial e controle dos LEDs de acordo com os diferentes intervalos de temperatura.

## Componentes Necessários

- Arduino Uno ou similar
- Sensor de temperatura LM35
- Três LEDs (vermelho, amarelo e verde)
- Três resistores (para limitar a corrente dos LEDs)
- Jumpers para conexões

## Esquema de Ligação

Conecte os componentes da seguinte maneira:

- LM35:
  - Pino VCC ao 5V do Arduino
  - Pino GND ao GND do Arduino
  - Pino de saída ao pino A0 do Arduino

- LEDs:
  - LED verde: Pino positivo ao pino 11 do Arduino, pino negativo ao GND do Arduino
  - LED amarelo: Pino positivo ao pino 12 do Arduino, pino negativo ao GND do Arduino
  - LED vermelho: Pino positivo ao pino 13 do Arduino, pino negativo ao GND do Arduino

## Código

```cpp
//sensor de temperatura usando o LM35
#define ledRed 13
#define ledYellow 12
#define ledGreen 11

const int LM35 = A0; //define o pino que lera a saida do LM35
int temperatura; // variavel que armazenara a temperatura medida

//funcao que sera executada uma vez quando ligar ou resetar o arduino
void setup()
{
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  
  Serial.begin(9600); //inicializa a comunicacao serial
}

void loop()
{
  temperatura = int((float(analogRead(LM35))*5/(1024.0))/0.01);
  Serial.println(temperatura);
  delay(2000);
  
  if(temperatura < 25){
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
  } else if (temperatura <= 30 && temperatura >= 25){
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, LOW);
  } else if (temperatura > 30){
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);
  }
}
