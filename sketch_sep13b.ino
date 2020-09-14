#include <Bounce2.h>

#include <FastLED.h>

//FastLED stuff

#define NUM_LEDS 60
#define DATA_PIN 3
CRGB leds[NUM_LEDS];

uint8_t hue = 0;

//Bounce2 stuff

const int buttonPin = 6;
Bounce pushbutton = Bounce(buttonPin, 10);  // 10 ms debounce

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

byte previousState = HIGH;         // what state was the button last time
unsigned int count = 0;            // how many times has it changed to low
unsigned long countAt = 0;         // when count changed
unsigned int countPrinted = 0;     // last count printed

void loop() {
  EVERY_N_MILLISECONDS(100) {
    hue++;
  }
  if(count % 3 == 0){
    fill_solid(leds, NUM_LEDS, CHSV(hue, 255, 255));
  }
  FastLED.show();
  if (pushbutton.update()) {
    if (pushbutton.fallingEdge()) {
      count = count + 1;
      countAt = millis();
    }
  } else {
    if (count != countPrinted) {
      unsigned long nowMillis = millis();
      if (nowMillis - countAt > 100) {
        if(count % 3 == 1){
          fill_solid(leds, NUM_LEDS, CHSV(255, 130, 255));
        }
        if(count % 3 == 2){
          fill_solid(leds, NUM_LEDS, CHSV(30, 220, 255));
        }
        countPrinted = count;
      }
    }
  }
  FastLED.show();
}
