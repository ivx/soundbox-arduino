#include <Bounce2.h>

const int buttonStart = 2;
const int buttonNumber = 11;
bool buttonsPressed[buttonNumber];
int buttonValues[buttonNumber];
Bounce debouncer[buttonNumber];

void setup() {
   Serial.begin(9600);
   for (int i=0; i<buttonNumber; i++) {
     buttonsPressed[i] = false;
     debouncer[i] = Bounce();
     int buttonPin = i + buttonStart;
     pinMode(buttonPin, INPUT_PULLUP);
     debouncer[i].attach(buttonPin);
     debouncer[i].interval(5);
   }
}

void loop(){
   for (int i=0; i<buttonNumber; i++) {
     debouncer[i].update();
     if (debouncer[i].read() == LOW){
       if (!buttonsPressed[i]) {
         buttonsPressed[i] = true;
         Serial.println( i );
       }
     } else {
       buttonsPressed[i] = false;
     }
  }
}
