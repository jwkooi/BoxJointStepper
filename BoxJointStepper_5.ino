/* Program for box joint rig with steppermotor
   Jan Willem Kooi
   start datum: 27 sep 2015
   25 okt 2015: Adding limit switch and bug fixing
   14 nov 2015: Adding reverse and bug fixing
   02 jan 2016: New hardware, rotary encoder is reversed (adjustment in _90_interupt_0 
*/

// Debug opties
#include "Arduino.h"   // replace this by "WProgram.h" when your IDE is older then 1.0

#define DEBUG true // true = serial commands work,  false = no serial commands
#define Serial if(DEBUG)Serial


// I2C LCD display 16x2
#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


/* Interrups
   read a rotary encoder with interrupts
   Encoder hooked up with common to GROUND,
   encoder0PinA to pin 2, encoder0PinB to pin 3 (or pin 3 see below)
   it doesn't matter which encoder pin you use for A or B
*/

// red switch
#define RedButton 5 // purple
#define LimitSwitch 10 // white

// rotary encoder
#define Encoder0PinA  2 // brown
#define Encoder0PinB  4 // orange
#define Switch1Pin    3 // green

#define RedLed 6  // red
#define GreenLed 7  //green

#define Debounce 300 //delay after button is pressed in msec

//stepper
#define Step 8
#define Direction 9


#define StepperSpeed 160 // Pulsewidth related to speed stepper in microseconds, higher is slower 

volatile int Encoder0Pos = 0; //use volatile since interrups use this variable
volatile boolean RotarySwitchOn; //will be set in interrupt_1 true = go to menu

// Global variabels

#define MaxDimension 10000 // Maximum finger or Gap width 1/10 mm 

int unsigned TenthMM = 106; //Pitch M10 is 1,5mm Stepper 200x 1/8 steps.
//1/10mm is 106.66667 steps.
//addition correction step done in 'moving'

int unsigned StepCorrectionTreshold = 77; //Accuracy setting. Lower = moving more (if too small), Higher = moving less (if to big)
int StepCorrection = 0; //

int unsigned FingerWidth = 90; //Width of finger 1/10 mm
int unsigned GapWidth = 90; //Width of gap between fingers 1/10 mm


int unsigned SawBlade = 30; //Saw blade width in 1/10 mm, default 3mm
int unsigned OverLap = 0; // Overlap between saw cuts in 1/10 mm

boolean Reverse = false; //normal: first finger than gap, reverse first gap than finger

int Dummy1; // used for switching values



