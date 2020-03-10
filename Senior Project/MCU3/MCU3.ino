#include <Stepper.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>  
#include <TridentTD_LineNotify.h>
#include <Servo.h>

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

//กำหนด ouput ให้หลอดไฟ

    String a;
    int o;
    int inter=0;
    int i; //กำหนดตำแหน่งแกน Y
    int j; //กำหนดตำแหน่งแกน X
    int k; //กำหนดตำแหน่งแกน Z
    int Cal;
    int axisX=0;
    int axisY=0;
    int StoreJ;
    int StoreI;

//กำหนดตำแหน่งปลูก
    int floor1[5][2]={{0,0},{1850,0},{2700,0},{3550,0},{4200,0}};
    int floor2[5][2]={{0,3700},{860,3700},{1750,3700},{2870,3700},{3870,3700}};
    int floor3[5][2]={{0,7680},{875,7680},{1850,7680},{2850,7680},{3870,7680}};
    int effect[6]={1630,7400,600,5650,5400,300};
//Set ตำแหน่งปลูก
    int AA=2,AB=2,AC=2,AD=2,AE=2,AF=2,AG=2,AH=2;
    int BA=2,BB=2,BC=2,BD=2,BE=2,BF=2,BG=2,BH=2;
//Set ช่องว่างชั้นปลูก(ถาดเพาะ)
    
    const int stepPinZ = D5; 
    const int dirPinZ = D6; 
    const int enPinZ = D8; 
 
    
//กำหนด client
    WiFiClient espClient;
    PubSubClient client(espClient);
    Servo myservo;



void setup() {
     ESP.wdtDisable(); 
     ESP.wdtEnable(WDTO_8S);
    myservo.attach(D1);
    tong();
// กำหนด Line Token
     LINE.setToken(LINE_TOKEN);

     
 // กำหนด motor
    pinMode(stepPinZ,OUTPUT); 
    pinMode(dirPinZ,OUTPUT);
    
    pinMode(enPinZ,OUTPUT);
    digitalWrite(enPinZ,LOW);

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
     
 

            
void loop(){
//เชื่อต่อ MQTT
   if (!client.connected()) {
      Serial.print("Attempting MQTT connection...");
      if (client.connect("ESP8266Client3", mqtt_user, mqtt_password)) {
        Serial.println("connected");
        } else 
        {
           Serial.print("failed, rc=");
           Serial.print(client.state());
           Serial.println(" try again in 5 seconds");
           delay(500);
           inter=0;
           return;
              }       
   } else {
    client.subscribe("/led");
    if(inter==0){
    LINE.notify("อุปกรณ์ตัวที่3ของท่านเชื่อต่ออินเตอร์เน็ตแล้ว");
    inter=1;
    }
   }
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        client.loop();
      }



void callback(char* topic, byte* massage, unsigned int length) {
      Serial.print("Message arrived [");
      Serial.print(topic);
      Serial.print("] "); 
      String ms = "";
      int o = 0;
//เลือกคำทีส่งมา
 while (o < length) ms += (char)massage[o++];
       Serial.println(ms);
       if(ms =="evolve"){
          evolve();
      }
      else if(ms =="Into1"){
          k=effect[0];
          tong();
          Into();
          evolve();
     
      }
      else if(ms =="Into2"){
          k=effect[1];
          tong();
          Into();
          evolve();
    
      }
        else if(ms =="Into3"){
          k=effect[3];
          tong();
          Into();
          evolve();
        
      }
        else if(ms =="Into4"){
          k=effect[4];
          tong();
          Into();
          evolve();
       
      }
           else if(ms =="Into5"){
          k=effect[0];  
          Into();
        
      }
           else if(ms =="Into6"){
          k=effect[1];
          Into();
         
      }
           else if(ms =="Into7"){
          k=effect[3];
          Into();
         
      }
           else if(ms =="Into8"){
          k=effect[4];
          Into();
         
      }
 
      else if(ms =="Out1"){
          k=effect[0];  
          delay(100);
          Out();
        
     
      }
      else if(ms =="Out2"){
          k=effect[1];  
          delay(100);
          Out();
   
     
      }
      else if(ms =="Out3"){
          k=effect[3];  
          delay(100);
          Out();
        
     
      }
      else if(ms =="Out4"){
          k=effect[4];  
          delay(100);
          Out();
       
     
      }
      else if(ms =="Out5"){
          tong();
          k=effect[0];
          Out();
          
     
      }
      else if(ms =="Out6"){
          tong();
          k=effect[1];
          Out();
       
     
      }
      else if(ms =="Out7"){
          tong();
          k=effect[3];
          Out();
       
     
      }
      else if(ms =="Out8"){
          tong();
          k=effect[4];
          Out();
         
     
      }
}
        


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ขยับเข้า
void Into(){
        digitalWrite(dirPinZ,LOW);            
        for(int x = 0; x < k; x++) {
          ESP.wdtDisable(); 
              digitalWrite(stepPinZ,HIGH);
              delayMicroseconds(450);
              digitalWrite(stepPinZ,LOW);
              delayMicroseconds(450);
            }
            delay(10);
            ESP.wdtEnable(WDTO_8S);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ขยับออก
void Out(){
        digitalWrite(dirPinZ,HIGH);            
        for(int x = 0; x < k; x++) {
               ESP.wdtDisable(); 
              digitalWrite(stepPinZ,HIGH);
              delayMicroseconds(450);
              digitalWrite(stepPinZ,LOW);
              delayMicroseconds(450);
            }
            delay(10);
              ESP.wdtEnable(WDTO_8S);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void tong(){
  myservo.write(-30); 
  delay(100);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void evolve(){
  myservo.write(35); 
  delay(100);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
