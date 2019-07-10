//Проценко Я.В.
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "SH1106.h"
#include "Frame.h"

#define OLED_RESET  5   // RESET
#define OLED_DC     4   // Data/Command
#define OLED_CS     15  // Chip select
#define ReplyBuffer "OK"
#define localPort   5445
#define interruptPin 2
#define ASK         '?'
#define ESP01_port  500
#define sizeBuffer  9

SH1106 display(true, OLED_RESET, OLED_DC, OLED_CS);

IPAddress IP_ESP01(192,168,0,105);
char ssid[] = "BOBER-FM";
char pass[] = "99999999";

char Buffer[5] = {'0'};
//char Messege[50];
char packetBuffer[9][5]; //buffer to hold incoming packet

WiFiUDP Udp;

uint8_t i = 1, timeON = 0, Reply = 0;     //счётчик обычный, счётчик работы дисплея включенным 
uint16_t time1 = 0;            //счётчик до оповещенния разряда аккумулятора
long vcc = 0, rssi, averageVCC;
volatile byte ON = 0;          //переменная прерываний
bool On = true;               //переменная обычного цикла
bool FirstRequest = false;


void Draw()                                                                 //функция отрисовки таблицы
{
  display.drawXbm(0,14,Frame_width,Frame_height,(const char*)Frame_bits);
  for (uint8_t j = 0, k1 = 0; j < sizeBuffer; j++, k1 = 0)
  {
    if (j!=0)
    {
      if ((j%2 == 0)&&(j!=0))
        k1=1;
      display.drawString(((j+1)/2)*26, 15+(k1*25), String(packetBuffer[j]));
    }
    else
    {
      display.drawString(1, 15, String(packetBuffer[0]));  
    }
    display.display();   
  }
}

void Signal(long rssi_1 = rssi)                //функция отрисовки батарейки
{
  display.setColor(BLACK);
  display.drawRect(115, 2, 10, 8);
  display.fillRect(115, 2, 10, 8);
  display.setColor(WHITE);
  Serial.println(rssi_1);
  if (rssi_1 < (-80))
      display.drawXbm(115, 2, W2_width,W2_height,(const char*)W2_bits);
    else if ((rssi_1 >= (-80)) && (rssi_1 < (-70)))
      display.drawXbm(115, 2, W3_width,W3_height,(const char*)W3_bits);
      else if ((rssi_1 >= (-70)) && (rssi_1 < (-60)))
        display.drawXbm(115, 2, W4_width,W4_height,(const char*)W4_bits);
        else if (rssi_1 >= (-60))
          display.drawXbm(115, 2, W5_width,W5_height,(const char*)W5_bits);  
  display.display();
}

void Battery(long vcc_1 = averageVCC)                       //функция отрисовки уровня сигнала Wi-Fi
{
  Serial.println(vcc_1);
  if (On)
  {
    display.setColor(BLACK);
    display.drawRect(0, 2, 16, 8);
    display.fillRect(0, 2, 16, 8);
    display.setColor(WHITE);
    if (vcc_1 >= 800)
      display.drawXbm(0, 2, Img_Battery_3_width, Img_Battery_3_height, (const char*)Img_Battery_3);
      else if ((vcc_1 >= 600) && (vcc_1 < 800))
        display.drawXbm(0, 2, Img_Battery_2_width, Img_Battery_2_height, (const char*)Img_Battery_2);
        else if ((vcc_1 >= 400) && (vcc_1 < 600))
          display.drawXbm(0, 2, Img_Battery_1_width, Img_Battery_1_height, (const char*)Img_Battery_1);
          else if (vcc_1 < 400)
            display.drawXbm(0, 2, Img_Battery_0_width, Img_Battery_0_height, (const char*)Img_Battery_0);          
    display.display();
  }
  else if (vcc_1 < 400)
  {
    time1++;
    if (time1 == 60000)
    {
      time1 = 0;
      display.clear();
      display.displayOn();
      display.drawXbm(20, 20, Img_BigBattery_low_width, Img_BigBattery_low_height, (const char*)Img_BigBattery_low);
      display.display();
      delay(2000);
      display.displayOff();
     }       
  }
  i = 1;
}

