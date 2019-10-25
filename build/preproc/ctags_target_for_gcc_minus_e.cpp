# 1 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
# 1 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
/*

  Low-cost Sous vide Cooker

  version 1.0

  Using libraries:

  - Adafruit SSD1306 for OLED display - learn.adafruit.com

  - Rotary encoder switch - www.belajarduino.com

*/
# 9 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
# 10 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 2
# 11 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 2
# 12 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 2
# 13 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 2
# 14 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 2





// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)

Adafruit_SSD1306 display(128 /* OLED display width, in pixels*/, 64 /* OLED display height, in pixels*/, &Wire, -1 /* Reset pin # (or -1 if sharing Arduino reset pin)*/);

int SCK_PIN = 9;
int CS_PIN = 10;
int SO_PIN = 11;
MAX6675 thermocouple(SCK_PIN, CS_PIN, SO_PIN);

int mode;
const int REQ_TEMPERATURE = 0;
const int REQ_DURATION = 1;
const int PREHEATING = 2;
const int HEATING = 3;

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

int swState = 0x0;
long lastDebounceTime = 0;
long debounceDelay = 50;
unsigned long previousMillisControl = 0;
unsigned long previousMillisReadTemp = 0;


void setup() {

  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(0x02 /*|< Gen. display voltage from 3.3V*/, 0x3C)) { // Address 0x3D for 128x64

    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 64 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 64 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                  "SSD1306 allocation failed"
# 64 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                  ); &__c[0];}))
# 64 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                  )));

    for (;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  pinMode(HEATER_PIN, 0x1);
  pinMode(BLOWER_PIN, 0x1);
  digitalWrite(HEATER_PIN, 0x0);
  digitalWrite(BLOWER_PIN, 0x0);

  pinMode(out_a, 0x2);
  pinMode(out_b, 0x2);
  pinMode(sw, 0x2);
  attachInterrupt(0, updateEncoder, 1);
  attachInterrupt(1, updateEncoder, 1);

  mode = REQ_TEMPERATURE;

  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 90 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 90 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                "====================================="
# 90 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                ); &__c[0];}))
# 90 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                )));
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 91 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 91 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                "===== Low-cost Sous Vide Cooker ====="
# 91 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                ); &__c[0];}))
# 91 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                )));
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 92 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 92 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                "====================================="
# 92 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                ); &__c[0];}))
# 92 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                )));

}


void loop() {
  if (mode == REQ_TEMPERATURE) {
    // requesting temperature to user
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(1 /*|< Draw 'on' pixels*/);
    display.setCursor(0, 0);
    display.print("Suhu (C):");

    temp_desired = 30 + encoderValue;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 108 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 108 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                "User wants temperature at "
# 108 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                ); &__c[0];}))
# 108 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                ))); Serial.println(temp_desired);

    display.setCursor(0, 31);
    display.print((int)temp_desired);
    swState = digitalRead(sw);
    //Serial.print(swState);
    if (swState == 0x0) {
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
    display.setTextColor(1 /*|< Draw 'on' pixels*/);
    display.setCursor(0, 0);
    display.print("Durasi");
    display.setCursor(0, 20);
    display.print("(menit):");

    unsigned long duration_mins = 10 + encoderValue;
    display.setCursor(0, 40);
    display.print(duration_mins);

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 139 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 139 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                "User wants duration at "
# 139 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                ); &__c[0];}))
# 139 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                ))); Serial.println(duration_mins);

    swState = digitalRead(sw);
    //Serial.print(swState);
    if (swState == 0x0) {
      duration = duration_mins * 60 * 1000;
      time_start = millis();

      Serial.println(duration);
      Serial.println(time_start);

      digitalWrite(BLOWER_PIN, 0x1);

      encoderValue = 0;
      mode = PREHEATING;
    }
    //Serial.println(mode);
    display.display();
    delay(250);
  }

  else if (mode == PREHEATING) {
    // preheating (waiting for the heater to reach target temperature)
    time_now = millis();
    swState = digitalRead(sw);

    // read temperature
    unsigned long currentMillisReadTemp = millis();
    if (currentMillisReadTemp - previousMillisReadTemp >= 1000) {
      previousMillisReadTemp = currentMillisReadTemp;
      temp_sensor = thermocouple.readCelsius();
    }

    Serial.println(temp_sensor);

    if ((time_now - time_start > duration) || !swState) {
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0, 0);
      display.print("Finished");

      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 180 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 180 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                    "Finished cooking!"
# 180 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                    ); &__c[0];}))
# 180 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                    )));

      digitalWrite(BLOWER_PIN, 0x0);
      digitalWrite(HEATER_PIN, 0x0);
      display.display();
      delay(2000);
      mode = REQ_TEMPERATURE;
    } else {
      String templeft = String((int)temp_sensor) + " -> " + String((int)temp_desired);
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0, 0);
      display.print("Preheating");
      display.setCursor(0, 20);
      display.print(templeft);

      // waiting for the heater to reach target temperature
      if (temp_sensor < temp_desired) {
        digitalWrite(HEATER_PIN, 0x1);
      } else {
        // switch mode to heating
        digitalWrite(HEATER_PIN, 0x0);
        mode = HEATING;
      }
    }
    display.display();
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

    Serial.println(temp_sensor);

    if ((time_now - time_start > duration) || !swState) {
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0, 0);
      display.print("Finished");

      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 228 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 228 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                    "Finished cooking!"
# 228 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino" 3
                    ); &__c[0];}))
# 228 "d:\\Gits\\SchuheHeizung\\SchuheHeizung_v2\\SchuheHeizung_v2.ino"
                    )));

      digitalWrite(BLOWER_PIN, 0x0);
      digitalWrite(HEATER_PIN, 0x0);
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
        display.setCursor(0, 0);
        display.print(timeleft);
        display.setCursor(0, 20);
        display.print(templeft);

        Serial.println(timeleft);

        if (temp_sensor < temp_desired) {
          digitalWrite(HEATER_PIN, 0x1);
        } else {
          digitalWrite(HEATER_PIN, 0x0);
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
  int sum = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if (sum == 0b1101) encoderValue++;
  if (sum == 0b1110) encoderValue--;

  lastEncoded = encoded; //store this value for next time
}
