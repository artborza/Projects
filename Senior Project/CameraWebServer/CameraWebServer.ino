#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "esp_camera.h"
#include "esp_system.h"
#include <TridentTD_LineNotify.h>
#include <SoftwareSerial.h>
#include <PubSubClient.h>


hw_timer_t *timer = NULL;
void IRAM_ATTR resetModule(){
    ets_printf("reboot\n");
    esp_restart();
}

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
//value from pin  V1:CAM  V2:Sensor  V3:LED Flash

int inter=0;
char auth[] = "RV4yT1o8USvJwA0elg7nDJqq-e-TWJb7";
const char* ssid = "AofECS";
const char* password = "AAAaaa52";
String LINE_TOKEN = "qHnz9dkx5bWWC73oHGiBkqki8dWz72mBypGvza0VBeb";

// Pin definition for CAMERA_MODEL_AI_THINKER
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

// Config MQTT Server
    #define mqtt_server "tailor.cloudmqtt.com"
    #define mqtt_port  16253
    #define mqtt_user "ibpdvqkv"
    #define mqtt_password "rlFXvQvk-AB0"

const int Led_Flash = 4;
const int Led_run = 13;
int pinSensor = 0 ,pinFlash = 0 ,Cam_capture = 0 ,time_capture=0;
boolean startTimer = false;
unsigned long time_now=0;

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
BLYNK_WRITE(V1){
  Cam_capture = param.asInt();
  // assigning incoming value from pin V1 to a variable
  // process received value
}


WiFiClient espClient;
PubSubClient client(espClient);
void setup()
{
  LINE.setToken(LINE_TOKEN);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  pinMode(Led_Flash, OUTPUT);
  pinMode(Led_run, OUTPUT);

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
         
 Blynk.begin(auth,ssid, password);
  
    timer = timerBegin(0, 80, true); //timer 0, div 80Mhz 
    timerAttachInterrupt(timer, &resetModule, true);
    timerAlarmWrite(timer, 20000000, false); //set time in us 15s
    timerAlarmEnable(timer); //enable interrupt

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG; 
  
  if(psramFound()){
// FRAMESIZE_ +
//QQVGA/160x120//QQVGA2/128x160//QCIF/176x144//HQVGA/240x176
//QVGA/320x240//CIF/400x296//VGA/640x480//SVGA/800x600//XGA/1024x768
//SXGA/1280x1024//UXGA/1600x1200//QXGA/2048*1536
    config.frame_size = FRAMESIZE_VGA; 
    config.jpeg_quality = 10;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_QQVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }
  
  // Init Camera
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }
}

void loop()
{
  Blynk.run();
      if (!client.connected()) {
      Serial.print("Attempting MQTT connection...");
      if (client.connect("ESP32Client", mqtt_user, mqtt_password)) {
        Serial.println("connected");
        } else {
           Serial.print("failed, rc=");
           Serial.print(client.state());
           Serial.println(" try again in 5 seconds");
           delay(5000);
           inter=0;
           return;
              }
// MQTT Topic /ESP32             
   } else {  
    client.subscribe("/led");
    if(inter==0){
    LINE.notify("กล้องถ่ายรูปของท่านเชื่อต่ออินเตอร์เน็ตแล้ว");
    inter=1;
    }
          }
      timerWrite(timer, 0); //reset timer (feed watchdog)
    long tme = millis();
    client.loop();
}

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
      if(msg == "takeon")
      {
      Camera_capture();
      }
}
void Camera_capture() {

  camera_fb_t * fb = NULL;
  delay(200); 
  // Take Picture with Camera
  fb = esp_camera_fb_get(); 
  if(!fb) {
    Serial.println("Camera capture failed");
    return;
  }
   Send_line(fb->buf,fb->len);
   esp_camera_fb_return(fb); 
  // Serial.println("Going to sleep now");
  // esp_deep_sleep_start();
  // Serial.println("This will never be printed");

}

void Send_line(uint8_t *image_data,size_t image_size){
   LINE.notifyPicture(image_data, image_size);
  }
