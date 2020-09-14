#include <Bounce2.h>

#include <FastLED.h>

//FastLED stuff

#define NUM_LEDS 16
#define DATA_PIN 3 //LED pin
CRGB leds[NUM_LEDS];

uint8_t hue = 0;

//Bounce2 stuff

const int buttonPin = 6; //Pro Micro pin for your button
Bounce pushbutton = Bounce(buttonPin, 10);  // 10 ms debounce

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  //might have to change "GRB" to "RGB" or "BGR" or whatever depending on your LED strip
}

//all the button code was copied from the Bounce2 tutorial
byte previousState = HIGH;         // what state was the button last time
unsigned int count = 0;            // how many times has it changed to low
unsigned long countAt = 0;         // when count changed
unsigned int countPrinted = 0;     // last count printed

void loop() {
  
  //RGB cycle code
  EVERY_N_MILLISECONDS(100) { //embedded function in FastLED library - you can also do EVERY_N_SECONDS()
    hue++;
  }
  
  //this has to be outside the pushbutton switch statement below, since it's constantly cycling colors
  if(count % 3 == 0){
    fill_solid(leds, NUM_LEDS, CHSV(hue, 255, 255));
  }
  
  //again, all the code for the button was copied from the Bounce2 tutorial
  if (pushbutton.update()) {
    if (pushbutton.fallingEdge()) {
      count = count + 1;
      countAt = millis();
    }
  } else {
    if (count != countPrinted) {
      unsigned long nowMillis = millis();
      if (nowMillis - countAt > 100) {
        //if you want to add a case, increment what you're modulo-ing count by
        switch(count % 3){
          case 1:
            fill_solid(leds, NUM_LEDS, CHSV(255, 130, 255)); //pink led to match my setup
            break;
          case 2:
            fill_solid(leds, NUM_LEDS, CHSV(30, 220, 255)); //my attempt at making a 2700K "warm white" color temperature
            break;
        }
        countPrinted = count;
      }
    }
  }
  
  //turns on the lights
  FastLED.show();
}
