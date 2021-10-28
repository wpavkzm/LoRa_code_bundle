#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include "SSD1306.h"
#include "images.h"

#define SCK     5    // GPIO5  -- SX1278's SCK
#define MISO    19   // GPIO19 -- SX1278's MISnO
#define MOSI    27   // GPIO27 -- SX1278's MOSI
#define SS      18   // GPIO18 -- SX1278's CS
#define RST     14   // GPIO14 -- SX1278's RESET
#define DI0     26   // GPIO26 -- SX1278's IRQ(Interrupt Request)
#define BAND  868E6

unsigned long t;

unsigned long wait_time;
unsigned long past = 0;
unsigned int counter = 0;


SSD1306 display(0x3c, 21, 22);
String rssi = "RSSI --";
String packSize = "--";
String packet ;
String LoRaData;
String sensor_name = "Sensor_10 ";



void setup() {
  pinMode(16, OUTPUT);
  pinMode(2, OUTPUT);

  digitalWrite(16, LOW);    // set GPIO16 low to reset OLED
  delay(50);
  digitalWrite(16, HIGH); // while OLED is running, must set GPIO16 in high

  Serial.begin(115200);
  while (!Serial);
  Serial.println();
  Serial.println("LoRa Sender Test");

  SPI.begin(SCK, MISO, MOSI, SS);
  LoRa.setPins(SS, RST, DI0);

  if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  //LoRa.onReceive(cbk);
  LoRa.receive();
  Serial.println("init ok");
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

  delay(1500);
}

void send_twice(unsigned int counter) {
  int count = 0;
  while (count < 3) {
    if (LoRa.parsePacket())
    {
      delay(random(100, 1000));   // wait for a second
    }
    else {
      LoRa.beginPacket();
      LoRa.print(sensor_name);
      LoRa.print(counter);
      LoRa.endPacket();
      LoRa.receive();
      count ++;
      delay(1000);
    }
  }
}


    void loop() {
      if (LoRa.parsePacket())
      {
        //    Serial.print("Received packet '");
        //    while (LoRa.available())
        //    {
        //      LoRaData = LoRa.readString();
        //      Serial.println(LoRaData);
        //    }
        delay(random(100, 1000));   // wait for a second
      }
      else {
        LoRa.beginPacket();
        LoRa.print(sensor_name);
        LoRa.print(counter);
        LoRa.endPacket();
        LoRa.receive();
        send_twice(counter);
        counter++;
        delay(1000);   // wait for a second
      }
    }
