/*
turn on a LED when the button is pressed and stays on 
until the button is pressed again
*/
int pinButton = 4;
int LED = 8;
int stateLED = LOW;
int stateButton;
int previous = LOW;
long time = 0;
long debounce = 5000;

void setup() {
  Serial.begin(9600);
  pinMode(pinButton, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  stateButton = digitalRead(pinButton);  
  if(stateButton == HIGH && previous == LOW && millis() - time > debounce) {
    if(stateLED == HIGH){
      stateLED = LOW;
      Serial.println("OFF");
    } else {
       stateLED = HIGH;
       Serial.println("ON"); 
    }
    time = millis();
  }
  digitalWrite(LED, stateLED);
  previous == stateButton;
}
