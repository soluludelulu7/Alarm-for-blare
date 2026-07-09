#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h> // library thingies
#include <SPI.h>
#define TFT_CS    7 
#define TFT_DC    8
#define TFT_MOSI  20 // Pin assignments
#define TFT_SCLK  21
#define TFT_RST   10
Adafruit_ST7789 display = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST); // screen object thingy

int hours = 12; // set it up at exactly midnight for it to work
int minutes = 0;

void setup() {
  Serial.begin(115200); 
  display.init(76, 284);  
  display.fillScreen(ST77XX_BLACK); // oi screen wake up matey boi
}

void loop() {
  minutes++;
  if (minutes > 59) {
    minutes = 0; // update the timey
    hourse = (hours % 12) + 1;
  }  
}
  display.fillScreen(ST77XX_RED); // wanted red font so it looks cool
  display.setCursor(38, 142); // not sure might be the middle
  display.setTextSize(5); // text might be a little large can adjust later
  display.printf(hours, minutes); // show the time on the screen
  delay(60000)
}