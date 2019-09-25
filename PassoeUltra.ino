TaskHandle_t Task1;
TaskHandle_t Task2;

#include <Ultrasonic.h>
#define TRIGGER_PIN  32
#define ECHO_PIN     33

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);


int stepdelay;
int velocidade;
long microsec;
float cmMsec, inMsec;

void puslo();



void setup() {
  Serial.begin(9600); 
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(34, OUTPUT);

  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
}

void Task1code( void * pvParameters ){


 for(;;){
   digitalWrite(34, LOW);
   digitalWrite(12, HIGH);
   
   for(int x = 0; x < 800; x++) { // 200 passos é uma volta, tá 800 pq o passo está em 1/4
   pulso();
 }

  delay(1000);
   
  digitalWrite(12, LOW);
  for(int x = 0; x < 800; x++) { // 
    pulso();
  }

  delay(1000);
  } 
}


void loop() {
   microsec = ultrasonic.timing();
   cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
   Serial.print("CM: ");
   Serial.println(cmMsec);
}

void pulso(){
  digitalWrite(13,HIGH);
  delayMicroseconds(1000);
  digitalWrite(13,LOW);
  delayMicroseconds(1000);
}
