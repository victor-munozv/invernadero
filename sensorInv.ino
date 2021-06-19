void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);// pin 13 como salida
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,HIGH);//encender pin 13
delay(1000);// delay significa espera
digitalWrite(13,LOW);// ahora le dice que se apague
delay(3000);//otro espera para que este apagado 
}
