// Title: Gauntlet System Validation
//Description:
//System Validation Engineer: Mervin Nguyen, Wilson Nguyen
//Company: Home

//DescriptionL This is pseudocode for the system validation engineer position. 
//This code will be used to validate the system of "T". 
//The system will be validated by checking the system for any debugging. 

//Pseudocode:
//Using 5 servos for each finger on the hand. 

//Loop position of sensors
//initialize all flex sensors for each finger
//initialize all servos for each finger
//initialize all motors for each finger
//initialize all sensors for each finger
//read analog values from flex sensors

//map the analog values to the servo positions
//map the analog values to the motor positions
//map the analog values to the sensor positions

//check for any debugging

//NOTES:
//intiialize communication protocol (e.g. I2C, SPI, UART)
//intiialie power management system 
// perform self-test on all sensors
//perform self-test on all actuators
//log intiial system state

//start main control loop
//read sensor data
//process sensor fata
//update actuator positions on processed data
//log system state
//check for errors
//handle errors
//repeat

//end main control loop
//perform system shutdown
//log final system state

//end
//export servo.h library for compiling error
#include <Servo.h>

//initialize all servos for each finger
Servo servoWonThumb;
Servo servoTwoIndex;
Servo servoThreeMiddle;
Servo servoFourRing;
Servo servoFivePinky;

int won = A1;
int two = A2;
int three = A3;
int four = A4;
int five = A5;

void setup(){
    Serial.begin(9600);
    servoWonThumb.attach(9);
    servoTwoIndex.attach(10);
    servoThreeMiddle.attach(11);
    servoFourRing.attach(12);
    servoFivePinky.attach(13);
}

void loop(){
    int wonPos;
    int twoPos;
    int threePos;
    int fourPos;
    int fivePos;

    int servoWonThumbPos;
    int servoTwoIndexPos;
    int servoThreeMiddlePos;
    int servoFourRingPos;
    int servoFivePinkyPos;
    
    //read analog values from flex sensors
    wonPos = analogRead(won);
    servoWonThumbPos = map(wonPos, 850, 900, 180, 0);
    servoWonThumbPos = constrain(servoWonThumbPos, 180, 0);
    servoWonThumb.write(servoWonThumbPos);

    twoPos = analogRead(two);
    servoTwoIndexPos = map(twoPos, 850, 900, 180, 0);
    servoTwoIndexPos = constrain(servoTwoIndexPos, 180, 0);
    servoTwoIndex.write(servoTwoIndexPos);

    threePos = analogRead(three);
    servoThreeMiddlePos = map(threePos, 850, 900, 180, 0);
    servoThreeMiddlePos = constrain(servoThreeMiddlePos, 180, 0);
    servoThreeMiddle.write(servoThreeMiddlePos);

    fourPos = analogRead(four);
    servoFourRingPos = map(fourPos, 850, 900, 180, 0);
    servoFourRingPos = constrain(servoFourRingPos, 180, 0);
    servoFourRing.write(servoFourRingPos);

    fivePos = analogRead(five);
    servoFivePinkyPos = map(fivePos, 850, 900, 180, 0);
    servoFivePinkyPos = constrain(servoFivePinkyPos, 180, 0);
    servoFivePinky.write(servoFivePinkyPos);

    //debug code by printing positions to serial monitor for real time monitoring
    Serial.print(wonPos);
    Serial.print("--");
    Serial.print(twoPos);
    Serial.print("--");
    Serial.print(threePos);
    Serial.print("--");
    Serial.print(fourPos);
    Serial.print("--");
    Serial.print(fivePos);

    delay (300);
}

//testing new remote repository
