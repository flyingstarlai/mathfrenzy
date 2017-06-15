#include <SoftwareSerial.h>

// bluetooth pin
SoftwareSerial BT(10, 11);  //TX D10, RX D11


// TETRIS TONES credit to electricmango //

#include "pitches.h"


//notes in the melody:
int melody[] = {
  NOTE_E5, NOTE_E3, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, 
  NOTE_B4, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_A3, NOTE_D5,
  NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_D5, NOTE_E3, NOTE_E5,
  NOTE_E3, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_B2, 
  NOTE_C3, NOTE_D3, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_C5, NOTE_C5, NOTE_G5, 
  NOTE_F5, NOTE_E5, NOTE_C3, 0, NOTE_C5, NOTE_E5, NOTE_A4, NOTE_G4, NOTE_D5,
  NOTE_C5, NOTE_B4, NOTE_E4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_E5, 
  NOTE_G4, NOTE_C5, NOTE_E4, NOTE_A4, NOTE_E3, NOTE_A4, 0, 
  NOTE_E5, NOTE_E3, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, 
  NOTE_B4, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_A3, NOTE_D5,
  NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_D5, NOTE_E3, NOTE_E5,
  NOTE_E3, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_B2, 
  NOTE_C3, NOTE_D3, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_C5, NOTE_C5, NOTE_G5, 
  NOTE_F5, NOTE_E5, NOTE_C3, 0, NOTE_C5, NOTE_E5, NOTE_A4, NOTE_G4, NOTE_D5,
  NOTE_C5, NOTE_B4, NOTE_E4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_E5, 
  NOTE_G4, NOTE_C5, NOTE_E4, NOTE_A4, NOTE_E3, NOTE_A4, 0,
  NOTE_E4, NOTE_E3, NOTE_A2, NOTE_E3, NOTE_C4, NOTE_E3, NOTE_A2, NOTE_E3, 
  NOTE_D4, NOTE_E3, NOTE_GS2, NOTE_E3, NOTE_B3, NOTE_E3, NOTE_GS2, NOTE_E3,
  NOTE_C4, NOTE_E3, NOTE_A2, NOTE_E3, NOTE_A3, NOTE_E3, NOTE_A2, NOTE_E3, 
  NOTE_GS3, NOTE_E3, NOTE_GS2, NOTE_E3, NOTE_B3, NOTE_E3, NOTE_GS2, NOTE_E3, 
  NOTE_E4, NOTE_E3, NOTE_A2, NOTE_E3, NOTE_C4, NOTE_E3, NOTE_A2, NOTE_E3, 
  NOTE_D4, NOTE_E3, NOTE_GS2, NOTE_E3, NOTE_B3, NOTE_E3, NOTE_GS2, NOTE_E3,
  NOTE_C4, NOTE_E3, NOTE_E4, NOTE_E3, NOTE_A4, NOTE_E3, NOTE_A2, NOTE_E3, 
  NOTE_GS4, NOTE_E3, NOTE_GS2, NOTE_E3, NOTE_GS2, NOTE_E3, NOTE_GS2, NOTE_E3,
  NOTE_E5, NOTE_E3, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, 
  NOTE_B4, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_A3, NOTE_D5,
  NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_D5, NOTE_E3, NOTE_E5,
  NOTE_E3, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_B2, 
  NOTE_C3, NOTE_D3, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_C5, NOTE_C5, NOTE_G5, 
  NOTE_F5, NOTE_E5, NOTE_C3, 0, NOTE_C5, NOTE_E5, NOTE_A4, NOTE_G4, NOTE_D5,
  NOTE_C5, NOTE_B4, NOTE_E4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_E5, 
  NOTE_G4, NOTE_C5, NOTE_E4, NOTE_A4, NOTE_E3, NOTE_A4, 0, 
  NOTE_E5, NOTE_E3, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, 
  NOTE_B4, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_A3, NOTE_D5,
  NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_D5, NOTE_E3, NOTE_E5,
  NOTE_E3, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_B2, 
  NOTE_C3, NOTE_D3, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_C5, NOTE_C5, NOTE_G5, 
  NOTE_F5, NOTE_E5, NOTE_C3, 0, NOTE_C5, NOTE_E5, NOTE_A4, NOTE_G4, NOTE_D5,
  NOTE_C5, NOTE_B4, NOTE_E4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_E5, 
  NOTE_G4, NOTE_C5, NOTE_E4, NOTE_A4, NOTE_E3, NOTE_A4, 0,
  NOTE_E4, NOTE_E3, NOTE_A2, NOTE_E3, NOTE_C4, NOTE_E3, NOTE_A2, NOTE_E3, 
  NOTE_D4, NOTE_E3, NOTE_GS2, NOTE_E3, NOTE_B3, NOTE_E3, NOTE_GS2, NOTE_E3,
  NOTE_C4, NOTE_E3, NOTE_A2, NOTE_E3, NOTE_A3, NOTE_E3, NOTE_A2, NOTE_E3, 
  NOTE_GS3, NOTE_E3, NOTE_GS2, NOTE_E3, NOTE_B3, NOTE_E3, NOTE_GS2, NOTE_E3, 
  NOTE_E4, NOTE_E3, NOTE_A2, NOTE_E3, NOTE_C4, NOTE_E3, NOTE_A2, NOTE_E3, 
  NOTE_D4, NOTE_E3, NOTE_GS2, NOTE_E3, NOTE_B3, NOTE_E3, NOTE_GS2, NOTE_E3,
  NOTE_C4, NOTE_E3, NOTE_E4, NOTE_E3, NOTE_A4, NOTE_E3, NOTE_A2, NOTE_E3, 
  NOTE_GS4, NOTE_E3, NOTE_GS2, NOTE_E3, NOTE_GS2, NOTE_E3, NOTE_GS2, NOTE_E3,
};

