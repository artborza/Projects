
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>  
#include <TridentTD_LineNotify.h>
#include <time.h>
//----------------------------------------------------------------------------------------------------------------------------------------------------------------

//เชื่อต่อ Wifi

    char ssid1[] = "AofECS"; 
    char pass1[] = "AAAaaa52";

// Config MQTT Server
    #define mqtt_server "tailor.cloudmqtt.com"
    #define mqtt_port  16253
    #define mqtt_user "ibpdvqkv"
    #define mqtt_password "rlFXvQvk-AB0"

// Config ToKen line  
    String LINE_TOKEN = "qHnz9dkx5bWWC73oHGiBkqki8dWz72mBypGvza0VBeb";
    
// กำหนดค่าเวลา
    char ntp_server1[20] = "pool.ntp.org";
    char ntp_server2[20] = "time.nist.gov";
    char ntp_server3[20] = "time.uni.net.th";
    int timezone = 7 * 3600;
    int dst = 0;
    int time1=0;
    int time2=34;
    int time3;

//กำ ouput ให้หลอดไฟ

    int j=0;
  
  
//กำหนด client
    WiFiClient espClient;
    PubSubClient client(espClient);
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
void setup() {
// กำหนด Line Token
      LINE.setToken(LINE_TOKEN);
//config time
      configTime(timezone, dst, ntp_server1, ntp_server2, ntp_server3);
// Set output 
     pinMode(D1, OUTPUT);
     pinMode(D5, OUTPUT);
     pinMode(D6, OUTPUT);
     Serial.begin(115200);
// เชื่อต่อไวไฟ

      WiFi.begin(ssid1, pass1);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        }
       Serial.println("");
       Serial.println("WiFi connected");
       Serial.println("IP address: ");
       Serial.println(WiFi.localIP());
       client.setServer(mqtt_server, mqtt_port);
       client.setCallback(callback);
       }

       
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
       
void loop() {
//เชื่อต่อ MQTT
   if (!client.connected()) {
      Serial.print("Attempting MQTT connection...");
      if (client.connect("ESP8266Client", mqtt_user, mqtt_password)) {
        Serial.println("connected");
        } else 
        {
           Serial.print("failed, rc=");
           Serial.print(client.state());
           Serial.println(" try again in 5 seconds");
           delay(500);
           j=0;
           return;
              }       
   } else {
    client.subscribe("/led");
    if(j==0){
    LINE.notify("อุปกรณ์ตัวที่1ของท่านเชื่อต่ออินเตอร์เน็ตแล้ว");
    j=1;
    }
          }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//กำค่าให้เวลาเปิดปิด
    time_t now = time(nullptr);
    struct tm* p_tm = localtime(&now);
    if(p_tm->tm_hour == 17 && p_tm->tm_min == 0 && p_tm->tm_sec == 0 )
     {
        digitalWrite(D6,HIGH);
        LINE.notify("เริ่มต้นการให้แสงต้นพืช");
     }
    }
        if(p_tm->tm_hour == 6 && p_tm->tm_min == 0 && p_tm->tm_sec == 0 )
     {
        digitalWrite(D6,LOW);
        LINE.notify("หยุดการให้แสงต้นพืช");
     }
    }

        client.loop();
      }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------


void callback(char* topic, byte* payload, unsigned int length) {
      Serial.print("Message arrived [");
      Serial.print(topic);
      Serial.print("] "); 
      String msg = "";
      int i = 0;
//เลือกคำทีส่งมา
 while (i < length) msg += (char)payload[i++];

      Serial.println(msg);
//เปิดไฟ
      if(msg == "on")
      {
      digitalWrite(D6,HIGH);
      LINE.notify("หลอดไฟติดแล้ว");
      }
//ปิดไฟ
      else if(msg == "off")
      {
     digitalWrite(D6,LOW);
     LINE.notify("หลอดไฟดับแล้ว");
      }
//เปิดปั้ม
      else if(msg == "pumpon")
      {
     digitalWrite(D5,HIGH);
     LINE.notify("ปั้มน้ำติดแล้ว");
      }
//ปิดปั้ม
     else if(msg =="pumpoff")
      {
        digitalWrite(D5,LOW);
        LINE.notify("ปั้มน้ำปิดแล้วแล้ว");
      }
       msg="0";

  }


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
