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

//Define flex sensor pins
int thumb = A1;
int index = A2;
int middle = A3;
int ring = A4;
int pinky = A5;

void setup(){

}

void loop(){
    
}