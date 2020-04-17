
// SUPC->VREG.bit.SEL = 1 // Save power draw
#include "defs.h"
#include "graphics.h"
#include <SPI.h> 
#include <Adafruit_DotStar.h>
#include <Adafruit_LIS3DH.h>
#include <vector>
#include <Chimera_Poi.h>

Adafruit_LIS3DH sensor = Adafruit_LIS3DH(LIS3DH_CS);

Adafruit_DotStar onboard(1, 8, 6, DOTSTAR_BRG);

Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

uint8_t red_int = 0;
uint8_t green_int = 0;
uint8_t blue_int = 0; 

uint32_t tempHue = 0;


uint8_t currentColumn = 0;

LightMode *redMode = new LightMode(Color(255, 0, 128));
LightMode *stripeMode = new LightMode(tempTex, 32);
GravityMode* gravity = new GravityMode(&sensor);
LightMode *currentMode = nullptr;
std::vector<LightMode *> modes = std::vector<LightMode *>();
int modeIndex = 0;


void setup() 
{
  modes.push_back(redMode);
  modes.push_back(stripeMode);
  modes.push_back(gravity);

  Serial.println("Booting up...");
  pinMode(BUTTON_PIN, INPUT_PULLDOWN);
  
  Serial.begin(9600);
  Serial.println("Starting LIS3DH...");
    if (! sensor.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Error: LIS3DH failed init!");
    while (1) {
      Serial.println("Error: LIS3DH failed init!");
      yield();
    }
  }
  Serial.println("LIS3DH connected!");

  sensor.setRange(LIS3DH_RANGE_8_G); // 2, 4, 8 or 16 G!

  onboard.begin();
  onboard.show();

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  currentMode = modes[modeIndex];
}

void loop() {
  sensors_event_t event;
  sensor.getEvent(&event);
  // "event.acceleration.x"
  Serial.println(event.acceleration.x);

  strip.clear();

  char* tempStrip;

  tempStrip = currentMode->GetCurrentStrip();
  for(int currentPixel = 0; currentPixel < NUMPIXELS; currentPixel++) {
    strip.setPixelColor(
        31 - currentPixel,
        (uint8_t)tempStrip[3 * currentPixel + 1],
        (uint8_t)tempStrip[3 * currentPixel],
        (uint8_t)tempStrip[3 * currentPixel + 2]
       ); // green red blue
  }

  if (digitalRead(BUTTON_PIN))
  {

    while(digitalRead(BUTTON_PIN)) {

    }
    Serial.println("Button Down!");
    modeIndex++;
    modeIndex %= modes.size();

    currentMode = modes[modeIndex];
  }
 
  
  strip.setBrightness(8); // * 1-abs(event.acceleration.z));
  strip.show(); // Initialize all pixels to 'off'
//  tempHue += STEPSIZE;
  currentMode->Next();
  // delay(20);
}
