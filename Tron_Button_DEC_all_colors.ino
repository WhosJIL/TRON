// This is a demonstration on how to use an input device to trigger changes on your neo pixels.
// You should wire a momentary push button to connect from ground to a digital IO pin.  When you
// press the button it will change to a new pixel animation.  Note that you need to press the
// button once to start the first animation!

#include <Adafruit_NeoPixel.h>

#define BUTTON_PIN   3    // Digital IO pin connected to the button.  This will be
                          // driven with a pull-up resistor so the switch should
                          // pull the pin to ground momentarily.  On a high -> low
                          // transition the button press logic will execute.

#define PIXEL_PIN    5    // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 144
void Ring(uint32_t c); //pre-load code
void tronBlade(uint32_t c,uint8_t wait); //pre-load code
void rinzlerBlade(uint32_t c,uint8_t wait); //pre-load code
void cluBlade(uint32_t c,uint8_t wait); //pre-load code

// Parameter 1 = number of pixels in strip,  neopixel stick has 8
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

bool oldState = HIGH;
int showType = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
int pos = 0, dir = 1;
void loop() {
  // Get current button state.
  bool newState = digitalRead(BUTTON_PIN);

  // Check if state changed from high to low (button press).
  if (newState == LOW && oldState == HIGH) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState = digitalRead(BUTTON_PIN);
    if (newState == LOW) {
      showType++;
      if (showType > 9)
        showType=0;
      startShow(showType);
    }
  }

  // Set the last button state to the old state.
  oldState = newState;
}

