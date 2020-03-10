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
    int floor1[5][2]={{0,0},{1850,0},{2700,0},{3550,0},{4350,0}};
    int floor2[5][2]={{0,3650},{860,3650},{1860,3650},{2870,3650},{3830,3650}};
    int floor3[5][2]={{0,7620},{900,7620},{1900,7620},{2890,7620},{3830,7680}};
    int effect[6]={1570,6650,600,5470,5650,300};
//Set ตำแหน่งปลูก
    int AA=2,AB=2,AC=2,AD=2,AE=2,AF=2,AG=2,AH=2;
    int BA=2,BB=2,BC=2,BD=2,BE=2,BF=2,BG=2,BH=2;
//Set ช่องว่างชั้นปลูก(ถาดเพาะ)
    
    const int stepPinX = D2; 
    const int dirPinX = D6; 
    const int enPinX = D8; 
  
    const int stepPinY = D1; 
    const int dirPinY = D2;
    const int enPinY = D8;  

    const int stepPinZ = D6; 
    const int dirPinZ = D5; 
    const int enPinZ = D8; 
    
//กำหนด client
    WiFiClient espClient;
    PubSubClient client(espClient);
    Servo myservo;




void setup() {
     ESP.wdtDisable(); 
     ESP.wdtEnable(WDTO_8S);
// กำหนด Line Token
     LINE.setToken(LINE_TOKEN);
     myservo.attach(D5);
     client.publish("/led", "evolve"); 
 // กำหนด motor
    pinMode(stepPinX,OUTPUT); 
    pinMode(dirPinX,OUTPUT);
  
    pinMode(stepPinY,OUTPUT); 
    pinMode(dirPinY,OUTPUT);
    
    pinMode(stepPinZ,OUTPUT); 
    pinMode(dirPinZ,OUTPUT);
    
    pinMode(enPinX,OUTPUT);
    digitalWrite(enPinX,LOW);
  
    pinMode(enPinY,OUTPUT);
    digitalWrite(enPinY,LOW);

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
      if (client.connect("ESP8266Client2", mqtt_user, mqtt_password)) {
        Serial.println("connected");
        } else 
        {
           Serial.print("failed, rc=");
           Serial.print(client.state());
           Serial.println(" try again in 5 seconds");
           delay(5000);
           inter=0;
           return;
              }       
   } else {
    client.subscribe("/led");
    if(inter==0){
    LINE.notify("อุปกรณ์ตัวที่2ของท่านเชื่อต่ออินเตอร์เน็ตแล้ว");
    inter=1;
    }
   }
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        client.loop();
      }



