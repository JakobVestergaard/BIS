#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN 6
#define PIXEL_COUNT 3
#define DELAYVAL 500

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

const int buttonPin = 12;
int state = 0;

void setup() {
  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.show();  // Initialize all pixels to 'off'
}

void ok (void) {
  for (int i = 0; i < 3; i++){
    for (int i = 0; i < 100; i++){
      colorWipe(strip.Color(  0, i,   0), 0);
      }
    for (int i = 100; i > 0; i--){
      colorWipe(strip.Color(  0, i,   0), 0);
      }     
      colorWipe(strip.Color(  0, 0,   0), 0);
  }
}

void warning(void) {
  for (int i = 0; i < 10; i++){
    for (int i = 0; i < 100; i++){
      colorWipe(strip.Color(  i*2, i,   0), 2);
      }
    for (int i = 100; i > 0; i--){
      colorWipe(strip.Color(  i*2, i,   0), 2);
      }     
      colorWipe(strip.Color(  0, 0,   0), 0);
  }
}

void error(void) {
  for (int i = 0; i < 25; i++){
    for (int i = 0; i < 100; i++){
      colorWipe(strip.Color(  i, 0,   0), 0);
      }
    for (int i = 100; i > 0; i--){
      colorWipe(strip.Color(  i, 0,   0), 0);
      }     
      colorWipe(strip.Color(  0, 0,   0), 0);
  }
}

void busy(void) {
  for(int k = 0; k < 4; k++){
    for(int i = 0; i < PIXEL_COUNT; i++) { // For each pixel in strip...
      for (int j = 0; j < 100; j++){
        strip.setPixelColor(i, j*2, j, 0); //(pixel position, red, green, blue)
        strip.show();
        delay(2);
      }
    }
      for(int i = 0; i < PIXEL_COUNT; i++) { // For each pixel in strip...
      for (int j = 100; j > -1; j--){
        strip.setPixelColor(i, j, j/2, 0); //(pixel position, red, green, blue)
        strip.show();
        delay(2);
      }
    }
  }
  colorWipe(strip.Color(  0, 0,   0), 0);
}

int next_state(void) {
  while (digitalRead(buttonPin) == 0) {
    delay(0);
    // wait here till button is pressed
  }
  state++;
  if (state == 4) { state = 0; }
}

void loop() {
  switch (state) {
    case 0: ok();         next_state();   break;
    case 1: warning();    next_state();   break;
    case 2: error();      next_state();   break;
    case 3: busy();       next_state();   break;
  }
}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
