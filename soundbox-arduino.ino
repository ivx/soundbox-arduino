#include <Bounce2.h>

const int buttonStart = 2;
const int shiftButton = 10;
const int buttonNumber = 11;
bool buttonsPressed[buttonNumber];
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
   debouncer[shiftButton].update();
   if (debouncer[shiftButton].read() == LOW){
     if (!buttonsPressed[shiftButton]) {
       buttonsPressed[shiftButton] = true;
     }
   } else {
     buttonsPressed[shiftButton] = false;
   }
   for (int i=0; i<buttonNumber-1; i++) {
     debouncer[i].update();
     if (debouncer[i].read() == LOW){
       if (!buttonsPressed[i]) {
         buttonsPressed[i] = true;
         int value = i;
         if (buttonsPressed[shiftButton]) { value += 10; }
         Serial.println(value);
       }
     } else {
       buttonsPressed[i] = false;
     }
  }
}
