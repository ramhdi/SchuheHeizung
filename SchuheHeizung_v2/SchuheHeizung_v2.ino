/*
Low-cost Sous vide Cooker
version 1.0
Using libraries:
- Adafruit SSD1306 for OLED display - learn.adafruit.com
- Rotary encoder switch - www.belajarduino.com
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "max6675.h"

#define DEBUG
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int SCK_PIN = 9;
int CS_PIN = 10;
int SO_PIN = 11;
MAX6675 thermocouple(SCK_PIN, CS_PIN, SO_PIN);

int mode;
const int REQ_TEMPERATURE = 0;
const int REQ_DURATION = 1;
const int HEATING = 2;

int HEATER_PIN = 4;
int BLOWER_PIN = 5;

int out_a = 2;
int out_b = 3;
int sw = 12;

volatile int lastEncoded = 0;
volatile long encoderValue = 0;
long lastencoderValue = 0;
int lastMSB = 0;
int lastLSB = 0;

double temp_desired, temp_sensor;
unsigned long time_start, time_now, duration;

int swState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;
unsigned long previousMillisControl = 0;
unsigned long previousMillisReadTemp = 0;


void setup() {
#ifdef DEBUG
  Serial.begin(9600);
#endif
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
#ifdef DEBUG
    Serial.println(F("SSD1306 allocation failed"));
#endif
    for (;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  pinMode(HEATER_PIN, OUTPUT);
  pinMode(BLOWER_PIN, OUTPUT);
  digitalWrite(HEATER_PIN, LOW);
  digitalWrite(BLOWER_PIN, LOW);

  pinMode(out_a, INPUT_PULLUP);
  pinMode(out_b, INPUT_PULLUP);
  pinMode(sw, INPUT_PULLUP);
  attachInterrupt(0, updateEncoder, CHANGE);
  attachInterrupt(1, updateEncoder, CHANGE);

  mode = REQ_TEMPERATURE;
#ifdef DEBUG
  Serial.println(F("====================================="));
  Serial.println(F("===== Low-cost Sous Vide Cooker ====="));
  Serial.println(F("====================================="));
#endif
}


void loop() {
  if (mode == REQ_TEMPERATURE) {
    // requesting temperature to user
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("Suhu (C):");

    temp_desired = 30 + encoderValue;
#ifdef DEBUG
    Serial.print(F("User wants temperature at ")); Serial.println(temp_desired);
#endif
    display.setCursor(0, 31);
    display.print((int)temp_desired);
    swState = digitalRead(sw);
    //Serial.print(swState);
    if (swState == LOW) {
      mode = REQ_DURATION;

      encoderValue = 0;
    }

    //Serial.println(mode);
    display.display();
    delay(250);
  }

  else if (mode == REQ_DURATION) {
    // requesting duration to user
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("Durasi");
    display.setCursor(0, 20);
    display.print("(menit):");

    unsigned long duration_mins = 10 + encoderValue;
    display.setCursor(0, 40);
    display.print(duration_mins);
#ifdef DEBUG
    Serial.print(F("User wants duration at ")); Serial.println(duration_mins);
#endif
    swState = digitalRead(sw);
    //Serial.print(swState);
    if (swState == LOW) {
      duration = duration_mins * 60 * 1000;
      time_start = millis();
#ifdef DEBUG
      Serial.println(duration);
      Serial.println(time_start);
#endif
      digitalWrite(BLOWER_PIN, HIGH);

      encoderValue = 0;
      mode = HEATING;
    }
    //Serial.println(mode);
    display.display();
    delay(250);
  }

  else if (mode == HEATING) {
    // heating
    time_now = millis();
    swState = digitalRead(sw);

    // read temperature
    unsigned long currentMillisReadTemp = millis();
    if (currentMillisReadTemp - previousMillisReadTemp >= 1000) {
      previousMillisReadTemp = currentMillisReadTemp;
      temp_sensor = thermocouple.readCelsius();
    }
#ifdef DEBUG
    Serial.println(temp_sensor);
#endif
    if ((time_now - time_start > duration) || !swState) {
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0,0);
      display.print("Finished");
#ifdef DEBUG
      Serial.println(F("Finished cooking!"));
#endif
      digitalWrite(BLOWER_PIN, LOW);
      digitalWrite(HEATER_PIN, LOW);
      display.display();
      delay(2000);
      mode = REQ_TEMPERATURE;
    } else {
      // control heater and display
      unsigned long currentMillisControl = millis();
      if (currentMillisControl - previousMillisControl >= 100) {
        previousMillisControl = currentMillisControl;
        unsigned long time_left = (duration - (time_now - time_start)) / 1000;
        unsigned int time_left_hrs = time_left / 3600;
        unsigned int time_left_mins = (time_left / 60) % 60;
        unsigned int time_left_secs = time_left % 60;

        String templeft = String((int)temp_sensor) + " -> " + String((int)temp_desired);      
        String timeleft = "";
        if (time_left_hrs != 0) {
          timeleft += String(time_left_hrs);
          timeleft += "j ";
        }

        if (time_left_mins != 0 || time_left_hrs != 0) {
          timeleft += String(time_left_mins);
          timeleft += "m ";
        }
        timeleft += String(time_left_secs); timeleft += "d";
        display.clearDisplay();
        display.setTextSize(2);
        display.setCursor(0,0);
        display.print(timeleft);
        display.setCursor(0,20);
        display.print(templeft);
#ifdef DEBUG
        Serial.println(timeleft);
#endif
        if (temp_sensor < temp_desired) {
          digitalWrite(HEATER_PIN, HIGH);
        } else {
          digitalWrite(HEATER_PIN, LOW);
        }
      }
    }
    display.display();
  }
}

void updateEncoder() {
  int MSB = digitalRead(out_a); //MSB = most significant bit
  int LSB = digitalRead(out_b); //LSB = least significant bit

  int encoded = (MSB << 1) | LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if (sum == 0b1101) encoderValue++;
  if (sum == 0b1110) encoderValue--;

  lastEncoded = encoded; //store this value for next time
}