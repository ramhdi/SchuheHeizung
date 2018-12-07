# 1 "/home/ramhdi/Documents/SchuheHeizung_v1/SchuheHeizung_v1.ino"
# 1 "/home/ramhdi/Documents/SchuheHeizung_v1/SchuheHeizung_v1.ino"
/*************************************************************

  Download latest Blynk library here:

    https://github.com/blynkkk/blynk-library/releases/latest



  Blynk is a platform with iOS and Android apps to control

  Arduino, Raspberry Pi and the likes over the Internet.

  You can easily build graphic interfaces for all your

  projects by simply dragging and dropping widgets.



    Downloads, docs, tutorials: http://www.blynk.cc

    Sketch generator:           http://examples.blynk.cc

    Blynk community:            http://community.blynk.cc

    Follow us:                  http://www.fb.com/blynkapp

                                http://twitter.com/blynk_app



  Blynk library is licensed under MIT license

  This example code is in public domain.



 *************************************************************



  This sketch shows how to write values to Virtual Pins



  NOTE:

  BlynkTimer provides SimpleTimer functionality:

    http://playground.arduino.cc/Code/SimpleTimer



  App project setup:

    Value Display widget attached to Virtual Pin V5

 *************************************************************/
# 31 "/home/ramhdi/Documents/SchuheHeizung_v1/SchuheHeizung_v1.ino"
/* Comment this out to disable prints and save space */



# 36 "/home/ramhdi/Documents/SchuheHeizung_v1/SchuheHeizung_v1.ino" 2
# 37 "/home/ramhdi/Documents/SchuheHeizung_v1/SchuheHeizung_v1.ino" 2
# 38 "/home/ramhdi/Documents/SchuheHeizung_v1/SchuheHeizung_v1.ino" 2
# 39 "/home/ramhdi/Documents/SchuheHeizung_v1/SchuheHeizung_v1.ino" 2
# 40 "/home/ramhdi/Documents/SchuheHeizung_v1/SchuheHeizung_v1.ino" 2




// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "fc1242f360c84dc7a70e2d192ec1f533";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ramhdiAP";
char pass[] = "pancasila";

BlynkTimer timer;
MAX6675_Thermocouple thermo(D5, D8, D6);

double temp_thermo;
volatile double temp_desired;
volatile bool isHeaterOn;

int heater_pin = D1;
bool LedOn;

// Membaca thermometer
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  temp_thermo = thermo.readCelsius();
  Serial.println(temp_thermo);
  Blynk.virtualWrite(5, (int)temp_thermo);

  if (Blynk.connected() && !LedOn)
  {
    digitalWrite(16, 0x0);
    LedOn = true;
  }

  else if (!Blynk.connected())
  {
    digitalWrite(16, 0x1);
    LedOn = false;
  }

  // Heater control
  if (isHeaterOn)
  {
    if (temp_thermo < temp_desired)
    {
      digitalWrite(heater_pin, 0x1);
      Serial.println("Heater is on");
    }

    else // temp_thermo >= temp_desired
    {
      digitalWrite(heater_pin, 0x0);
      Serial.println("Heater is off");
    }
  }

  else // !isHeaterOn
  {
    digitalWrite(heater_pin, 0x0);
    Serial.println("Heater is off");
  }
}

// Membaca keadaan heater
void BlynkWidgetWrite0 (BlynkReq __attribute__((__unused__)) &request, const BlynkParam __attribute__((__unused__)) &param)
{
  // You'll get HIGH/1 at startTime and LOW/0 at stopTime.
  // this method will be triggered every day
  // until you remove widget or stop project or
  // clean stop/start fields of widget
  isHeaterOn = (bool)param.asInt();
  Serial.print("Heater should be on?: ");
  Serial.println(isHeaterOn);
}

// Mengendalikan suhu heater
void BlynkWidgetWrite1 (BlynkReq __attribute__((__unused__)) &request, const BlynkParam __attribute__((__unused__)) &param)
{
  // You'll get HIGH/1 at startTime and LOW/0 at stopTime.
  // this method will be triggered every day
  // until you remove widget or stop project or
  // clean stop/start fields of widget
  temp_desired = param.asInt();

  Serial.print("Desired temperature: ");
  Serial.println(temp_desired);
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(16, 0x01);
  pinMode(heater_pin, 0x01);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
