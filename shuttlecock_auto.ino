//Globals
#include <Servo.h>
Servo myservo;

//init all Stepper 
//stepper thrower
#define STEPPIN_P 12
#define DIRPIN_P 11
#define ENAPIN_P 10
//stepper X 
#define STEPPIN_X 9
#define DIRPIN_X 8
#define ENAPIN_X 7 
//stepper Y
#define STEPPIN_Y 6
#define DIRPIN_Y 5
#define ENAPIN_Y 4 

//init all button 
int button1 = 22;
int button2 = 23;
int button3 = 24;
int button4 = 25;

const int STEPTIME = 8; // delay time stepper

void setup() {
  // put your setup code here, to run once:
  //set I/O
  pinMode(STEPPIN_P,OUTPUT);
  pinMode(DIRPIN_P,OUTPUT);
  pinMode(ENAPIN_P,OUTPUT);
  pinMode(STEPPIN_Y,OUTPUT);
  pinMode(DIRPIN_Y,OUTPUT);
  pinMode(ENAPIN_Y,OUTPUT);
  pinMode(STEPPIN_X,OUTPUT);
  pinMode(DIRPIN_X,OUTPUT);
  pinMode(ENAPIN_X,OUTPUT);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  pinMode(button4,INPUT);
  digitalWrite(button1,HIGH);
  digitalWrite(button2,HIGH);
  digitalWrite(button3,HIGH);
  digitalWrite(button4,HIGH);
  myservo.attach(3);
  myservo.write(0);
  
  Serial.begin(9600);
  
  Serial.println("Bulutangkis Professional Starting......");
  delay(150);
  Serial.println("Done! lets rock!!!!!!!!\n");
  
}