void callback(char* topic, byte* payload, unsigned int length) {
      Serial.print("Message arrived [");
      Serial.print(topic);
      Serial.print("] "); 
      String msg = "";
      int o = 0;
//เลือกคำทีส่งมา
 while (o < length) msg += (char)payload[o++];
      tong();
       if(msg =="set")
      {       
        BA=1;
        BB=1;
        BC=1;
        BD=1;
        BE=1;
        BF=1;
        BG=1;
        BH=1;
         LINE.notify("กำหนดหลุมปลูกแล้ว");
      }
      else if(msg =="plant1")
      {
        LINE.notify("เริ่มต้นการปลูก");
        grow1();
        origin();
        LINE.notify("สิ้นสุดการปลูก");
      }
      else if(msg =="plant2")
      {
        LINE.notify("เริ่มต้นการปลูก");
        grow2();
        origin();
        LINE.notify("สิ้นสุดการปลูก");
      }
      else if(msg =="plant3")
      {
        LINE.notify("เริ่มต้นการปลูก");
        grow3();
        origin();
        LINE.notify("สิ้นสุดการปลูก");
      }
      else if(msg =="plant4")
      {
        LINE.notify("เริ่มต้นการปลูก");
        grow4();
        origin();
        LINE.notify("สิ้นสุดการปลูก");
      }
      else if(msg =="plant5")
      {
        LINE.notify("เริ่มต้นการปลูก");
        grow5();
        origin();
        LINE.notify("สิ้นสุดการปลูก");
      }
      else if(msg =="plant6")
      {
        LINE.notify("เริ่มต้นการปลูก");
        grow6();
        origin();
        LINE.notify("สิ้นสุดการปลูก");
      }
      else if(msg =="plant7")
      {
        LINE.notify("เริ่มต้นการปลูก");
        grow7();
        origin();
        LINE.notify("สิ้นสุดการปลูก");
      }
      else if(msg =="plant8")
      {
        LINE.notify("เริ่มต้นการปลูก");
        grow8();
        origin();
        LINE.notify("สิ้นสุดการปลูก");
      }
      else if(msg =="plantall")
      {
        LINE.notify("เริ่มต้นการปลูกต้นพืชทั้งหมด");
        plantall();
        LINE.notify("สิ้นสุดการปลูก");
      }
      else if(msg =="harvestall")
      {
        LINE.notify("เริ่มต้นการเก็บต้นพืชทั้งหมด");
        getall();
        LINE.notify("สิ้นสุดการเก็บ");
      }
      else if(msg =="harvest1")
      {
        LINE.notify("เริ่มต้นการเก็บต้นพืช");
        get1();
        origin();
        LINE.notify("สิ้นสุดการเก็บ");
      }
      else if(msg =="harvest2")
      {
        LINE.notify("เริ่มต้นการเก็บต้นพืช");
        get2();
        origin();
        LINE.notify("สิ้นสุดการเก็บ");
      }
      else if(msg =="harvest3")
      {
        LINE.notify("เริ่มต้นการเก็บต้นพืช");
        get3();
        origin();
        LINE.notify("สิ้นสุดการเก็บ");
      }
      else if(msg =="harvest4")
      {
        LINE.notify("เริ่มต้นการเก็บต้นพืช");
        get4();
        origin();
        LINE.notify("สิ้นสุดการเก็บ");
      }
      else if(msg =="harvest5")
      {
        LINE.notify("เริ่มต้นการเก็บต้นพืช");
        get5();
        origin();
        LINE.notify("สิ้นสุดการเก็บ");
      }
      else if(msg =="harvest6")
      {
        LINE.notify("เริ่มต้นการเก็บต้นพืช");
        get6();
        origin();
        LINE.notify("สิ้นสุดการเก็บ");
      }
      else if(msg =="harvest7")
      {
        LINE.notify("เริ่มต้นการเก็บต้นพืช");
        get7();
        origin();
        LINE.notify("สิ้นสุดการเก็บ");
      }
      else if(msg =="harvest8")
      {
        LINE.notify("เริ่มต้นการเก็บต้นพืช");
        get8();
        origin();
        LINE.notify("สิ้นสุดการเก็บ");
      }
      else if(msg =="takeon1")
      {
        LINE.notify("เริ่มต้นการถ่ายภาพ");
        takephoto1();
        origin();
        LINE.notify("สิ้นสุดการถ่ายภาพ");
      }
      else if(msg =="takeon2")
      {
        LINE.notify("เริ่มต้นการถ่ายภาพ");
        takephoto2();
        origin();
        LINE.notify("สิ้นสุดการถ่ายภาพ");
      }
      else if(msg =="takeon3")
      {
        LINE.notify("เริ่มต้นการถ่ายภาพ");
        takephoto3();
        origin();
        LINE.notify("สิ้นสุดการถ่ายภาพ");
      }
      else if(msg =="takeon4")
      {
        LINE.notify("เริ่มต้นการถ่ายภาพ");
        takephoto4();
        origin();
        LINE.notify("สิ้นสุดการถ่ายภาพ");
      }
      else if(msg =="takeon5")
      {
        LINE.notify("เริ่มต้นการถ่ายภาพ");
        takephoto5();
        origin();
        LINE.notify("สิ้นสุดการถ่ายภาพ");
      }
      else if(msg =="takeon6")
      {
        LINE.notify("เริ่มต้นการถ่ายภาพ");
        takephoto6();
        origin();
        LINE.notify("สิ้นสุดการถ่ายภาพ");
      }
      else if(msg =="takeon7")
      {
        LINE.notify("เริ่มต้นการถ่ายภาพ");
        takephoto7();
        origin();
        LINE.notify("สิ้นสุดการถ่ายภาพ");
      }
      else if(msg =="takeon8")
      {
        LINE.notify("เริ่มต้นการถ่ายภาพ");
        takephoto8();
        origin();
        LINE.notify("สิ้นสุดการถ่ายภาพ");
      }
       msg="0";
  }

  
