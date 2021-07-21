/*
 * GRATUITOUS SETS LABORATORIES
 * PATREON SIMON SAYS Mk III
 * 
 * Re-begun: 15 July, 2021
 * 
 */

//============================================================//
//============== REFERENCE ===================================//
//============================================================//

//-------------- GAME PARAMATERS  ----------------------------//

#define numberOfButtons 4
#define answerLength 8

//-------------- PIN DEFINITIONS  ----------------------------//

const int buttonPin[4] = {8, 2, 5, 12};
const int ledPin[4] = {9, 3, 4, 11};
const int buzzPin = 10;

//-------------- GLOBAL CONSTANTS ----------------------------//

byte correctAnswer[answerLength];

//-------------- GLOBAL VARIABLES ----------------------------//

bool validAnswer = false;

//============================================================//
//============== SETUP =======================================//
//============================================================//

void setup() {

//-------------- PINMODES ------------------------------------//
  
  for (int x=0; x<4; x++){
    pinMode (buttonPin[x], INPUT);
    pinMode (ledPin[x], OUTPUT);
  }
  pinMode (buzzPin, OUTPUT);

//-------------- MISC ----------------------------------------//

  randomSeed(analogRead(A0));

  Serial.begin(9600);

  while (!validAnswer){
    createAnswer();
  }  

  Serial.println("Setup complete");
  Serial.println();

}

//============================================================//
//============== LOOP ========================================//
//============================================================//

void loop() {
  
  dbts();

}