int noteDurations[] = {
  8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,4,8,8,16,16,8,8,8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,4,4,
  8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,4,8,8,16,16,8,8,8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,4,4,
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,4,8,8,16,16,8,8,8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,4,4,
  8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,4,8,8,16,16,8,8,8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,4,4,
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
};

int buzzer = 12;








int trueKnockSensor = 0;               
int falseKnockSensor = 1;      

int THRESHOLD = 40;

int numArray[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,0,1,1,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 0,1,1,1,1,0,1 },    // 3
                          { 0,0,1,1,0,1,1 },    // 4
                          { 0,1,1,1,0,1,1 },    // 5
                          { 1,1,1,1,1,0,1 },    // 6
                          { 0,0,1,1,1,1,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 0,1,1,1,1,1,1 }};   // 9
                                       

char signal;
char musicSignal;

//game object
int score = 0; //score
bool readKnock = false;
int trueKnock;
int falseKnock;
bool keyAnswer = false;
bool hit = false;
bool firstHit = false;
bool timeOver = false;

bool intro = true;


//game engine
bool gameRunning = false;
bool gameOver = false;


void buzz() {
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(100);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(100);
}



// generate answer method
bool generateKeyAnswer() {
  int rnd = random(1, 7); // random 1 - 6
  Serial.println(rnd);
  if(rnd > 3) return true;
  else return false;
 
}

//write score
void writeScore(int number) 
{
  int pin= 2;
  for (int j=0; j < 7; j++) {
   digitalWrite(pin, numArray[number][j]);
   pin++;
  }
}

// comparing method
void compareKnockToAnswer(bool answer) {
  Serial.print("answer: ");
  Serial.println(answer);
  Serial.print("key: ");
  Serial.println(keyAnswer);

  if(answer == keyAnswer) {
    // add score
    score += 1;
    if(score==10) score = 0;
    writeScore(score);

     // generate bool then send key answer
    keyAnswer = generateKeyAnswer();
    if(keyAnswer) BT.println("TRUE");
    else BT.println("FALSE");

  } 
  else {
    gameRunning = false;
    gameOver = true;
    BT.println("DIE");
  }

   
}

void playTetris(int duration) {
  int length = sizeof(melody);
  if(duration != 0) length = duration;
  for (int thisNote = 0; thisNote <  length / sizeof(melody[0]); thisNote++){
  
      /*
        to calculate the note duration, take one second divided by the note type.
        e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      */
      int noteDuration = 1000/noteDurations[thisNote];
      tone(buzzer, melody[thisNote],noteDuration);
      
      /*
        to distinguish the notes, set a minimum time between them.
        the note's duration + 30% seems to work well:
       */
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
     
      noTone(buzzer); //stop the tone playing:
    }
    intro = false;
}



void setup() {
  pinMode(buzzer, OUTPUT);
  BT.begin(9600);
  
  pinMode(2, OUTPUT);  // 2

  pinMode(3, OUTPUT);  // 2
  pinMode(4, OUTPUT); // 3
  pinMode(5, OUTPUT); // 4

  pinMode(6, OUTPUT); // 4

  pinMode(7, OUTPUT); // 6
  pinMode(8, OUTPUT); // 7
  pinMode(9, OUTPUT);
  
      //

 

}


void loop() {
  writeScore(0);
 

  if (BT.available()) {
  

    // signal 1 -> enter play state
    // signal 2 -> time up
    // signal 3 -> play tetris tone
    // signal 4 -> force to standby
    

    

    // receive signal to start
    signal = (BT.read());
    Serial.println(signal);
    if(signal == '1') {
      Serial.println("play state");
      score = 0;

      // generate bool then send key answer
      keyAnswer = generateKeyAnswer();
      if(keyAnswer) BT.println("STARTTRUE");
      else BT.println("STARTFALSE");

      // start game loop
      gameRunning = true;
      timeOver = false;
      readKnock = true;
    }
    
    if(signal == '3') {
       playTetris(129); 
       signal = 0;
    }
    while(gameRunning) {
      // read timeOver
      signal = (BT.read());
      if(signal == '2') {
        Serial.println(signal);
        timeOver = true;
      }

      if(signal == '4') {
        gameRunning = false;
      }

      if(!timeOver) {
        bool answer;
        
        if(readKnock) {
          // read knock
          
          trueKnock = analogRead(trueKnockSensor);
          falseKnock = analogRead(falseKnockSensor);

          if(trueKnock >= THRESHOLD) {
            buzz();
            buzz();
            answer = true;
            readKnock = false;
            }

          if(falseKnock >= THRESHOLD) {
            buzz();
            buzz();
            answer = false;
            readKnock = false;
          }
        }
        else {
          // compare knock if get hit
          compareKnockToAnswer(answer);
          readKnock = true;
        }
      } 
      else {
        gameOver = true;
        gameRunning = false;
      }   
    }

    if(gameOver) {
      //game over here
      //playUnderworldMario();
      gameOver = false;
    }
  }

}




