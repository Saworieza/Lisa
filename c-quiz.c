#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int min_lower=1, min_upper=10, count=10, max_lower=10, max_upper=100;
char operands [][100]={
 "+","-","*","/"
};

void minimum(){
 srand(time(0));
 int min_num = (rand() % (min_upper-min_lower+1)+min_lower);
 printf("%d ", min_num);
}

void maximum(){
 srand(time(0));
 int max_num = (rand() % (max_num - max_lower+1) + max_lower);
 printf("%d", max_num);
}

int main() {
    //introduce option
    char option;
    char easy_questions[][100] ={
      "1. What is 5 - 3?.",
      "2. What is 5 + 4?",
      "3. What is 6 - 2?"
    };
    char easy_answers[3] = {'2','9','4'};
    // calculate number of questions that we have
    int numberOfQuestions = sizeof(easy_questions)/sizeof(easy_questions[0]);
    // store guess
    char guess;
    // track score
    int score, grade;


    printf("Welcome To Maths Tester Pro. \n Select a Difficulty.\n ");
    //select options
    printf("1. Easy\n ");
    printf("2. Medium\n ");
    printf("3. Hard \n");
    printf(">  ");
    
    //get choice from user
    option=getchar();
    
    switch(option){
      case '1':
        printf("Easy Mode Selected \n");
        for(int i=0; i < numberOfQuestions; i++){
          printf("%s ", easy_questions[i]);
          printf("You have 3 lives remaining \n");
          printf("Answer: ");
          scanf("%c", &guess);
          while ((getchar()) != '\n'); // clear \n from input buffer

          //check if answer is correct
          if (guess==easy_answers[i]){
            printf("Correct! \n");
            score++;
          } else {
            printf("Wrong \n");
          }
        };

        //display user score
        printf("Test Complete \nYou Scored %d/%d \n", score, numberOfQuestions);
      break;

      case '2':
        printf("Medium Mode Selected \n");
      break;

      case '3':
        printf("Hard Mode Selected \n");
      break;

      default:
       printf("Your Selection is Incorrect \n");

      break;
    }

    return 0;
}