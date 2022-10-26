#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

//get user's option
char getoption() { 
	char option;
	do {
		scanf("%c", &option);
		if (option == '1' || option == '2' || option == '3' || option == 'e' || option == 'm' || option == 'h')
			break;
		printf("Invalid option! Enter 1, 2 or 3.\n");
	} while(1);
	switch(option) {
		case '1':
		case 'e':
			printf("Easy Mode selected!\n");
			break;
		case '2':
		case 'm':
			printf("Medium Mode selected!\n");
			break;
		case '3':
		case 'h':
			printf("Hard Mode selected!\n");
			break;
	}
	return(option);
}

//ask_question method
int ask_question(int min, int max) { 
	int result, operand, num1, num2, ans;
	bool x;
		
	/* This is generating a random number between 1 and 10, and then randomly selecting a math operator. */
	srand(time(NULL));
	char mathOp[] = "-+";
	operand = mathOp[rand() % (sizeof mathOp - 1)];
	num1 = rand() % max + min;
	num2 = rand() % max + min;
	result = num1 - (num2*(operand - 44));
	
	/* This is printing the question and then scanning the user's answer. */
	printf("What is %d %c %d?\t",num1, operand, num2);
	scanf("%d%*c", &ans);

	/* This is checking if the user's answer is correct or not. If it is correct, it will print "Correct!"
	and return true. If it is incorrect, it will print "Incorrect! */
	if (ans == result) {
		printf("Correct!\n\n");
		x = true;}
	else if (ans != result) {
		printf("Incorrect! The correct answer was %d.\n\n", result);
		x = false;}
	return (x);}

//main program
int main() 
{
	/* This is declaring the variables that will be used in the program. */
	int lives, max_num, questions, i, score;
	char c, level;
	float percentage;
	bool a;
	do {
		printf("Welcome to Maths Tester Pro!\n");
		printf("Select a diffiulty level:\n1) Easy\n2) Medium\n3) Hard\n");
			
		level = getoption();
		switch(level) 
		{
			/* The code for the easy mode. */
			case '1':
				lives = 3;
				max_num = 10;
				questions = 5;
				score = 0;
				
				
				/* A for loop that is asking the user questions. It is also checking if the user has any lives
				left. */
				for (i = 1; i <= questions; i++) //for loop
				{
					if (i < questions && lives > 0) {
						printf("Question %d of %d. You have %d lives remaining.\n", i, questions, lives);
						a = ask_question(1,max_num);
						if (a == true) {
							score = score + 1;}
						else {
							lives = lives - 1;}
					}

					if (i == questions && lives > 0) {
						printf("Challenge question!\n");
						printf("Question %d of %d. You have %d lives remaining.\n", i, questions, lives);
						a = ask_question(max_num, max_num*2);
						if (a == true) {
							score = score + 1;}
						else {
							lives = lives - 1;}
					}
					if (i < questions && lives == 0){
						printf("Out of lives, game over!\n");
						break;
					}
				} //end for loop
				
				//calculate part
				printf("Test complete.\n");
				int percentage = (score / 5.0)*100;
				//using ld to return long int when we round off the %
				printf("You scored %d/%d (%ld%c).\n", score, questions, lround(+percentage), '%');
				if(percentage >= 80){
					printf("Your grade is a High Distinction!");}
				else if(percentage >= 70){
					printf("Your grade is a Distinction!");}
				else if(percentage >= 60){
					printf("Your grade is a Credit!");}
				else if(percentage >= 50){
					printf("Your grade is a Pass!");}
				else{
					printf("Your grade is a Fail!");}
				break; //end case 1
	
			
			/* This is the code for the medium mode. It is the same as the code for the easy mode, except that
			the lives, max_num and questions are different. */
			case '2':
				lives = 2;
				max_num = 25;
				questions = 10;
				score = 0;
				
				for (i = 1; i <= questions; i++) 
				{
					if (i < questions && lives > 0) {
						printf("Question %d of %d. You have %d lives remaining.\n", i, questions, lives);
						a = ask_question(1,max_num);
						if (a == true) {
							score = score + 1;}
						else {
							lives = lives - 1;}
					}
					if (i == questions && lives > 0) {
						printf("Challenge question!\n");
						printf("Question %d of %d. You have %d lives remaining.\n", i, questions, lives);
						a = ask_question(max_num, max_num*2);
						if (a == true) {
							score = score + 1;}
						else {
							lives = lives - 1;}
					}
					if (lives == 0){
						printf("Out of lives, game over!\n");
						break;
					}
				}
				
				printf("Test complete.\n");
				percentage = (score / 10.0)*100;
				//using ld to return long int when we round off the %
				/* This is printing the user's score and the percentage they got. It is also printing the user's
				grade. */
				printf("You scored %d/%d (%ld%c).\n", score, questions, lround(+percentage), '%');
				if(percentage >= 80){
					printf("Your grade is a High Distinction!");}
				else if(percentage >= 70){
					printf("Your grade is a Distinction!");}
				else if(percentage >= 60){
					printf("Your grade is a Credit!");}
				else if(percentage >= 50){
					printf("Your grade is a Pass!");}
				else{
					printf("Your grade is a Fail!");}
				break;
	
			
			/* This is the code for the hard mode. It is the same as the code for the easy and medium modes,
			except that the lives, max_num and questions are different. */
			case '3':
				lives = 1;
				max_num = 50;
				questions = 15;
				score = 0;
				
				for (i = 1; i <= questions; i++) 
				{
					if (i < questions && lives > 0) {
						printf("Question %d of %d. You have %d lives remaining.\n", i, questions, lives);
						a = ask_question(1,max_num);
						if (a == true) {
							score = score + 1;}
						else {
							lives = lives - 1;}
					}
					if (i == questions && lives > 0){
						printf("Challenge question!\n");
						printf("Question %d of %d. You have %d lives remaining.\n", i, questions, lives);
						a = ask_question(max_num, max_num*2);
						if (a == true) {
							score = score + 1;}
						else {
							lives = lives - 1;}
					}
					if (i < questions && lives == 0){
						printf("Out of lives, Game over!\n");
						break;
					}
				}
				
				printf("Test complete.\n");
				percentage = (score / 20.0)*100;
				//using ld to return long int when we round off the %
				printf("You scored %d/%d (%ld%c).\n", score, questions, lround(+percentage), '%');
				if(percentage >= 80){
					printf("Your grade is a High Distinction!");}
				else if(percentage >= 70){
					printf("Your grade is a Distinction!");}
				else if(percentage >= 60){
					printf("Your grade is a Credit!");}
				else if(percentage >= 50){
					printf("Your grade is a Pass!");}
				else{
					printf("Your grade is a Fail!");}
				break;
		}
	/* This is asking the user if they want to play again. If they enter 'y', the program will start
	again. If they enter 'n', the program will end. */
	printf("\nDo you want to start again?(y/n): ");
    	scanf("%c",&c);
	} while (c == 'y');
	printf("Thanks for playing. \n");		
	return 0;
}