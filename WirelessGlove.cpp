// Title: WIreless Glove Control
//Description: Pseudocode for controlling a glove with flex sensors connected to an Arduino R3 and paired with a wireless trasnceiveer

//libaries
#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <printf.h>

//intiialize radio data
RF24 radio(7,8); //CE, CSN

const byte address[6] = "00001";

unsigned long interval = 1000;
unsigned long shortInterval = 750;
unsigned long longInterval = 3000;
unsigned long caseStartTime = 0;

//Define flex sensor pins
int thumb = A1;
int index = A2;
int middle = A3;
int ring = A4;
int pinky = A5;

int value1;
int value2;
int value3;
int value4;
int value5;

int flex1;
int flex2;
int flex3;
int flex4;
int flex5;

//Initialize Button Data
const int buttonPin = 9;    //Pin connected to the push button

int buttonState;
int lastButtonState = LOW;
int mode = 1;   //Current mode: 0 for mode 1, 1 for mode 2

bool debounceActive = false;        //Flag to track if button debouncing is active
bool initialButtonChange = false;   //Flag to track the initial button state change

unsigned long lastModeChange = 0;   //Time of the last mode change
unsigned long debounceDelay = 100;  //Debounce delay in milliseconds

void setup(){

}

void loop(){
    
}