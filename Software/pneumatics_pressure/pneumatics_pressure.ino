#include "Q2HX711.h"
#include "Average.h"

#define button1 3 // boutton de gauche
#define button2 5 // boutton de droite
#define pump 8
#define valv 9

const byte MPS_OUT_pin = 2; // OUT data pin
const byte MPS_SCK_pin = 4; // clock data pin
int avg_size = 10; // #pts to average over

Q2HX711 MPS20N0040D(MPS_OUT_pin, MPS_SCK_pin); // start comm with the HX710B
Average<long> ave(avg_size);



void setup() {
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
                                                                                                                                                                         
  pinMode(pump, OUTPUT);
  pinMode(valv , OUTPUT);

  Serial.begin(115200); // initialisation du port série

}

void loop() {
  
  boolean b1 = digitalRead(button1);
  boolean b2 = digitalRead(button2);
  // 0 = LOW = bouton appuyé , valve ouverte
  // 1 = HIGH = bouton relaché, valve fermée
  
  if(b1 == HIGH and b2 == HIGH)
  {
    Serial.println("Button state : 11 ");
    digitalWrite(pump, LOW); 
    digitalWrite(valv, HIGH);
    ave.push(MPS20N0040D.read());
    Serial.println(ave.mean());
    delay(700);
  }
  
  if(b1 == LOW and b2 == HIGH)
  {
    Serial.println("Button state : 01");
    digitalWrite(pump , HIGH);
    digitalWrite(valv , HIGH);
    ave.push(MPS20N0040D.read());
    Serial.println(ave.mean());
    delay(700);
  }
  
  if(b1 == HIGH and b2 == LOW)
  {
    Serial.println("Button state : 10");
    digitalWrite(pump , LOW);
    digitalWrite(valv , LOW);
    ave.push(MPS20N0040D.read());
    Serial.println(ave.mean());
    delay(700);
  }
  
  if(b1 == LOW and b2 == LOW)
  {
    Serial.println("Button state : 00 #error");
  }
}
