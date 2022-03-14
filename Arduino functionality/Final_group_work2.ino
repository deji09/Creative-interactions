#include <LiquidCrystal.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#include <LiquidCrystal.h>
#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.
//Pin for the button
const int pot = 1; // select pin for potentiometer
int value = 0; //value used for delays
int newvalue = 0;
const int buttonPin = 10;  //Digital
const int gameButtonPin = 9;
//Pins for the joystick
const int xjoy = 2; //Analog
const int yjoy = 4;
const int yPin = 1; //Analog
int xjoyvalue = 0;
int yjoyvalue = 0;
//Pin for the potentiomer
//const int potentiomerPin = 1;

//Variable for reading the potentiomer
//int potentiomerValue = analogRead(potentiomerPin);
//int newPotentiomerValue;

//Variable for keeping track of the score
int score = 0;
int newScore = 0;
const int timeDelay = 5000;

// variable for reading the pushbutton status
int buttonState = 0;
int gameButtonState = 0;

//time left before the player fails the game
int timeLeft = 5;

//variable for when the game finishes
boolean gameOver = false;

//time left before the game restarts
int restartTime = 10;

//Restart function
void(* resetFunc) (void) = 0;

//Random number generator
int randomNumber;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  //Digital
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
  Serial.begin(9600);
  Serial.println("hi");
  strip.begin();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'
  // put your setup code here, to run once:

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(gameButtonPin, INPUT);
  analogRead(1);
  // initialize the joystick button pin as an input: (COULD NOT NEED TO BE USED)
  //set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Welcome to bopit");
  lcd.print("Press the button ");
  //With each new game the score will be set to zero
  //A new random number will generate each time
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  StartLight();
  while (gameOver == false)
  {
    randomNumberGenerator();
    option();
  }

}

void option() {


  //Displays the score
  lcd.setCursor(0, 0);

  lcd.setCursor(0, 1);
  if (randomNumber == 0)
  {
    lcd.begin(16, 2);
    lcd.print(" Action ");
    lcd.print(randomNumber + 1 );
    upCounter();
    delay(1000);
    Button();
    delay(2000);
    lcd.begin(16, 2);
    lcd.print(" The score is  ");
    lcd.setCursor(0, 1);
    lcd.print(newScore);
    lcd.setCursor(0, 0);
    delay(2000);
  }

  else if (randomNumber == 1)
  {
    lcd.begin(16, 2);
    lcd.print(" Action ");
    lcd.print(randomNumber + 1 );
    strip.setPixelColor(4, 0, 0, 255); // Green
    colorWipe(strip.Color(0, 0, 0, 255), 90); // White RGBW
    rightCounter();
    Serial.println(" Joystick vertical score ");
    joystickUpOrDown();
    delay(1000);
    lcd.begin(16, 2);
    lcd.print(" The score is  ");
    lcd.setCursor(0, 1);
    lcd.print(newScore);
    lcd.setCursor(0, 0);
    delay(1000);
  }

  else if (randomNumber == 2)
  {
    lcd.begin(16, 2);
    lcd.print(" Action ");
    lcd.print(randomNumber + 1 );
    strip.setPixelColor(7, 0, 0, 255); // Green
    colorWipe(strip.Color(0, 0, 0, 255), 90); // White RGBW
    downCounter();
    delay(1000);
    potentiometer();
    delay(1000);
    lcd.begin(16, 2);
    lcd.print(" The score is  ");
    lcd.setCursor(0, 1);
    lcd.print(newScore);
    lcd.setCursor(0, 0);
    delay(1000);
  }

  else if (randomNumber == 3)
  {
    lcd.begin(16, 2);
    lcd.print(" Action  ");
    lcd.print(randomNumber + 1);
    strip.setPixelColor(10, 0, 0, 255); // Green
    colorWipe(strip.Color(0, 0, 0, 255), 90); // White RGBW
    leftCounter();
    delay(1000);
    joystickLeftOrRight();
    delay(1000);
    lcd.begin(16, 2);
    lcd.print(" The score is  ");
    lcd.setCursor(0, 1);
    lcd.print(newScore);
    lcd.setCursor(0, 0);
    delay(1000);
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, c);  //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, Wheel( (i + j) % 255)); //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}



void randomNumberGenerator()
{
  //generates a number between 0 and 3
  randomNumber = random(0, 4);
}

void StartLight()
{
  lcd.begin(16, 2);
  lcd.print("Welcome to bopit ");
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    while (buttonState == HIGH) {
      buttonState = digitalRead(buttonPin);
      rainbow(0);
    }
  }
  else {
    colorWipe(strip.Color(255, 0, 0), 0); // Red
    colorWipe(strip.Color(0, 0, 0, 255), 1); // White RGBW
    randomNumberGenerator();
  }
}



void upCounter() {
  int upCount = 0;
  while (upCount <= 3) {
    gameButtonState = digitalRead(gameButtonPin);
    strip.setPixelColor(1, 0, 0, 255); // Green
    colorWipe(strip.Color(0, 0, 0, 255), 90); // White RGBW
    upCount++;
  }
}

void downCounter() {
  int downCount = 0;
  while (downCount <= 3) {
    strip.setPixelColor(7, 0, 0, 255); // Green
    colorWipe(strip.Color(0, 0, 0, 255), 90); // White RGBW
    downCount++;
  }
}

void leftCounter() {
  int leftCount = 0;
  while (leftCount <= 2) {
    strip.setPixelColor(10, 0, 0, 255); // Green
    colorWipe(strip.Color(0, 0, 0, 255), 90); // White RGBW
    leftCount++;
  }
}

void rightCounter() {
  int rightCount = 0;
  while (rightCount <= 2) {
    strip.setPixelColor(4, 0, 0, 255); // Green
    colorWipe(strip.Color(0, 0, 0, 255), 90); // White RGBW
    rightCount++;
  }
}

void gameover()
{
  delay(3000);
  lcd.begin(16, 2);
  lcd.print("Gameover ");
  lcd.print("score ");
  lcd.setCursor(0, 1);
  lcd.print( newScore  );
  lcd.setCursor(0, 0);
  delay(3000);
  gameOver = false;
  loop();
}
