#include "IRremote.h"

const int receiver = 9; // Signal Pin of IR receiver to Arduino Pin 9
const int LedPin = 11; //output to pin 11
int LedState = LOW;

IRrecv irrecv(receiver);
decode_results results;
 
void setup(){
  Serial.begin(9600);
  pinMode(LedPin, OUTPUT);
  Serial.println("IR Controls Online"); 
  irrecv.enableIRIn(); // Start the receiver
}
 
void loop(){
  if (irrecv.decode(&results)){ // have we received an IR signal?
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
}

void translateIR(){ // takes action based on IR code received
 switch(results.value){
  case 0xE0E036C9: digitalWrite(LedPin, HIGH);
    Serial.println(" A Button   Led ON"); break;
  case 0xE0E06897: digitalWrite(LedPin, LOW);
    Serial.println(" D button   Led OFF"); break;
  default:
    Serial.println(" Button not in use"); 

  }
  delay(500); // Do not get immediate repeat
}
