/*
 * This function will run during SETUP and/or after completing the current game. 
 * It will generate a random correctAnswer array,
 * then check to see if that answer is valid.
 */

//============================================================//
//============== CREATE ANSWER ===============================//
//============================================================//

void createAnswer(){

  validAnswer = true;                                           // assume that the function will write a valid answer

  Serial.println("Generating answer...");

/*
 * Actual Answer Generation
 */

  for (int x=0; x<answerLength; x++){                           // for each place in the desired answerLength...
    correctAnswer[x] = random(1,numberOfButtons+1);             // write a random number b/n 1 & the numberOfButtons
  }

/*
 * Check that each button is used.
 */
 
  for (int button = 1; button <= numberOfButtons; button++){    // for each button...
    bool buttonIsUsed = false;                                  // assume it is not used
    for (int place = 0; place < answerLength; place++){         // for each place in the correctAnswer...
      if (button == correctAnswer[place]){                      // check if it corresponds to that button...
        buttonIsUsed = true;                                    // and raise that flag
      }
    }
    if (!buttonIsUsed){                                         // if that button wasn't used...
      validAnswer = false;                                      // this answer in not valid
    }
  }

/*
 * Check if any button is used twice in a row.
 */

  for (int place = 1; place < answerLength; place++){           // for each place in the answerLength...
    if (correctAnswer[place] == correctAnswer[place-1]){        // if that is the same as the previous...
      validAnswer = false;                                      // this answer in not valid
    }
  }

  if (validAnswer){                                             // if the answer is valid, communicate that to the monitor
    Serial.println("Answer generated");
    Serial.print("Correct Answer is: ");
      for (int x=0; x<answerLength; x++){
        Serial.print(correctAnswer[x]);
      }
    Serial.println();
  }
}
