
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
  
  Serial.begin(9600);//inicializa a comunicacao serial
}

void loop()
{
  
  temperatura = int((float(analogRead(LM35))*5/(1024.0))/0.01);
  Serial.println(temperatura);
  delay(2000);
  
  if(temperatura<25){
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
    
  } else if (temperatura <= 30 && temperatura >= 25){
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, LOW);
   
  } else if (temperatura>30){
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);
  }

  
}
