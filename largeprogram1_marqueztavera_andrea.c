//Andrea Marquez Tavera
//Dr. Steinberg
//COP3223C Section 1
//Large Program 1

#define ROUNDS 3 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void greeting(); //display welcome message to user
int playRound(int round); //play one round
int humanPick(); //retrieve the user's guess
int computerPick(int choice, int leftover); //computer makes its pick
int leftOnTable(int toothpicks, int taken); //calculate number of toothpicks left
void winnerAnnouncment(int user); //overall winner of round announcement

int main()
{
	greeting(); //call greeting function to greet user and explain game instructions
	
	//loop to play 3 rounds
	for(int x = 0; x < ROUNDS; ++x)
	{
		int result = playRound(x + 1); //call playRound and assign result the value function returns
		
		winnerAnnouncment(result); //call winnerAnnouncment function to display the winner of each round
	}
	
	printf("********************************************************\n");
	printf("Thank you for playing this super awesome and very complicated game that Dr. Steinberg thinks is easy to code.\n");
	return 0;
}

//displays welcome message to user and explains game instructions
void greeting() 
{
	printf("********************************************************\n");
	printf("Welcome to Toothpick Game!\n");
	printf("Here are the rules.\n");
	printf("There are currently 31 toothpicks on the table.\n");
	printf("You and I will each get a turn to pick either 1, 2, or 3 toothpicks off the table.\n");
	printf("The player that gets to pick the last toothpicks loses the game!\n");
	printf("Sounds easy right? Well lets see if you can beat me!\n");
	printf("Ready to play?...Here we go!\n");
	printf("********************************************************\n");
}

//the logic behind each round
int playRound(int round)
{
	//welcome to a new round from 1 - 3
	printf("Welcome to a new round %d!\n", round);
	printf("You may go first (it's not rigged I promise)!\n");
	
	int toothpicks = 31; //number of toothpicks to start with
	
	int humanpick; //initialize humanpick variable that will call humanPick function later
	int computerpick; //initialize computerpick variable that will call computerPick function later
	int amounttaken = 0; //initialize and declare variable that states how many toothpicks have been taken thus far
	int amountLeftBecauseUser; //initialize variable that will declare how many toothpicks are left after the user chose on their turn

	//loop that keeps track of toothpicks until respective no more toothpicks left. we will learn about conditional loops soon :)
	
	while(toothpicks != 0)
	{
		//display how many toothpicks are on the table
		printf("********************************************************\n");
		printf("There are %d toothpick(s) left on the table.\n", toothpicks);
		humanpick = humanPick(); //calls humanpick function so user can make a move
		//conditions in case user cheats 
		if (humanpick > toothpicks) //if user tries to grab more than available toothpicks
		{
			printf("Oh oh, it looks like you're trying to be sneaky. Why you would try to grab more than the available toothpicks is confusing!\n");
			printf("I'd recommend re-reading the instructions, since you do -not- want to be the last player to make a move. Try again!\n");
			printf("********************************************************\n");
		}
		else if (humanpick > 3) //if user tries to grab more than allowed toothpicks
		{
			printf("Oh no, it looks like you're trying to be sneaky. It hurts my feelings that you'd try to grab more than allowed. Try again!\n");
			printf("********************************************************\n");
		}
		else //if user plays properly
		{
			printf("Ok... you took %d off the table.\n", humanpick); //shows how many toothpicks were taken
			amountLeftBecauseUser = leftOnTable(toothpicks, humanpick); //calls leftOnTable function to know how many toothpicks left after the user's turn
			
			//conditions in case game is over
			if (amountLeftBecauseUser <= 0) //if game over, stop
			{
				return 0;
			}
			else if (amountLeftBecauseUser > 0) //if game not over, keep playing
			{
				computerpick = computerPick(humanpick, amountLeftBecauseUser); //calls computerPick function to know how many toothpicks the computer took
				printf("I am taking %d toothpick(s) off the table.\n", computerpick);
		
				amounttaken = humanpick + computerpick; //adds up how many toothpicks were taken by both the computer and the user on one play
				toothpicks = leftOnTable(toothpicks, amounttaken); //declares how many toothpicks are left overall
			}
		}
		//return 0; //terminates loop HOWEVER YOU WILL NEED TO CHANGE THIS WHEN BUILDING YOUR PROGRAM. THIS WAS PUT IN THE SKELETON SO THAT THE INITIAL RUN ISN'T STUCK IN AN INFINITE LOOP
	}

	//conditions for winner
	if (computerpick == 1) //human wins
	{
		return 1;
	}
	else //computer wins
	{
		return -1;
	}
	//return 0; //returns 0 HOWEVER YOU WILL NEED TO CHANGE THIS PART OF THE CODE TO MAKE THE PROGRAM WORK PROPERLY! YOU DON'T WANT THE SAME VALUE RETURNED ALWAYS
}

//asks user to choose how many toothpicks to pick in a particular play
int humanPick()
{
	int userChoice;

	printf("How many toothpicks are you going to take off the table? "); 
	scanf("%d", &userChoice);
	
	return userChoice;
}

//logic for computer to determine how many toothpicks it'll take depending on humanpick results
int computerPick(int choice, int leftover) //choice == user amount, leftover == how many toothpicks are left
{
	printf("I'm making my decision now.\n");

	int computerChoice;
	
	if (leftover > 4) //if there are more than 4 toothpicks left, will choose 4 - user's choice
		computerChoice = 4 - choice;
	else if (leftover >= 2) //if there are 2 - 4 (inclusive) toothpicks left, will leave 1
		computerChoice = leftover - 1;
	else //if there's only one left, computer will have to pick one therefore losing
		computerChoice = 1;
	
	return computerChoice;
}

//subtracts parameters to determine how many toothpicks are left on the table
int leftOnTable(int toothpicks, int taken) 
{
	int amountLeft = toothpicks - taken;
	return amountLeft;
}

//determines winner through what playRound function returns
void winnerAnnouncment(int user)
{
	if (user == 1)
		printf("You won... yay...\n");
	else
		printf("I won! You must be embarassed!\n");
}