
//game object
int score = 0; //score
bool leftKnock = false; //left target
bool rightKnock = false; //right target
bool keyAnswer = false;
bool timeOver = false;

char receivedChars[10]; 

//game engine
bool gameRunning = false;
bool gameOver = false;

//generate answer
bool generateKeyAnswer() {
  int rnd = random(1, 7) // random 1 - 6
  if(rnd > 3) return true; // 4, 5, 6 -> true
  else return false; // 1, 2, 3 -> false
}

compareKnockToAnswer() {
  if(answer == keyAnswer) {
    // add score
    score += 1;
  } else {
    gameRunning = false;
    gameOver = true;
  }
}


void setup() {

}

void loop() {

  // receive signal to start


  while(gameRunning) {

    // generate answer
    answer = generateAnswer();

    // send answer


    // read timeOver

    
    if(!timeOver) {

      // read knock 

      // compare knock
      compareKnockToAnswer();

    } else {
      gameOver = true;
      gameRunning = false;  
    }
      
  }

  if(gameOver) {
    // send gameover

    // send score

    score = 0;
    timeOver = false;

  }

}