void UDP_chat()
{
  int packetSize = Udp.parsePacket();
  if (packetSize > 0) 
  {
    Serial.println(packetSize);
    int len = Udp.read(Buffer, 4);         //считывание пакета в Buffer
    
    if (len > 0)
    { 
      Serial.println(len);
      Buffer[len] = '0';
    }

    Buffer[4] = '\0';           // записываем в конец признак конца строки для удобной работы с массивом как со строкой
    Udp.read();
    Udp.beginPacket(IP_ESP01, ESP01_port); //Отправляем ответ на IP и порт отправителя
    Udp.write(ReplyBuffer);
    Udp.endPacket();
    Serial.print("Contents: ");
    Serial.println(Buffer);
    if (!On)
    {
      display.displayOn();
      On = true;
      Serial.println("ON");
    }
    timeON = 0;
    if (!FirstRequest)                          // если был отправлен запрос на получение данных, то не выводить на дисплей
    {
      display.clear();
      display.setFont(ArialMT_Plain_24);
      display.drawString(30, 20, String(Buffer));
      display.display();
      delay(2000);
      display.clear();
    }
    else
    {
      Reply++;                                   //счётчик для запроса
      if (Reply == 9)                            // если считалось последнее запрошеное сообщение
      {
        Reply == 0;
        FirstRequest = false;
      }
    }
    Signal();
    Battery();
  }
}

void Attach()
{
  static unsigned long millis_prev;
  if (millis() - 100 > millis_prev)                 
      ON = 1;                        // меняем значение на противоположное
  millis_prev = millis();
  Serial.println (ON);
}

void Connect()
{
   do
   {
      WiFi.begin(ssid, pass);
      for (uint8_t i = 0; (WiFi.status() != WL_CONNECTED) || (i < 50); i++)
      {
        delay(500);
        Serial.print(".");
        i++;
      }
      if (WiFi.status() == WL_CONNECTED)
      {
        display.clear();
        display.drawString(0, 25, "Connect to \"" + String(ssid) + "\"");
      }
      else
      {
        display.clear();
        display.drawString(20, 25, "No connection");
        display.display(); 
        Serial.println("No connection"); 
        delay(10000); 
      }
    }
    while (WiFi.status()!= WL_CONNECTED);
  display.display();
  delay(2000);
  display.clear(); 
  Serial.println(WiFi.SSID());
  Serial.println(WiFi.localIP());
  Request(); 
}

void Request()
{
  Udp.beginPacket(IP_ESP01, ESP01_port);
  Udp.write(ASK);
  Udp.endPacket();
  FirstRequest = true;
}

void setup()
{
  Serial.begin(115200);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), Attach, FALLING);
  Serial.println("");
  display.init();
  display.clear();
  display.setFont(ArialMT_Plain_24);
  display.drawString(20, 20, "SMART");
  display.display();

  display.setFont(ArialMT_Plain_10);
  WiFi.mode(WIFI_STA);
  Connect();
  Draw();
  Battery();
  Signal();
    
  Udp.begin(localPort); // Начинаем «слушать» клиентов:
}

void loop()
{
  if (WiFi.isConnected())
  {
    if (ON == 1)
    {
      if (On)
      {
        Serial.println("OFF");
        display.displayOff();
        On = false;
      } 
      else
      {
        Serial.println("ON");
        display.displayOn();
        On = true;
      }
      ON = 0;
      timeON = 0;
    }
  
    UDP_chat();
  
    i++;
    vcc += analogRead(A0);             //считывание напряжения аккумулятора
    if (i%20==0)
    {
      averageVCC = vcc/20;
      Battery();
      vcc = 0;
    }
    if (On)
    {
      timeON++;
      if (i%19 == 0)
      {
        rssi = WiFi.RSSI();
        Signal();
      }
      if (Buffer[1] != '0')               //если буфер не пуст, то скопировать его содержимое в массив по первой цифре
      {
        int number = atoi(Buffer);
        uint8_t number2 = number/100;
        switch (number2)
        {
          case 17:
          {
            strcpy(packetBuffer[0],Buffer);
            break;  
          }
          case 16:
          {
            strcpy(packetBuffer[1],Buffer); 
            break;  
          }
          case 15:
          {
            strcpy(packetBuffer[2],Buffer);
            break;  
          }
          default:
          {
            for (uint8_t i = 0; i < 4; i++)
              packetBuffer[(number2-20)+2][i] = Buffer[i+1];
          } 
        }
        memset(Buffer, '0', 5);
        display.setFont(ArialMT_Plain_10);
        Draw();                                    //вызов функции рисования таблицы и содержимого массива
      }
      if (timeON >= 150)                           //отключение дисплея после 150 циклов loop()
      {
        Serial.println("OFF");
        On = false;
        display.displayOff();    
      }
    }
  }
  else
  {
    Connect();
    Draw();  
  }
  delay(50);
}
