{\rtf1\ansi\ansicpg1252\cocoartf2759
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // variables that will be used in this code\
\
//fUNCTION PROTOTYPES\
void driveGO();\
void Reverse();\
void FLASHING();\
\
\
//enable function\
const int EN = 6; //D6\
const int EN1 = 11; //D11\
\
\
//MOTORS\
//right motor\
const int AY = 7; //D7 1Y\
const int BY = 8; //D8 2Y\
\
\
//left motor\
const int CY = 9 ; //D9 3Y\
const int DY = 10 ; //D10 4Y\
\
\
//LEDS\
//Back two LEDS\
const int ledLeftA = 12;\
const int ledRightA = 4;\
\
\
//Middle two leds\
const int ledLeftB = 13;\
const int ledRightB = 5;\
\
\
//Front single led\
const int ledC = 1;\
\
\
//BMPR\
const int bmprLeft = 2; //D2\
const int bmprRight = 3; //D3\
\
\
void setup() \{\
  // put your setup code here, to run once:\
\
  //ENABLE\
  pinMode(EN, OUTPUT);\
  pinMode(EN1, OUTPUT);\
\
\
  //RIGHT MOTOR\
  pinMode(AY, OUTPUT);\
  pinMode(BY, OUTPUT);\
\
  //LEFT MOTOR\
  pinMode(CY, OUTPUT);\
  pinMode(DY, OUTPUT);\
\
  //THE LEDS\
  pinMode(ledLeftA  , OUTPUT);\
  pinMode(ledRightA , OUTPUT);\
  pinMode(ledLeftB  , OUTPUT);\
  pinMode(ledRightB , OUTPUT);\
  pinMode(ledC , OUTPUT);\
\
  // BUMPERS\
  pinMode(bmprLeft, INPUT);\
  pinMode(bmprRight, INPUT);\
\
\
  //SETTING HIGHT TO THE MOT0RS\
  digitalWrite(EN, HIGH );\
  digitalWrite(EN1, HIGH); // declaring for the whole code thta the car will be always be higH\
\}\
\
\
void loop() \{\
\
  //THE CAR GOING FORWARDS\
  // delay to allow car to initialize before starting the indicating leds codes\
\
  delay(1000); // 1 sec\
 FLASHING();\
 delay(1000); // 1 sec\
 \
  // drive forwards\
  driveGO();\
  digitalWrite(AY, HIGH );\
  digitalWrite(BY, LOW);\
  digitalWrite(CY, HIGH );\
  digitalWrite(DY, LOW);\
\
\
  // bumper detection directions\
  if ( digitalRead(bmprRight) == LOW ) \{\
    Reverse();\
    digitalWrite(AY, LOW );\
    digitalWrite(BY, HIGH);\
    digitalWrite(CY, LOW );\
    digitalWrite(DY, HIGH);\
    delay(1500);\
    digitalWrite(AY, LOW );\
    digitalWrite(BY, LOW);\
    digitalWrite(CY, HIGH );\
    digitalWrite(DY, LOW);\
    delay(750);\
  \}\
\
  if ( digitalRead(bmprLeft) == LOW) \{\
    Reverse();\
    digitalWrite(AY, LOW );\
    digitalWrite(BY, HIGH);\
    digitalWrite(CY, LOW );\
    digitalWrite(DY, HIGH);\
    delay(1500);\
    digitalWrite(AY, HIGH );\
    digitalWrite(BY, LOW);\
    digitalWrite(CY, LOW );\
    digitalWrite(DY, LOW);\
    delay(750);\
  \}\
\
\}\
//FUNCTIONS\
void driveGO() \{\
  // this function is called when the  car goes forward and the LEDS correspond accordingly\
  //for loop to repeat th sequence\
  digitalWrite(ledC, HIGH );\
  delay(100);\
  digitalWrite(ledC, LOW );\
  delay(100);\
  digitalWrite(ledLeftB, HIGH );\
  digitalWrite(ledRightB, HIGH );\
  delay(100);\
  digitalWrite(ledLeftB, LOW );\
  digitalWrite(ledRightB, LOW );\
  delay(100);\
  digitalWrite(ledLeftA, HIGH );\
  digitalWrite(ledRightA, HIGH );\
  delay(100);\
  digitalWrite(ledLeftA, LOW );\
  digitalWrite(ledRightA, LOW );\
  delay(100);\
\}\
\
void Reverse() \{\
  // this function is called when the  car goes backwards and the LEDS correspond accordingly\
  digitalWrite(ledLeftA, HIGH );\
  digitalWrite(ledRightA, HIGH );\
  delay(100);\
  digitalWrite(ledLeftA, LOW );\
  digitalWrite(ledRightA, LOW );\
  delay(100);\
  digitalWrite(ledLeftB, HIGH );\
  digitalWrite(ledRightB, HIGH );\
  delay(100);\
  digitalWrite(ledLeftB, LOW );\
  digitalWrite(ledRightB, LOW );\
  delay(100);\
  digitalWrite(ledC, HIGH );\
  delay(100);\
  digitalWrite(ledC, LOW );\
  delay(100);\
\}\
\
void FLASHING() \{\
  // THIS FUNCTION TELLS YOU THAT THE CAR WILL BEGIN RUNNING\
  digitalWrite(ledLeftA, HIGH );\
  digitalWrite(ledRightA, HIGH );\
  digitalWrite(ledLeftB, HIGH );\
  digitalWrite(ledRightB, HIGH );\
  digitalWrite(ledC , HIGH );\
  delay(300);\
  digitalWrite(ledLeftA, LOW);\
  digitalWrite(ledRightA, LOW);\
  digitalWrite(ledLeftB, LOW);\
  digitalWrite(ledRightB, LOW);\
  digitalWrite(ledC , LOW );\
  delay(300);\
\}\
\
\
}