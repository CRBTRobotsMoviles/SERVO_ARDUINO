#include <Servo.h>  //Se agrega la libreria servo para la señal de pwm de 50HZ.
 
Servo servouno;     //Crea un objeto servo para controlar servouno. 
Servo servodos;     //Crea un objeto servo para controlar servodos.
int adc = 0;
int angulo = 0;

void setup() 
{ 
  servouno.attach(9,600,2400);    // asigna el pin 9 al servouno.
  servodos.attach(10,600,2400);   // asigna el pin 10 al servodos.
  Serial.begin(9600);             // Inicializa puerto serie.
} 
 
void loop() 
{ 
  adc = analogRead(A0);                 // realiza la lectura del potenciometro.
  angulo = map(adc, 0, 1023, 0, 180);   // escala la lectura a un valor entre 0 y 180.
  servouno.write(angulo);               // envia el valor escalado al servouno.
  servodos.write(angulo);               // envia el valor escalado al servodos.
  Serial.print("Angulo:  ");            
  Serial.println(angulo);               //Imprime en el monitor serie el valor digital.
  delay(10);            
} 