void plantall(){
     if(AA==2){
      AA=0;
     }
     if(AB==2){
      AB=0;
     }
     if(AC==2){
      AC=0;
     }
     if(AD==2){
      AD=0;
     }
     if(AE==2){
      AE=0;
     }
     if(AF==2){
      AF=0;
     }
     if(AG==2){
      AG=0;
     }
     if(AH==2){
      AH=0;
     }
    
     if(AA==0){
        grow1(); 
      }
      if(AB==0){
        grow2();
     }
     if(AC==0){
        grow3();
     }
     if(AD==0){
        grow4();
     }
     if(AE==0){
        grow5();
     }
     if(AF==0){
        grow6();
     }
     if(AG==0){
        grow7();
     }
     if(AH==0){
        grow8();
     }
      origin();

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void getall(){
  
 if(AA==1){
    get1(); 
  }
  if(AB==1){
    get2();
 }
 if(AC==1){
   get3();
 }
 if(AD==1){
    get4();
 }
 if(AE==1){
    get5();
 }
 if(AF==1){
    get6();
 }
 if(AG==1){
    get7();
 }
 if(AH==1){
    get8();
 }
  origin();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ปลูก1
void grow1(){
  check1();
  i=floor3[0][1];
  StoreI=i;
  AA=3;
  check4();
  i=StoreI;
  Below();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ปลูก2
void grow2(){
  check1();
  i=floor3[0][1];
  StoreI=i;
  AB=3;
  check4();
  i=StoreI;
  Below();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ปลูก3
void grow3(){
  check1();
  i=floor3[0][1];
  StoreI=i;
  AC=3;
  check4();
  i=StoreI;
  Below();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ปลูก4
void grow4(){
  check1();
  i=floor3[0][1];
  StoreI=i;
  AD=3;
  check4();
  i=StoreI;
  Below();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ปลูก5
void grow5(){
  check1();
  i=floor2[0][1];
  StoreI=i;
  AE=3;
  check4();
  i=StoreI;
  Below();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ปลูก6
void grow6(){
  check1();
  i=floor2[0][1];
  StoreI=i;
  AF=3;
  check4();
  i=StoreI;
  Below();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ปลูก7
void grow7(){
  check1();
  i=floor2[0][1];
  StoreI=i;
  AG=3;
  check4();
  i=StoreI;
  Below();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ปลูก8
void grow8(){
  check1();
  i=floor2[0][1];
  StoreI=i;
  AH=3;
  check4();
  i=StoreI;
  Below();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//เก็บ1
void get1(){
  AA=3;
  client.publish("/led", "evolve"); 
  check3();
  check2();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//เก็บ2
void get2(){
  AB=3;
  check3();
  check2();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//เก็บ3
void get3(){
  AC=3;
  check3();
  check2();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//เก็บ4
void get4(){
  AD=3;
  check3();
  check2();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//เก็บ5
void get5(){
  AE=3;
  check3();
  check2();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//เก็บ6
void get6(){
  AF=3;
  check3();
  check2();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//เก็บ7
void get7(){
  AG=3;
  check3();
  check2();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//เก็บ8
void get8(){
  AH=3;
  check3();
  check2();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ถ่ายรูปต้น1
void takephoto1(){

evolve(); 
  i=floor3[0][1];
  On();
  j=floor3[1][0];
  Right();
  client.publish("/led", "takeon"); 
  delay(15000);
  Left();
  Below();

  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ถ่ายรูปต้น1
void takephoto2(){
 
 evolve();
  i=floor3[0][1];
  On();
  j=floor3[2][0];
  Right();
  client.publish("/led", "takeon"); 
  delay(15000);
  Left();
  Below();
 
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ถ่ายรูปต้น1
void takephoto3(){

evolve();
  i=floor3[0][1];
  On();
  j=floor3[3][0];
  Right();
 client.publish("/led", "takeon"); 
  delay(15000);
  Left();
  Below();

  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ถ่ายรูปต้น1
void takephoto4(){

evolve(); 
    i=floor3[0][1];
  On();
  j=floor3[4][0];
  Right();
  client.publish("/led", "takeon"); 
  delay(15000);
  Left();
  Below();
 
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ถ่ายรูปต้น1
void takephoto5(){
  evolve();
  i=floor2[0][1];
  On();
  j=floor2[1][0];
  Right();
  client.publish("/led", "takeon"); 
  delay(15000);
  Left();
  Below();

  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ถ่ายรูปต้น1
void takephoto6(){
 
 evolve();
  i=floor2[0][1];
  On();
  j=floor2[2][0];
  Right();
  client.publish("/led", "takeon"); 
  delay(15000);
  Left();
  Below();
 
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ถ่ายรูปต้น1
void takephoto7(){
 
 evolve();
  i=floor2[0][1];
  On();
  j=floor2[3][0];
  Right();
 client.publish("/led", "takeon"); 
  delay(15000);
  Left();
  Below();

  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ถ่ายรูปต้น1
void takephoto8(){

  evolve();
  i=floor2[0][1];
  On();
  j=floor2[4][0];
  Right();
 client.publish("/led", "takeon"); 
  delay(15000);
  Left();
  Below();

  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cal(){
  Cal = j-axisX;
  if(Cal>0){
    j= j-axisX;
    Right();
  }
  else{
    j=axisX-j;
    Left();
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//เช็คการยกขึ้นจากแปลงเพาะ
void check1(){
  if(BA == 1){
    j=floor1[1][0];
    StoreJ=j;
    cal();
    Upper2();
    axisX=StoreJ;
    axisY=i;
    BA=0;
  }
  else if(BB == 1){
    j=floor1[2][0];
    StoreJ=j;
    cal();
    Upper2();
    axisX=StoreJ;
    axisY=i;
    BB=0;
  }
  else if(BC == 1){
    j=floor1[3][0];
    StoreJ=j;
    cal();
    Upper2();
    axisX=StoreJ;
    axisY=i;
    BC=0;
  }
  else if(BD == 1){
    j=floor1[4][0];
    StoreJ=j;
    cal();
    Upper2();
    axisX=StoreJ;
    axisY=i;
    BD=0;
  }
  else if(BE == 1){
    j=floor1[1][0];
    StoreJ=j;
    cal();
    Upper3();
    axisX=StoreJ;
    axisY=i;
    BE=0;
  }
  else if(BF == 1){
    j=floor1[2][0];
    StoreJ=j;
    cal();
    Upper3();
    axisX=StoreJ;
    axisY=i;
    BF=0;
  }
  else if(BG == 1){
    j=floor1[3][0];
    StoreJ=j;
    cal();
    Upper3();
    axisX=StoreJ;
    axisY=i;
    BG=0;
  }
  else if(BH == 1){
    j=floor1[4][0];
    StoreJ=j;
    cal();
    Upper3();
    axisX=StoreJ;
    axisY=i;
    BH=0;
  }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//เช็คการยกลงแปลงเพาะ
void check2(){
  if(BE == 0){
    j=floor1[1][0];
    StoreJ=j;
    i=axisY;
    cal();
    Below();
    Lowwer3();
    axisX=StoreJ;
    axisY=0;
    BE=1;
  }
  else if(BF == 0){
    j=floor1[2][0];
    StoreJ=j;
    i=axisY;
    cal();
    Below();
    Lowwer3();
    axisX=StoreJ;
    axisY=0;
    BF=1;
  }
  else if(BG == 0){
    j=floor1[3][0];
    StoreJ=j;
    i=axisY;
    cal();
    Below();
    Lowwer3();
    axisX=StoreJ;
    axisY=0;
    BG=1;
  }
  else if(BH == 0){
    j=floor1[4][0];
    StoreJ=j;
    i=axisY;
    cal();
    Below();
    Lowwer3();
    axisX=StoreJ;
    axisY=0;
    BH=1;
  }
  else if(BD == 0){
    j=floor1[4][0];
    StoreJ=j;
    i=axisY;
    cal();
    Below();
    Lowwer2();
    axisX=StoreJ;
    axisY=0;
    BD=1;
  }
  else if(BC == 0){
    j=floor1[3][0];
    StoreJ=j;
    i=axisY;
    cal();
    Below();
    Lowwer2();
    axisX=StoreJ;
    axisY=0;
    BC=1;
  }
  else if(BB == 0){
    j=floor1[2][0];
    StoreJ=j;
    i=axisY;
    cal();
    Below();
    Lowwer2();
    axisX=StoreJ;
    axisY=0;
    BB=1;
  }
  else if(BA == 0){
    j=floor1[1][0];
    StoreJ=j;
    i=axisY;
    cal();
    Below();
    Lowwer2();
    axisX=StoreJ;
    axisY=0;
    BA=1;
  }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//เช็คการยกขึ้นจากถาดปลูก
void check3(){
  if(AA == 3){
    i=floor3[0][1];
    j=floor3[1][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Upper1();
    axisX=StoreJ;
    axisY=StoreI;
    AA=0;
  }
  else if(AB == 3){
    i=floor3[0][1];
    j=floor3[2][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Upper1();
    axisX=StoreJ;
    axisY=StoreI;
    AB=0;
  }
  else if(AC == 3){
    i=floor3[0][1];
    j=floor3[3][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Upper1();
    axisX=StoreJ;
    axisY=StoreI;
    AC=0;
  }
  else if(AD == 3){
    i=floor3[0][1];
    j=floor3[4][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Upper1();
    axisX=StoreJ;
    axisY=StoreI;
    AD=0;
  }
  else if(AE == 3){
    i=floor2[0][1];
    j=floor2[1][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Upper1();
    axisX=StoreJ;
    axisY=StoreI;
    AE=0;
  }
  else if(AF == 3){
    i=floor2[0][1];
    j=floor2[2][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Upper4();
    axisX=StoreJ;
    axisY=StoreI;
    AF=0;
  }
  else if(AG == 3){
    i=floor2[0][1];
    j=floor2[3][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Upper4();
    axisX=StoreJ;
    axisY=StoreI;
    AG=0;
  }
  else if(AH == 3){
    i=floor2[0][1];
    j=floor2[4][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Upper4();
    axisX=StoreJ;
    axisY=StoreI;
    AH=0;
  }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//เช็คการยกลงถาดปลูก
void check4(){
  if(AA == 3){
    i=floor3[0][1];
    j=floor3[1][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Lowwer1();
    axisX=StoreJ;
    axisY=StoreI;
    AA=1;
  }
  else if(AB == 3){
    i=floor3[0][1];
    j=floor3[2][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Lowwer1();
    axisX=StoreJ;
    axisY=StoreI;
    AB=1;
  }
  else if(AC == 3){
    i=floor3[0][1];
    j=floor3[3][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Lowwer1();
    axisX=StoreJ;
    axisY=StoreI;
    AC=1;
  }
  else if(AD == 3){
    i=floor3[0][1];
    j=floor3[4][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Lowwer1();
    axisX=StoreJ;
    axisY=StoreI;
    AD=1;
  }
  else if(AE == 3){
    i=floor2[0][1];
    j=floor2[1][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Lowwer4();
    axisX=StoreJ;
    axisY=StoreI;
    AE=1;
  }
  else if(AF == 3){
    i=floor2[0][1];
    j=floor2[2][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Lowwer4();
    axisX=StoreJ;
    axisY=StoreI;
    AF=1;
  }
  else if(AG == 3){
    i=floor2[0][1];
    j=floor2[3][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Lowwer4();
    axisX=StoreJ;
    axisY=StoreI;
    AG=1;
  }
  else if(AH == 3){
    i=floor2[0][1];
    j=floor2[4][0];
    StoreJ=j;
    StoreI=i;
    On();
    cal();
    Lowwer4();
    axisX=StoreJ;
    axisY=StoreI;
    AH=1;
  }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ยกขึ้นถาดปลูก
void Upper1(){
  k=effect[3];
  tong();
  delay(500);
  Into();
  delay(500);
   evolve();
   delay(500);
  i=effect[2];
  On();
  delay(500);
  k=effect[3];
  Out(); 
  
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Upper2(){
  k=effect[0];
  tong();
  Into();
  delay(500);
   evolve();
   delay(500);
  i=effect[2];
  On();
  delay(500);
  Out();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ยกลงจากถาดเพาะแถว2
void Upper3(){
  k=effect[1];
  tong();
  delay(500);
  Into();
  evolve();
  delay(500);
  i=effect[2];
  On();
  delay(500);
  Out(); 
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Upper4(){
  k=effect[4];
  tong();
  delay(500);
  Into();
  evolve();
  delay(500);
  i=effect[2];
  On();
  delay(500);
  Out();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//กลับจุดOringin;
void origin(){
  j=axisX;
  Left();
  axisY=0;
  axisX=0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ยกขึ้นถาดปลูก
void Lowwer1(){
  k=effect[3];
  delay(500);
  Into();
  delay(500);
  i=effect[2];
  Below();
  delay(500);
  tong();
  delay(500);
  k=effect[3];
  Out();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ยกลงจากถาดเพาะแถว1
void Lowwer2(){
  k=effect[0];
  delay(500);
  Into();
  delay(500);
  i=effect[2];
  Below();
  delay(500);
   tong();
   delay(500);
  Out();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ยกลงจากถาดเพาะแถว2
void Lowwer3(){
  k=effect[1];
  delay(500);
  Into();
  delay(500);
  i=effect[2];
  Below();
  delay(500);
  tong();
  delay(500);
  Out();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ยกขึ้นถาดปลูก
void Lowwer4(){
  k=effect[4];
  delay(500);
  Into();
  delay(500);
  i=effect[2];
  Below();
  tong();
  delay(500);
  k=effect[4];
  Out();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ขยับซ้าย
void Left(){
        digitalWrite(dirPinX,LOW);            
        for(int x = 0; x <j; x++) {
            ESP.wdtDisable(); 
            digitalWrite(stepPinX,HIGH);
            delayMicroseconds(400);
            digitalWrite(stepPinX,LOW);
            delayMicroseconds(400);
            }
            delay(100);
            ESP.wdtEnable(WDTO_8S);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ขยับขวา
void Right(){
        digitalWrite(dirPinX,HIGH);            
        for(int x = 0; x <j; x++) {
            ESP.wdtDisable(); 
            digitalWrite(stepPinX,HIGH);
            delayMicroseconds(400);
            digitalWrite(stepPinX,LOW);
            delayMicroseconds(400);
            }
            delay(100);
            ESP.wdtEnable(WDTO_8S);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ขยับบน
void On(){
        digitalWrite(dirPinY,HIGH);            
        for(int x = 0; x <i; x++) {
            ESP.wdtDisable(); 
            digitalWrite(stepPinY,HIGH);
            delayMicroseconds(500);
            digitalWrite(stepPinY,LOW);
            delayMicroseconds(500);
            }
            delay(100);
            ESP.wdtEnable(WDTO_8S);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ขยับล่าง
void Below(){
        delay(1000); 
        digitalWrite(dirPinY,LOW);            
        for(int x = 0; x <i; x++) {
          ESP.wdtDisable(); 
            digitalWrite(stepPinY,HIGH);
            delayMicroseconds(500);
            digitalWrite(stepPinY,LOW);
            delayMicroseconds(500);
            }
            delay(100);
            ESP.wdtEnable(WDTO_8S);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
  myservo.write(40); 
  delay(100);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
