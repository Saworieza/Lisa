#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

//defaults
int score = 0;

//get user's choice
char getchoice() { 
	char choice;
	do {
		scanf("%c", &choice);
		if (choice == '1' || choice == '2' || choice == '3')
			break;
		printf("Invalid choice! Enter 1, 2 or 3.\n");
	} while(1);
	switch(choice) {
		case '1':
			printf("Easy Mode selected!\n");
			break;
		case '2':
			printf("Medium Mode selected!\n");
			break;
		case '3':
			printf("Hard Mode selected!\n");
			break;
	}
	return(choice); }

//ask_question function
int ask_question(int min, int max) { 
	int result, operand, num1, num2, ans;
	bool x;
		
	srand(time(NULL));
	char mathSym[] = "-+";
	operand = mathSym[rand() % (sizeof mathSym - 1)];
	num1 = rand() % max + min;
	num2 = rand() % max + min;
	result = num1 - (num2*(operand - 50));
	
	printf("What is %d %c %d?\t",num1, operand, num2);
	scanf("%d%*c", &ans);

	if (ans == result) {
		printf("Correct!\n\n");
		x = true; }
	else if (ans != result) {
		printf("Incorrect! The correct answer was %d.\n\n", result);
		x = false; }
	return (x); }

//calculate percentages
void percentageScore() {
// 	printf("Test complete.\n");
// 	int percentage = (score / 5.0)*100;
// 	//using ld to return long int when we round off the %
// 	// printf("You scored %d/%d (%ld%c).\n", score, questions, lround(+percentage), '%');
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
}

//main program
int main() 
{
	int lives, max_num, questions, i, score;
	char c, difficulty;
	float percentage;
	bool a;
	do {
		printf("Welcome to Maths Tester Pro!\n");
		printf("Select a diffiulty level:\n1) Easy\n2) Medium\n3) Hard\n");
			
		difficulty = getchoice();
		switch(difficulty) 
		{
			case '1':
				lives = 3;
				max_num = 10;
				questions = 5;
				score = 0;
				
				for (i = 1; i <= questions; i ++) //for loop
				{
					if (i < questions && lives > 0) 
					{
						printf("Question %d of %d. You have %d lives remaining.\n", i, questions, lives);
						a = ask_question(1,max_num);
						if (a == true) {
							score = score + 1; }
						else {
							lives = lives - 1; }
					}

					if (i == questions && lives > 0) 
					{
						printf("Challenge question!\n");
						printf("Question %d of %d. You have %d lives remaining.\n", i, questions, lives);
						a = ask_question(max_num, max_num*2);
						if (a == true) {
							score = score + 1; }
						else {
							lives = lives - 1; }
					}
					if (i < questions && lives == 0)
					{
						printf("Out of lives, game over!\n");
						break;
					}
				} //end for loop
				


				// calculate part
				printf("Test complete.\n");
				int percentage = (score / 5.0)*100;
				//using ld to return long int when we round off the %
				printf("You scored %d/%d (%ld%c).\n", score, questions, lround(+percentage), '%');
				percentageScore();
	
			//same as case 1
			case '2':
				lives = 2;
				max_num = 25;
				questions = 10;
				score = 0;
				
				for (i = 1; i <= questions; i ++) 
				{
					if (i < questions && lives > 0) 
					{
						printf("Question %d of %d. You have %d lives remaining.\n", i, questions, lives);
						a = ask_question(1,max_num);
						if (a == true) {
							score = score + 1; }
						else {
							lives = lives - 1; }
					}
					if (i == questions && lives > 0) 
					{
						printf("Challenge question!\n");
						printf("Question %d of %d. You have %d lives remaining.\n", i, questions, lives);
						a = ask_question(max_num, max_num*2);
						if (a == true) {
							score = score + 1; }
						else {
							lives = lives - 1; }
					}
					if (lives == 0)
					{
						printf("Out of lives, game over!\n");
						break;
					}
				}
				
				printf("Test complete.\n");
				percentage = (score / 10.0)*100;
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
	
			//same as case 1
			case '3':
				lives = 1;
				max_num = 50;
				questions = 15;
				score = 0;
				
				for (i = 1; i <= questions; i ++) 
				{
					if (i < questions && lives > 0) 
					{
						printf("Question %d of %d. You have %d lives remaining.\n", i, questions, lives);
						a = ask_question(1,max_num);
						if (a == true) {
							score = score + 1; }
						else {
							lives = lives - 1; }
					}
					if (i == questions && lives > 0) 
					{
						printf("Challenge question!\n");
						printf("Question %d of %d. You have %d lives remaining.\n", i, questions, lives);
						a = ask_question(max_num, max_num*2);
						if (a == true) {
							score = score + 1; }
						else {
							lives = lives - 1; }
					}
					if (i < questions && lives == 0)
					{
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
	printf("\nDo you want to start again?(y/n): ");
    	scanf("%c",&c);
	} while (c == 'y');
	printf("Thanks for playing. \n");		
	return 0;
}