// Title: WIreless Glove Control
//Description: Pseudocode for controlling a glove with flex sensors connected to an Arduino R3 and paired with a wireless trasnceiveer

//libaries
#include stdio.h>
#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//intiialize radio data
RF24 radio(7,8); //CE, CSN

//Address for the radio
const byte address[6] = "00001";


int trasmit[6]; //transmit data wirelessly
int checkIndex = 1; //check index for the data

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
    Serial.begin(9600);
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_HIGH);
    radio.stopListening();

    pinMode(buttonPin, INPUT);
    Serial.println("Start the test");
}

void loop(){
    initial buttonState = digitalRead(buttonPin);   //read current state

    if(!initialButtonChange){
        if(buttonState != lastButtonState){
            lastButtonState = buttonState;
            if (buttonState == HIGH){
                initialButtonChange = true; //Button stae changed for the first time
            }
        }
        if ((millis() - lastModeChange) > debounceDelay){
            debounceActive = false; //Disable button debouncing after debounceDelay
        }
        if (modeSelect == 0){
            mode1();    //Execute mode 1 functionality
        }
        else{
            mode2();    //Execute mode 2 functionality
        }
    }

    void mode1(){   //Preset Gesture mode
        transmit[5] = 1;
        
        switch(checkIndex){
            case 1: //fully open
                delay(1000);
                if (caseStartTime == 0){
                    caseStartTime = millis();
                }

                if (millis() - caseStartTime > shortInterval){
                    checkIndex++;
                    caseStartTime = 0;
                    break;
                }

                transmit[0] = 0;
                transmit[1] = 0;
                transmit[2] = 0;
                transmit[3] = 0;
                transmit[4] = 0;
                
                break;
            case 2: //fully closed
                if (caseStartTime == 0){
                    caseStartTime = millis();
                }
                if (millis() - caseStartTime > longInterval){
                    checkIndex++;
                    caseStartTime = 0;
                    break;
                }

                transmit[0] = 95;
                transmit[1] = 120;
                transmit[2] = 90;
                transmit[3] = 0;
                transmit[4] = 115;
            break;

            case 5: //Surfer
            
        }
    }
}