void loop() {

  if(digitalRead(button1)==LOW){
  Serial.println("button 1 on click......")  
  Serial.println("now in point A....");
  titikA();
  Serial.println("now in point B....");
  titikB();
  Serial.println("now in point C....");
  titikC();
  Serial.println("now in point D....");
  titikD();
  Serial.println("now in point E....");
  titikE();
  Serial.println("now in point F....");
  titikF();
  }
	else{
		Serial.println("button 1 release");
	}
  if(digitalRead(button2)==LOW){
	Serial.println("button 2 on click......") 
  Serial.println("now in point G....");
  titikG();
  Serial.println("now in point H....");
  titikH();
  Serial.println("now in point I....");
  titikI();
  Serial.println("now in point J.....");
  titikJ();
  Serial.println("now in point K.....");
  titikK();
  Serial.println("now in point L.....");
  titikL();
  }
	else{
		Serial.println("button 2 release");
	}
   
  if (digitalRead(button3)==LOW) {
    Serial.println("Calibration Starting.....");
     forward2(150, ENAPIN_Y, DIRPIN_Y, STEPPIN_Y);
     reverse2(160, ENAPIN_Y, DIRPIN_Y, STEPPIN_Y);
     reverse2(30, ENAPIN_P, DIRPIN_P, STEPPIN_P);
     forward2(40, ENAPIN_P, DIRPIN_P, STEPPIN_P);
    Serial.println("Done!")
    }

  if(digitalRead(button4)==LOW) {
    Serial.println("Shutting down Stepper Motor!");
    digitalWrite(4,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(10,HIGH);
  }
}

void titikA(){  
 forward(75, ENAPIN_Y, DIRPIN_Y, STEPPIN_Y);
 reverse(30, ENAPIN_X, DIRPIN_X, STEPPIN_X);
 thrower();
 delay(150);
 
}
void titikB(){  
  forward(30, ENAPIN_X, DIRPIN_X, STEPPIN_X);
  delay(150);
  thrower2();
  delay(150);
}
void titikC(){
  forward(30, ENAPIN_X, DIRPIN_X, STEPPIN_X);
  thrower2();
  reverse(30, ENAPIN_X, DIRPIN_X, STEPPIN_X);
      delay(150);
}
void titikD(){  
 forward(75, ENAPIN_Y, DIRPIN_Y, STEPPIN_Y);
 reverse(30, ENAPIN_X, DIRPIN_X, STEPPIN_X);
 thrower2();
 delay(150);
 
}
void titikE(){  
  forward(30, ENAPIN_X, DIRPIN_X, STEPPIN_X);
  delay(150);
  thrower2();
  delay(150);
}
void titikF(){
 // analogWrite(DC, 100);
  forward(30, ENAPIN_X, DIRPIN_X, STEPPIN_X);
  thrower2();
    reverse(30, ENAPIN_X, DIRPIN_X, STEPPIN_X);
  reverse(150, ENAPIN_Y, DIRPIN_Y, STEPPIN_Y);
    forward(45, ENAPIN_P, DIRPIN_P, STEPPIN_P);
  delay(150);
}
  void titikG(){  
 forward(150, ENAPIN_Y, DIRPIN_Y, STEPPIN_Y);
 reverse(30, ENAPIN_X, DIRPIN_X, STEPPIN_X);
 thrower();
 delay(150);
 
}
void titikH(){  
  reverse(75, ENAPIN_Y, DIRPIN_Y, STEPPIN_Y);
  forward(60, ENAPIN_X, DIRPIN_X, STEPPIN_X);
   delay(150);
  thrower2();
  delay(150);
}
void titikI(){
  reverse(60, ENAPIN_X, DIRPIN_X, STEPPIN_X);
  thrower2();
  delay(150);
}
void titikJ(){  
 forward(75, ENAPIN_Y, DIRPIN_Y, STEPPIN_Y);
 forward(60, ENAPIN_X, DIRPIN_X, STEPPIN_X);
 thrower2();
 delay(150);
 
}
void titikK(){  
  reverse(30, ENAPIN_X, DIRPIN_X, STEPPIN_X);
  delay(150);
  thrower2();
  delay(150);
}
void titikL(){
 // analogWrite(DC, 100);
  reverse(75, ENAPIN_Y, DIRPIN_Y, STEPPIN_Y);
  thrower2();
    reverse(75, ENAPIN_Y, DIRPIN_Y, STEPPIN_Y);
    forward(45, ENAPIN_P, DIRPIN_P, STEPPIN_P);
  delay(150);
}
//init pelontar
void thrower() {
  reverse(50, ENAPIN_P, DIRPIN_P, STEPPIN_P);
  delay(150);
  myservo.write(41);
  delay(10);    // servo close
  forward(55, ENAPIN_P, DIRPIN_P, STEPPIN_P);
  delay(10);
  myservo.write(0);
  delay(15);// servo open
  reverse(50, ENAPIN_P, DIRPIN_P, STEPPIN_P);
  delay(150);
}
//init pelontar
void thrower2() {
  myservo.write(41);
  delay(4);    // servo close
  forward(55, ENAPIN_P, DIRPIN_P, STEPPIN_P);
  delay(150);
  myservo.write(0);
  delay(4);// servo open
  reverse(50
  , ENAPIN_P, DIRPIN_P, STEPPIN_P);
  delay(150);
}
void forward(int steps, int ENA, int DIR, int STEP){
  int i;
  digitalWrite(ENA,LOW);//ENABLE IS ACTIVE LOW
  digitalWrite(DIR,HIGH);//SET DIRECTION  
  delay(200);
  for(i=0;i<steps;i++){
    digitalWrite(STEP,HIGH);
    delay(STEPTIME);
    digitalWrite(STEP,LOW);
    delay(STEPTIME);
  }
//  digitalWrite(ENA,HIGH);//DISABLE STEPPER
}

void reverse(int steps, int ENA, int DIR, int STEP){
  int i;
  digitalWrite(ENA,LOW);//ENABLE IS ACTIVE LOW
  digitalWrite(DIR,LOW);//SET DIRECTION 
  delay(200);
  for(i=0;i<steps;i++){
    digitalWrite(STEP,HIGH);
    delay(STEPTIME);
    digitalWrite(STEP,LOW);
    delay(STEPTIME);
  }
//  digitalWrite(ENA,HIGH);//DISABLE STEPPER
}
void forward2(int steps, int ENA, int DIR, int STEP){
  int i;
  digitalWrite(ENA,LOW);//ENABLE IS ACTIVE LOW
  digitalWrite(DIR,HIGH);//SET DIRECTION  
  for(i=0;i<steps;i++){
    digitalWrite(STEP,HIGH);
    delay(8);
    digitalWrite(STEP,LOW);
    delay(8);
  }
//  digitalWrite(ENA,HIGH);//DISABLE STEPPER
}

void reverse2(int steps, int ENA, int DIR, int STEP){
  int i;
  digitalWrite(ENA,LOW);//ENABLE IS ACTIVE LOW
  digitalWrite(DIR,LOW);//SET DIRECTION 
  for(i=0;i<steps;i++){
    digitalWrite(STEP,HIGH);
    delay(8);
    digitalWrite(STEP,LOW);
    delay(8);

  }}

//  digitalWrite(ENA,HIGH);//DISABLE STEPPER}