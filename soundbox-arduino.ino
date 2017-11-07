#include <Bounce2.h>

// Declare the pins for the Button and the LED<br>
int buttonPin = 12;
int LED = 13;
int count = 0;
bool pressed = false;
Bounce debouncer = Bounce(); 

void setup() {
   Serial.begin(9600);
   pinMode(buttonPin, INPUT_PULLUP);
   pinMode(LED, OUTPUT);

   debouncer.attach(buttonPin);
   debouncer.interval(5);
}

void loop(){
   debouncer.update();
   int buttonValue = debouncer.read();
   if (buttonValue == LOW){
      if (!pressed) {
        count++;
        pressed = true;
        Serial.println(count);
      }
   } else {
      pressed = false;
   }
}
