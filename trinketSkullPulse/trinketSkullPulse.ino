#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

int waitTime = 20;

void setup() {
  // for trinket 5V
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // end Trinket code

  strip.begin();
  strip.setBrightness(200);
  strip.show(); // initiates all pixels to 'off'  
}

void loop() {
  fadeInAndOut(203, 100, 254, waitTime); // darkorchid
  fadeInAndOut(50, 255, 50, waitTime); // LimeGreen
  fadeInAndOut(255, 0, 255, waitTime); // darkMagenta

}
// Fade a pixel in and out
void fadeInAndOut(uint8_t red, uint8_t green, uint8_t blue, uint8_t wait) {
  for(uint8_t b=0; b <255; b++) {
    for(uint8_t i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, red*b/255, green*b/255, blue*b/255);
    }
    strip.show();
    delay(wait);
  };
  for(uint8_t b=255; b > 0; b--) {
    for(uint8_t i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, red*b/255, green*b/255, blue*b/255);
    }
    strip.show();
    delay(wait);
  };
};



