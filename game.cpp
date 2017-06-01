
//game object
int score = 0; //score
bool leftKnock = false; //left target
bool rightKnock = false; //right target
bool keyAnswer = false;
bool timeOver = false;

String 

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

  // 1. receive signal to start




  while(gameRunning) {

    // 2. generate answer
    answer = generateAnswer();


    
    while(!timeOver) {
      if(timeOver) {
        gameOver = false;
        gameRunning = false;  
      }
      // read knock 

      // compare knock
      compareKnockToAnswer();

    }
      
  }

  if(gameOver) {
    //display gameover
  }

}