// SchuheHeizung_v1
// code by ramhdi
// 06/12/2018
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <MAX6675_Thermocouple.h>
#include <PID_v1.h>
#include <MAX6675_Thermocouple.h>

// pin SPI
#define SCK_PIN D5
#define CS_PIN  D8
#define SO_PIN  D6

// kode auth Blynk
char auth[] = "fc1242f360c84dc7a70e2d192ec1f533";

// memilih wifi
char ssid[] = "ramhdiAP";
char pass[] = "pancasila";

// class constructor
BlynkTimer timer;
MAX6675_Thermocouple thermo(SCK_PIN, CS_PIN, SO_PIN);

double temp_thermo; // suhu pembacaan sensor
volatile double temp_desired; // suhu masukan pengguna 
volatile bool isHeaterOn; // keadaan pemanas yang pengguna inginkan

// inisialisasi pin
// tidak ada variabel pin relay
// karena dikendalikan langsung dari app Blynk
int heater_pin = D1;
bool LedOn;

// sinkronisasi masukan pengguna pada app Blynk
// dipanggil setiap berhasil koneksi ke Blynk
BLYNK_CONNECTED() {
    Blynk.syncAll();
}

// membaca sensor suhu dan mengendalikan suhu pemaas
void myTimerEvent()
{
  Serial.println(temp_thermo);
  Blynk.virtualWrite(V5, (int)temp_thermo); // mengirimkan data suhu ke pengguna

  // indikator koneksi menggunakan built-in LED
  if (Blynk.connected() && !LedOn) // terkoneksi, led nyala
  {
    digitalWrite(LED_BUILTIN, LOW); // menggunakan LOW karena led menggunakan pullup
    LedOn = true;
  }

  else if (!Blynk.connected())
  {
    digitalWrite(LED_BUILTIN, HIGH); // gagal koneksi, led mati
    LedOn = false;
  }

  // Heater control
  if (isHeaterOn)
  {
    if (temp_thermo < temp_desired)
    {
      digitalWrite(heater_pin, HIGH);
      Serial.println("Heater is on");
    }

    else  // temp_thermo >= temp_desired
    {
      digitalWrite(heater_pin, LOW);
      Serial.println("Heater is off");
    }
  }

  else  // !isHeaterOn
  {
    digitalWrite(heater_pin, LOW);
    Serial.println("Heater is off");
  }
}

// Membaca keadaan heater dari pengguna
BLYNK_WRITE(V0)
{
  isHeaterOn = (bool)param.asInt();
  Serial.print("Heater should be on?: ");
  Serial.println(isHeaterOn);
}

// membaca suhu yang diinginkan pengguna
BLYNK_WRITE(V1)
{
  temp_desired = param.asInt();
  
  Serial.print("Desired temperature: ");
  Serial.println(temp_desired);
}

void setup()
{
  Serial.begin(115200);

  // inisialisasi pin built-in LED dan pemanas
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(heater_pin, OUTPUT);
  Blynk.begin(auth, ssid, pass);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
}
