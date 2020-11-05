#include <SoftwareSerial.h>//libreria de bluetooth
//pines de entrada y salida de daos del bluetooth
SoftwareSerial miBT(0,1);//0:tdx de bluethooth
char DATO=0;
//pines del controlador de motor
 int a=4;
 int b=5;
 int c=6;
 int d=7;
//pines analogicos para controlar las velocidades 
int vel_a=9;//para el lado derecho
int vel_b=3;//para el lado izquerdo 
void setup() {
  Serial.begin(9600);
  Serial.println("estamos listos");
  miBT.begin(38400);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);  
  pinMode(vel_a,OUTPUT);
  pinMode(vel_b ,OUTPUT);
}

void loop() {
 if(miBT.available())//lee BT y envia a arduino  
 {
 //datos que recogera el bluetooth
 DATO=miBT.read();
 //controlador de velocidad
 analogWrite(vel_a,255);//ladod derecho
 analogWrite(vel_b,255);//lado izquierdo
 //moviviento hacia adelante
    if(DATO=='2'){
         digitalWrite(a,LOW);
         digitalWrite(b,!digitalRead(b));
         digitalWrite(c,LOW);
         digitalWrite(d,!digitalRead(d));
      }
 //moviviento hacia izquierda     
    if(DATO=='4'){
         digitalWrite(a,HIGH);
         digitalWrite(b,LOW);
         digitalWrite(c,LOW);
         digitalWrite(d,HIGH);
         //analogWrite(vel_b,100);
    
    }
  //STOP
    if (DATO=='5'){
          digitalWrite(a,LOW);
          digitalWrite(b,LOW);
          digitalWrite(c,LOW);
          digitalWrite(d,LOW);
    }
  //moviviento hacia la derecha  
     if (DATO=='6'){
          digitalWrite(a,LOW);
          digitalWrite(b,HIGH);
          digitalWrite(c,HIGH);
          digitalWrite(d,LOW);
    }
 //movimiento hacia atras
    if (DATO=='8'){
          digitalWrite(a,HIGH);
          digitalWrite(b,LOW);
          digitalWrite(c,HIGH);
          digitalWrite(d,LOW);
    }  
   }
}