void startShow(int i) {
  switch(i){
    case 0: colorWipe(strip.Color(0, 0, 0), 2);// Black/off
            break;
    case 1: Ring(strip.Color(0, 255, 255));
    delay(2000);
    tronBlade(strip.Color(0, 255, 255),500);    // tron blue
            break;
    case 2: colorWipe(strip.Color(0, 0, 0), 8);  // Black
            break;
    case 3: Ring(strip.Color(255, 51, 0));
    delay(2000);
    rinzlerBlade(strip.Color(255, 51, 0),500);// Rinzler 
            break;
    case 4: colorWipe(strip.Color(0, 0, 0), 8);  // Black
            break;
    case 5: Ring(strip.Color(255, 239, 18));
    delay(2000);
    cluBlade(strip.Color(255, 239, 18),500); // CLU
            break;
    case 6: colorWipe(strip.Color(0, 0, 0), 8);  // Black
            break;
    case 7: colorWipe(strip.Color(0, 0, 0), 2);
            break;
    case 8: colorWipe(strip.Color(0, 0, 0), 2);
            break;
    case 9: colorWipe(strip.Color(0, 0, 0), 2);
            break;
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void Ring(uint32_t c){
            strip.setPixelColor(0, c);
            strip.show();
            strip.setPixelColor(1, c);
            strip.show();
            strip.setPixelColor(2, c);
            strip.show();
            delay (200);
            strip.setPixelColor(3, c);
            strip.show();
            strip.setPixelColor(4, c);
            strip.show();
            strip.setPixelColor(5, c);
            strip.show();
            delay (200);
            strip.setPixelColor(6, c);
            strip.show();
            strip.setPixelColor(7, c);
            strip.show();
            strip.setPixelColor(8, c);
            strip.show();
            delay (200);
            strip.setPixelColor(9, c);
            strip.show();
            strip.setPixelColor(10, c);
            strip.show();
            strip.setPixelColor(11, c);
            strip.show();
            delay (200);
            strip.setPixelColor(12, c);
            strip.show();
            strip.setPixelColor(13, c);
            strip.show();
            strip.setPixelColor(14, c);
            strip.show();
            delay (200);
            strip.setPixelColor(15, c);
            strip.show();
            strip.setPixelColor(16, c);
            strip.show();
            strip.setPixelColor(17, c);
            strip.show();
            delay (200);
            strip.setPixelColor(18, c);
            strip.show();
            strip.setPixelColor(19, c);
            strip.show();
            strip.setPixelColor(20, c);
            strip.show();
            delay (200);
            strip.setPixelColor(21, c);
            strip.show();
            strip.setPixelColor(22, c);
            strip.show();
            strip.setPixelColor(23, c);
            strip.show();
            delay (200);
            strip.setPixelColor(24, c);
            strip.show();
            strip.setPixelColor(25, c);
            strip.show();
            strip.setPixelColor(26, c);
            strip.show();
            delay (200);
            strip.setPixelColor(27, c);
            strip.show();
            strip.setPixelColor(28, c);
            strip.show();
            strip.setPixelColor(29, c);
            strip.show();
            delay (200);
            strip.setPixelColor(30, c);
            strip.show();
            strip.setPixelColor(31, c);
            strip.show();
            strip.setPixelColor(32, c);
            strip.show();
            delay (200);
            strip.setPixelColor(33, c);
            strip.show();
            strip.setPixelColor(34, c);
            strip.show();
            strip.setPixelColor(35, c);
            strip.show();
            delay (200);
            strip.setPixelColor(36, c);
            strip.show();
            strip.setPixelColor(37, c);
            strip.show();
            strip.setPixelColor(38, c);
            strip.show();
            delay (200);
            strip.setPixelColor(39, c);
            strip.show();
            strip.setPixelColor(40, c);
            strip.show();
            strip.setPixelColor(41, c);
            strip.show();
            delay (200);
            strip.setPixelColor(42, c);
            strip.show();
            strip.setPixelColor(43, c);
            strip.show();
            strip.setPixelColor(44, c);
            strip.show();
            delay (200);
            strip.setPixelColor(45, c);
            strip.show();
            strip.setPixelColor(46, c);
            strip.show();
            strip.setPixelColor(47, c);
            strip.show();
            delay (1000);
}



void tronBlade(uint32_t c,uint8_t wait){
  int j;
            strip.setPixelColor(0, c);
            strip.setPixelColor(1, c);
            strip.setPixelColor(2, c);
            strip.setPixelColor(3, c);
            strip.setPixelColor(4, c);
            strip.setPixelColor(5, c);
            strip.setPixelColor(6, c);
            strip.setPixelColor(7, c);
            strip.setPixelColor(8, c);
            strip.setPixelColor(9, c);
            strip.setPixelColor(10, c);
            strip.setPixelColor(11, c);
            strip.setPixelColor(12, c);
            strip.setPixelColor(13, c);
            strip.setPixelColor(14, c);
            strip.setPixelColor(15, c);
            strip.setPixelColor(16, c);
            strip.setPixelColor(17, c);
            strip.setPixelColor(18, c);
            strip.setPixelColor(19, c);
            strip.setPixelColor(20, c);
            strip.setPixelColor(21, c);
            strip.setPixelColor(22, c);
            strip.setPixelColor(23, c);
            strip.setPixelColor(24, c);
            strip.setPixelColor(25, c);
            strip.setPixelColor(26, c);
            strip.setPixelColor(27, c);
            strip.setPixelColor(28, c);
            strip.setPixelColor(29, c);
            strip.setPixelColor(30, c);
            strip.setPixelColor(31, c);
            strip.setPixelColor(32, c);
            strip.setPixelColor(33, c);
            strip.setPixelColor(34, c);
            strip.setPixelColor(35, c);
            strip.setPixelColor(36, c);
            strip.setPixelColor(37, c);
            strip.setPixelColor(38, c);
            strip.setPixelColor(39, c);
            strip.setPixelColor(40, c);
            strip.setPixelColor(41, c);
            strip.setPixelColor(42, c);
            strip.setPixelColor(43, c);
            strip.setPixelColor(44, c);
            strip.setPixelColor(45, c);
            strip.setPixelColor(46, c);
            strip.setPixelColor(47, c);
for(int x = 0; x < 1000; x++) {//run this code 1000 times
strip.setPixelColor(pos + 48, 0x66ffff);
strip.setPixelColor(pos + 49, 0x4dffff);
strip.setPixelColor(pos + 50, 0x33ffff);
strip.setPixelColor(pos + 51, 0x1affff);
strip.setPixelColor(pos + 52, 0x00ffff);
strip.setPixelColor(pos + 53, 0x00e6e6);
strip.setPixelColor(pos + 54, 0x00cccc);
strip.setPixelColor(pos + 55, 0x00b3b3);
strip.setPixelColor(pos + 56, 0x66ffff);
strip.setPixelColor(pos + 57, 0x4dffff);
strip.setPixelColor(pos + 58, 0x33ffff);
strip.setPixelColor(pos + 59, 0x1affff);
strip.setPixelColor(pos + 60, 0x00ffff);
strip.setPixelColor(pos + 61, 0x00e6e6);
strip.setPixelColor(pos + 62, 0x00cccc);
strip.setPixelColor(pos + 63, 0x00b3b3);
strip.setPixelColor(pos + 64, 0x66ffff);
strip.setPixelColor(pos + 65, 0x4dffff);
strip.setPixelColor(pos + 66, 0x33ffff);
strip.setPixelColor(pos + 67, 0x1affff);
strip.setPixelColor(pos + 68, 0x00ffff);
strip.setPixelColor(pos + 69, 0x00e6e6);
strip.setPixelColor(pos + 70, 0x00cccc);
strip.setPixelColor(pos + 71, 0x00b3b3);
strip.setPixelColor(pos + 72, 0x66ffff);
strip.setPixelColor(pos + 73, 0x4dffff);
strip.setPixelColor(pos + 74, 0x33ffff);
strip.setPixelColor(pos + 75, 0x1affff);
strip.setPixelColor(pos + 76, 0x00ffff);
strip.setPixelColor(pos + 77, 0x00e6e6);
strip.setPixelColor(pos + 78, 0x00cccc);
strip.setPixelColor(pos + 79, 0x00b3b3);
strip.setPixelColor(pos + 80, 0x66ffff);
strip.setPixelColor(pos + 81, 0x4dffff);
strip.setPixelColor(pos + 82, 0x33ffff);
strip.setPixelColor(pos + 83, 0x1affff);
strip.setPixelColor(pos + 84, 0x00ffff);
strip.setPixelColor(pos + 85, 0x00e6e6);
strip.setPixelColor(pos + 86, 0x00cccc);
strip.setPixelColor(pos + 87, 0x00b3b3);
strip.setPixelColor(pos + 88, 0x66ffff);
strip.setPixelColor(pos + 89, 0x4dffff);
strip.setPixelColor(pos + 90, 0x33ffff);
strip.setPixelColor(pos + 91, 0x1affff);
strip.setPixelColor(pos + 92, 0x00ffff);
strip.setPixelColor(pos + 93, 0x00e6e6);
strip.setPixelColor(pos + 94, 0x00cccc);
strip.setPixelColor(pos + 95, 0x00b3b3);
strip.setPixelColor(pos + 96, 0x66ffff);
strip.setPixelColor(pos + 97, 0x4dffff);
strip.setPixelColor(pos + 98, 0x33ffff);
strip.setPixelColor(pos + 99, 0x1affff);
strip.setPixelColor(pos + 100, 0x00ffff);
strip.setPixelColor(pos + 101, 0x00e6e6);
strip.setPixelColor(pos + 102, 0x00cccc);
strip.setPixelColor(pos + 103, 0x00b3b3);
strip.setPixelColor(pos + 104, 0x66ffff);
strip.setPixelColor(pos + 105, 0x4dffff);
strip.setPixelColor(pos + 106, 0x33ffff);
strip.setPixelColor(pos + 107, 0x1affff);
strip.setPixelColor(pos + 108, 0x00ffff);
strip.setPixelColor(pos + 109, 0x00e6e6);
strip.setPixelColor(pos + 110, 0x00cccc);
strip.setPixelColor(pos + 111, 0x00b3b3);
strip.setPixelColor(pos + 112, 0x66ffff);
strip.setPixelColor(pos + 113, 0x4dffff);
strip.setPixelColor(pos + 114, 0x33ffff);
strip.setPixelColor(pos + 115, 0x1affff);
strip.setPixelColor(pos + 116, 0x00ffff);
strip.setPixelColor(pos + 117, 0x00e6e6);
strip.setPixelColor(pos + 118, 0x00cccc);
strip.setPixelColor(pos + 119, 0x00b3b3);
strip.setPixelColor(pos + 120, 0x66ffff);
strip.setPixelColor(pos + 121, 0x4dffff);
strip.setPixelColor(pos + 122, 0x33ffff);
strip.setPixelColor(pos + 123, 0x1affff);
strip.setPixelColor(pos + 124, 0x00ffff);
strip.setPixelColor(pos + 125, 0x00e6e6);
strip.setPixelColor(pos + 126, 0x00cccc);
strip.setPixelColor(pos + 127, 0x00b3b3);
strip.setPixelColor(pos + 128, 0x66ffff);
strip.setPixelColor(pos + 129, 0x4dffff);
strip.setPixelColor(pos + 130, 0x33ffff);
strip.setPixelColor(pos + 131, 0x1affff);
strip.setPixelColor(pos + 132, 0x00ffff);
strip.setPixelColor(pos + 133, 0x00e6e6);
strip.setPixelColor(pos + 134, 0x00cccc);
strip.setPixelColor(pos + 135, 0x00b3b3);
strip.setPixelColor(pos + 136, 0x66ffff);
strip.setPixelColor(pos + 137, 0x4dffff);
strip.setPixelColor(pos + 138, 0x33ffff);
strip.setPixelColor(pos + 139, 0x1affff);
strip.setPixelColor(pos + 140, 0x00ffff);
strip.setPixelColor(pos + 141, 0x00e6e6);
strip.setPixelColor(pos + 142, 0x00cccc);
strip.setPixelColor(pos + 143, 0x00b3b3);
  



  
  strip.show();
  delay(10);
 
  // Rather than being sneaky and erasing just the tail pixel,
  // it's easier to erase it all and draw a new one next time.
  for(j=48; j<= 54; j++) strip.setPixelColor(pos+j, 1);
 
  // Bounce off ends of strip
  pos += dir;
  if(pos < 0) {
    pos = 0;
    dir = -dir;
  } else if(pos >= 8) {
    pos = 0;
    dir = -dir;
  }


}}
void rinzlerBlade(uint32_t c,uint8_t wait){
  int j;
            strip.setPixelColor(0, c);
            strip.setPixelColor(1, c);
            strip.setPixelColor(2, c);
            strip.setPixelColor(3, c);
            strip.setPixelColor(4, c);
            strip.setPixelColor(5, c);
            strip.setPixelColor(6, c);
            strip.setPixelColor(7, c);
            strip.setPixelColor(8, c);
            strip.setPixelColor(9, c);
            strip.setPixelColor(10, c);
            strip.setPixelColor(11, c);
            strip.setPixelColor(12, c);
            strip.setPixelColor(13, c);
            strip.setPixelColor(14, c);
            strip.setPixelColor(15, c);
            strip.setPixelColor(16, c);
            strip.setPixelColor(17, c);
            strip.setPixelColor(18, c);
            strip.setPixelColor(19, c);
            strip.setPixelColor(20, c);
            strip.setPixelColor(21, c);
            strip.setPixelColor(22, c);
            strip.setPixelColor(23, c);
            strip.setPixelColor(24, c);
            strip.setPixelColor(25, c);
            strip.setPixelColor(26, c);
            strip.setPixelColor(27, c);
            strip.setPixelColor(28, c);
            strip.setPixelColor(29, c);
            strip.setPixelColor(30, c);
            strip.setPixelColor(31, c);
            strip.setPixelColor(32, c);
            strip.setPixelColor(33, c);
            strip.setPixelColor(34, c);
            strip.setPixelColor(35, c);
            strip.setPixelColor(36, c);
            strip.setPixelColor(37, c);
            strip.setPixelColor(38, c);
            strip.setPixelColor(39, c);
            strip.setPixelColor(40, c);
            strip.setPixelColor(41, c);
            strip.setPixelColor(42, c);
            strip.setPixelColor(43, c);
            strip.setPixelColor(44, c);
            strip.setPixelColor(45, c);
            strip.setPixelColor(46, c);
            strip.setPixelColor(47, c);
 for(int x = 0; x < 1000; x++) {//run this code 1000 times
strip.setPixelColor(pos + 48, 0xffffff);
strip.setPixelColor(pos + 49, 0xbfbfbf);
strip.setPixelColor(pos + 50, 0x8c8c8c);
strip.setPixelColor(pos + 51, 0x737373);
strip.setPixelColor(pos + 52, 0x595959);
strip.setPixelColor(pos + 53, 0x404040);
strip.setPixelColor(pos + 54, 0x262626);
strip.setPixelColor(pos + 55, 0x0d0d0d);
strip.setPixelColor(pos + 56, 0xffffff);
strip.setPixelColor(pos + 57, 0xbfbfbf);
strip.setPixelColor(pos + 58, 0x8c8c8c);
strip.setPixelColor(pos + 59, 0x737373);
strip.setPixelColor(pos + 60, 0x595959);
strip.setPixelColor(pos + 61, 0x404040);
strip.setPixelColor(pos + 62, 0x262626);
strip.setPixelColor(pos + 63, 0x0d0d0d);
strip.setPixelColor(pos + 64, 0xffffff);
strip.setPixelColor(pos + 65, 0xbfbfbf);
strip.setPixelColor(pos + 66, 0x8c8c8c);
strip.setPixelColor(pos + 67, 0x737373);
strip.setPixelColor(pos + 68, 0x595959);
strip.setPixelColor(pos + 69, 0x404040);
strip.setPixelColor(pos + 70, 0x262626);
strip.setPixelColor(pos + 71, 0x0d0d0d);
strip.setPixelColor(pos + 72, 0xffffff);
strip.setPixelColor(pos + 73, 0xbfbfbf);
strip.setPixelColor(pos + 74, 0x8c8c8c);
strip.setPixelColor(pos + 75, 0x737373);
strip.setPixelColor(pos + 76, 0x595959);
strip.setPixelColor(pos + 77, 0x404040);
strip.setPixelColor(pos + 78, 0x262626);
strip.setPixelColor(pos + 79, 0x0d0d0d);
strip.setPixelColor(pos + 80, 0xffffff);
strip.setPixelColor(pos + 81, 0xbfbfbf);
strip.setPixelColor(pos + 82, 0x8c8c8c);
strip.setPixelColor(pos + 83, 0x737373);
strip.setPixelColor(pos + 84, 0x595959);
strip.setPixelColor(pos + 85, 0x404040);
strip.setPixelColor(pos + 86, 0x262626);
strip.setPixelColor(pos + 87, 0x0d0d0d);
strip.setPixelColor(pos + 88, 0xffffff);
strip.setPixelColor(pos + 89, 0xbfbfbf);
strip.setPixelColor(pos + 90, 0x8c8c8c);
strip.setPixelColor(pos + 91, 0x737373);
strip.setPixelColor(pos + 92, 0x595959);
strip.setPixelColor(pos + 93, 0x404040);
strip.setPixelColor(pos + 94, 0x262626);
strip.setPixelColor(pos + 95, 0x0d0d0d);
strip.setPixelColor(pos + 96, 0xffffff);
strip.setPixelColor(pos + 97, 0xbfbfbf);
strip.setPixelColor(pos + 98, 0x8c8c8c);
strip.setPixelColor(pos + 99, 0x737373);
strip.setPixelColor(pos + 100, 0x595959);
strip.setPixelColor(pos + 101, 0x404040);
strip.setPixelColor(pos + 102, 0x262626);
strip.setPixelColor(pos + 103, 0x0d0d0d);
strip.setPixelColor(pos + 104, 0xffffff);
strip.setPixelColor(pos + 105, 0xbfbfbf);
strip.setPixelColor(pos + 106, 0x8c8c8c);
strip.setPixelColor(pos + 107, 0x737373);
strip.setPixelColor(pos + 108, 0x595959);
strip.setPixelColor(pos + 109, 0x404040);
strip.setPixelColor(pos + 110, 0x262626);
strip.setPixelColor(pos + 111, 0x0d0d0d);
strip.setPixelColor(pos + 112, 0xffffff);
strip.setPixelColor(pos + 113, 0xbfbfbf);
strip.setPixelColor(pos + 114, 0x8c8c8c);
strip.setPixelColor(pos + 115, 0x737373);
strip.setPixelColor(pos + 116, 0x595959);
strip.setPixelColor(pos + 117, 0x404040);
strip.setPixelColor(pos + 118, 0x262626);
strip.setPixelColor(pos + 119, 0x0d0d0d);
strip.setPixelColor(pos + 120, 0xffffff);
strip.setPixelColor(pos + 121, 0xbfbfbf);
strip.setPixelColor(pos + 122, 0x8c8c8c);
strip.setPixelColor(pos + 123, 0x737373);
strip.setPixelColor(pos + 124, 0x595959);
strip.setPixelColor(pos + 125, 0x404040);
strip.setPixelColor(pos + 126, 0x262626);
strip.setPixelColor(pos + 127, 0x0d0d0d);
strip.setPixelColor(pos + 128, 0xffffff);
strip.setPixelColor(pos + 129, 0xbfbfbf);
strip.setPixelColor(pos + 130, 0x8c8c8c);
strip.setPixelColor(pos + 131, 0x737373);
strip.setPixelColor(pos + 132, 0x595959);
strip.setPixelColor(pos + 133, 0x404040);
strip.setPixelColor(pos + 134, 0x262626);
strip.setPixelColor(pos + 135, 0x0d0d0d);
strip.setPixelColor(pos + 136, 0xffffff);
strip.setPixelColor(pos + 137, 0xbfbfbf);
strip.setPixelColor(pos + 138, 0x8c8c8c);
strip.setPixelColor(pos + 139, 0x737373);
strip.setPixelColor(pos + 140, 0x595959);
strip.setPixelColor(pos + 141, 0x404040);
strip.setPixelColor(pos + 142, 0x262626);
strip.setPixelColor(pos + 143, 0x0d0d0d);
  strip.show();
  delay(7);
 
  // Rather than being sneaky and erasing just the tail pixel,
  // it's easier to erase it all and draw a new one next time.
  for(j=48; j<= 54; j++) strip.setPixelColor(pos+j, 1);
 
  // Bounce off ends of strip
  pos += dir;
  if(pos < 0) {
    pos = 0;
    dir = -dir;
  } else if(pos >= 8) {
    pos = 0;
    dir = -dir;
  }}}
void cluBlade(uint32_t c,uint8_t wait){
  int j;
            strip.setPixelColor(0, c);
            strip.setPixelColor(1, c);
            strip.setPixelColor(2, c);
            strip.setPixelColor(3, c);
            strip.setPixelColor(4, c);
            strip.setPixelColor(5, c);
            strip.setPixelColor(6, c);
            strip.setPixelColor(7, c);
            strip.setPixelColor(8, c);
            strip.setPixelColor(9, c);
            strip.setPixelColor(10, c);
            strip.setPixelColor(11, c);
            strip.setPixelColor(12, c);
            strip.setPixelColor(13, c);
            strip.setPixelColor(14, c);
            strip.setPixelColor(15, c);
            strip.setPixelColor(16, c);
            strip.setPixelColor(17, c);
            strip.setPixelColor(18, c);
            strip.setPixelColor(19, c);
            strip.setPixelColor(20, c);
            strip.setPixelColor(21, c);
            strip.setPixelColor(22, c);
            strip.setPixelColor(23, c);
            strip.setPixelColor(24, c);
            strip.setPixelColor(25, c);
            strip.setPixelColor(26, c);
            strip.setPixelColor(27, c);
            strip.setPixelColor(28, c);
            strip.setPixelColor(29, c);
            strip.setPixelColor(30, c);
            strip.setPixelColor(31, c);
            strip.setPixelColor(32, c);
            strip.setPixelColor(33, c);
            strip.setPixelColor(34, c);
            strip.setPixelColor(35, c);
            strip.setPixelColor(36, c);
            strip.setPixelColor(37, c);
            strip.setPixelColor(38, c);
            strip.setPixelColor(39, c);
            strip.setPixelColor(40, c);
            strip.setPixelColor(41, c);
            strip.setPixelColor(42, c);
            strip.setPixelColor(43, c);
            strip.setPixelColor(44, c);
            strip.setPixelColor(45, c);
            strip.setPixelColor(46, c);
            strip.setPixelColor(47, c);
 for(int x = 0; x < 1000; x++) {//run this code 1000 times
strip.setPixelColor(pos + 48, 0xfff133);
strip.setPixelColor(pos + 49, 0xffef12);
strip.setPixelColor(pos + 50, 0xccbe00);
strip.setPixelColor(pos + 51, 0x998f00);
strip.setPixelColor(pos + 52, 0x665f00);
strip.setPixelColor(pos + 53, 0x4d4700);
strip.setPixelColor(pos + 54, 0x333000);
strip.setPixelColor(pos + 55, 0x1a1800);
strip.setPixelColor(pos + 56, 0xfff133);
strip.setPixelColor(pos + 57, 0xffef12);
strip.setPixelColor(pos + 58, 0xccbe00);
strip.setPixelColor(pos + 59, 0x998f00);
strip.setPixelColor(pos + 60, 0x665f00);
strip.setPixelColor(pos + 61, 0x4d4700);
strip.setPixelColor(pos + 62, 0x333000);
strip.setPixelColor(pos + 63, 0x1a1800);
strip.setPixelColor(pos + 64, 0xfff133);
strip.setPixelColor(pos + 65, 0xffef12);
strip.setPixelColor(pos + 66, 0xccbe00);
strip.setPixelColor(pos + 67, 0x998f00);
strip.setPixelColor(pos + 68, 0x665f00);
strip.setPixelColor(pos + 69, 0x4d4700);
strip.setPixelColor(pos + 70, 0x333000);
strip.setPixelColor(pos + 71, 0x1a1800);
strip.setPixelColor(pos + 72, 0xfff133);
strip.setPixelColor(pos + 73, 0xffef12);
strip.setPixelColor(pos + 74, 0xccbe00);
strip.setPixelColor(pos + 75, 0x998f00);
strip.setPixelColor(pos + 76, 0x665f00);
strip.setPixelColor(pos + 77, 0x4d4700);
strip.setPixelColor(pos + 78, 0x333000);
strip.setPixelColor(pos + 79, 0x1a1800);
strip.setPixelColor(pos + 80, 0xfff133);
strip.setPixelColor(pos + 81, 0xffef12);
strip.setPixelColor(pos + 82, 0xccbe00);
strip.setPixelColor(pos + 83, 0x998f00);
strip.setPixelColor(pos + 84, 0x665f00);
strip.setPixelColor(pos + 85, 0x4d4700);
strip.setPixelColor(pos + 86, 0x333000);
strip.setPixelColor(pos + 87, 0x1a1800);
strip.setPixelColor(pos + 88, 0xfff133);
strip.setPixelColor(pos + 89, 0xffef12);
strip.setPixelColor(pos + 90, 0xccbe00);
strip.setPixelColor(pos + 91, 0x998f00);
strip.setPixelColor(pos + 92, 0x665f00);
strip.setPixelColor(pos + 93, 0x4d4700);
strip.setPixelColor(pos + 94, 0x333000);
strip.setPixelColor(pos + 95, 0x1a1800);
strip.setPixelColor(pos + 96, 0xfff133);
strip.setPixelColor(pos + 97, 0xffef12);
strip.setPixelColor(pos + 98, 0xccbe00);
strip.setPixelColor(pos + 99, 0x998f00);
strip.setPixelColor(pos + 100, 0x665f00);
strip.setPixelColor(pos + 101, 0x4d4700);
strip.setPixelColor(pos + 102, 0x333000);
strip.setPixelColor(pos + 103, 0x1a1800);
strip.setPixelColor(pos + 104, 0xfff133);
strip.setPixelColor(pos + 105, 0xffef12);
strip.setPixelColor(pos + 106, 0xccbe00);
strip.setPixelColor(pos + 107, 0x998f00);
strip.setPixelColor(pos + 108, 0x665f00);
strip.setPixelColor(pos + 109, 0x4d4700);
strip.setPixelColor(pos + 110, 0x333000);
strip.setPixelColor(pos + 111, 0x1a1800);
strip.setPixelColor(pos + 112, 0xfff133);
strip.setPixelColor(pos + 113, 0xffef12);
strip.setPixelColor(pos + 114, 0xccbe00);
strip.setPixelColor(pos + 115, 0x998f00);
strip.setPixelColor(pos + 116, 0x665f00);
strip.setPixelColor(pos + 117, 0x4d4700);
strip.setPixelColor(pos + 118, 0x333000);
strip.setPixelColor(pos + 119, 0x1a1800);
strip.setPixelColor(pos + 120, 0xfff133);
strip.setPixelColor(pos + 121, 0xffef12);
strip.setPixelColor(pos + 122, 0xccbe00);
strip.setPixelColor(pos + 123, 0x998f00);
strip.setPixelColor(pos + 124, 0x665f00);
strip.setPixelColor(pos + 125, 0x4d4700);
strip.setPixelColor(pos + 126, 0x333000);
strip.setPixelColor(pos + 127, 0x1a1800);
strip.setPixelColor(pos + 128, 0xfff133);
strip.setPixelColor(pos + 129, 0xffef12);
strip.setPixelColor(pos + 130, 0xccbe00);
strip.setPixelColor(pos + 131, 0x998f00);
strip.setPixelColor(pos + 132, 0x665f00);
strip.setPixelColor(pos + 133, 0x4d4700);
strip.setPixelColor(pos + 134, 0x333000);
strip.setPixelColor(pos + 135, 0x1a1800);
strip.setPixelColor(pos + 136, 0xfff133);
strip.setPixelColor(pos + 137, 0xffef12);
strip.setPixelColor(pos + 138, 0xccbe00);
strip.setPixelColor(pos + 139, 0x998f00);
strip.setPixelColor(pos + 140, 0x665f00);
strip.setPixelColor(pos + 141, 0x4d4700);
strip.setPixelColor(pos + 142, 0x333000);
strip.setPixelColor(pos + 143, 0x1a1800);
  strip.show();
  delay(7);
 
  // Rather than being sneaky and erasing just the tail pixel,
  // it's easier to erase it all and draw a new one next time.
  for(j=48; j<= 54; j++) strip.setPixelColor(pos+j, 1);
 
  // Bounce off ends of strip
  pos += dir;
  if(pos < 0) {
    pos = 0;
    dir = -dir;
  } else if(pos >= 8) {
    pos = 0;
    dir = -dir;
  }}}
