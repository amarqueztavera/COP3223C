//Andrea Marquez Tavera
//Dr. Steinberg
//COP3223C Section 1
//Large Program 3

#include <stdio.h>// preprocessor directive
#include <ctype.h>// standard library
#include <string.h>// string library
#define STRIKES 6// defines maximum strikes as 6
#define SIZE 20// defines maximum character count of each word as 20

void rules(void); //display rules of the game
void maskWord (char starword[], int size); //mask the word with stars to display
int playRound(char starword[], char answer[]); //play a round of hangman
int occurancesInWord(char userguess, char answer[]); //number of times letter occurs in word
void updateStarWord(char starword[], char answer[], char userguess); //replace respective * 
void playAgain(int *play); //ask user if to play again. 1 is yes 2 is no

int main()
{
    printf("Welcome to the Hangman Game!\n");// welcomes user
    printf("In case you haven't played this before:\n");
    rules();// calls rules user-defined function to display rules

    FILE *wordsPtr;// creates file pointer
    char wordTest[SIZE];// string to test file
    char copied[SIZE];// string to copy original word to alter it into asterisks 
    int play;// integer for playAgain function

    wordsPtr = fopen("words.txt", "r");// opens file
    if(wordsPtr == NULL)// if file cannot be found, print that
        printf("File did not open successfully! Goodbye :)\n");
    else// otherwise continue the game
    {
        while(fscanf(wordsPtr, "%s", wordTest) != -1)// as long as the file can read a line (aka a word for the game), keep playing
        {
            strcpy(copied, wordTest);// copy original word from file into another string so the original is not changed
            int length = strlen(copied);// find the length of characters of the word in the new string
            maskWord(copied, length);// call maskWord function, aka switch each character into a star
            printf("Welcome to the Round!\n");// begins visual display of round
            printf("The word has %d letters.\n\n", length);// shows how long the word is
            int playResult = playRound(copied, wordTest);// declares and initializes playRound function, number will determine if user wins round or not
            if(playResult == 1)// if user wins round, display so and ask if they want to play another round
            {
                printf("\nCongratulations! You won! The word was indeed %s\n", wordTest);
                playAgain(&play);// asks if they want to play again using playAgain function
            }
            else if(playResult == 0)// is user loses round, display so and ask if they want to play again
            {
                printf("************************************************************************\n");
                printf("Sorry, it appears that you have lost this round. The word was actually %s.\n", wordTest);// displays correct word
                playAgain(&play);// asks if they want to play again using playAgain function
            }
            if(play == 2)// if they choose to not keep playing, thank them for playing and stop the loop
            {
                printf("Thank you for playing! Come back whenever. Goodbye!\n");
                break;// stops while loop
            }
        }
        if(fscanf(wordsPtr, "%s", wordTest) == -1)// when there is no more words, tell them the game is done
        {
            printf("Thank you for playing today, there are no more words to play with!\n");
        }
    }

    fclose(wordsPtr);// closes file

    return 0;// function terminato
}

void rules(void)// displays rules
{
    printf("************************************************************************\n");
    printf("Here are the rules.\n");
    printf("I will provide you a set of * characters for each round.\n");
    printf("Each * represents a letter in the English Alphabet.\n");
    printf("You must figure out each letter of the missing word.\n");
    printf("For every correct letter guessed, I will reveal its place in the word.\n");
    printf("Each mistake will result in a strike.\n");
    printf("6 strikes will result in a loss that round.\n");
    printf("Are you ready? Here we go!\n");
    printf("************************************************************************\n");
}

void maskWord (char starword[], int size)
{
    for(int index = 0; index < size; index++)// goes through each character in the new string and changes them into *'s
    {
        starword[index] = '*';
    }
}

int playRound(char starword[], char answer[])
{
    char guessed;// used to store user's guess 
    char allGuessed[SIZE] = " ";// string to display all characters that have been guessed
    int length = strlen(starword);// finds length of word
    int CurrentStrikes = 0;// counter to know how many strikes the user has at a particular round
    
    while(CurrentStrikes < STRIKES)// as long as user didn't guess incorrectly 6 times, keep playing
    {
        if(strcmp(starword, answer) != 0)// as long as user didn't guess the whole word correctly, keep playing
        {
            printf("You currently have %d strike(s)\n", CurrentStrikes);// displays how many strikes user has
            printf("Letter(s) you have guessed thus far:%s\n\n", allGuessed);// displays which letter the user has guessed

            printf("%s\n\n", starword);// displays the hidden word that updates as the user correctly guesses

            printf("Enter your guess, please: ");// asks user to enter a character to guess
            scanf(" %c", &guessed);// stores user's character

            if(isalpha(guessed) == 0)// if the user did not input a letter, tell them that was not valid
            {
                printf("\nThat is not a letter in the alphabet :(\n\n");
            }
            else// otherwise, keep playing
            {
                char testGuess = tolower(guessed);// converts character to lower case
                int howMany = occurancesInWord(testGuess, answer);// declares and initializes occurancesInWord function
                int counter = 0;// counter to keep track of whether or not the user's guess has is already in the string that displays how all the letters (prevents duplicates from showing on the display and from being stored in the string)
                int repeatedWrong = 0;// counter to keep track of whether or not the wrong guess was already guessed before so no multiple strikes are counted for the same wrong guess

                if(howMany == 1)// if user's guess is a correct guess (aka is in the answer key)
                {
                    for(int index = 0; index < strlen(allGuessed); index++)// checks every character in the mass guesses string
                    {   
                        if(allGuessed[index] == testGuess)// if a character in the mass guess string is the same as the current guess, increase counter by one and tell them they already guessed it
                        {
                            printf("\nYou already guessed this!\n");
                            counter++;
                        }
                    }
                    if(counter == 0)// as long as the guess was not already guessed, add the guess to the guesses string
                        strncat(allGuessed, &testGuess, 1);
                
                    updateStarWord(starword, answer, testGuess);// changes the displayed starword to an updated version, meaning if the guess was correct the display will reveal it in the correct position
                    if(strcmp(starword, answer) != 0)// if the word is still not 100% guessed, display that the letter guessed was in the world. This is simply for easier visibilty for the user
                    {
                        printf("\nThe letter %c is in the word.\n\n", testGuess);
                    }
                }
                else if(howMany == 0)// if the guess was incorrect
                {
                    printf("\nThe letter %c is NOT in the word.\n\n", testGuess);// display that the guess was incorrect

                    if(strchr(allGuessed, testGuess) != NULL)// if the incorrect guess was already guessed before, add to counter and tell them they already guessed it.
                    {
                        printf("You already guessed this. Don't worry, we won't penalize you again.\n\n");
                        repeatedWrong++;
                    }
                    if(repeatedWrong == 0)// as long as the letter wasn't guessed already, increase strike count. This is so that the user doesn't get penalized for accidentally guessing the wrong letter more than once
                    {
                        CurrentStrikes++;
                    }

                    for(int index = 0; index < strlen(allGuessed); index++)// checks every character in the mass guesses string
                    {   
                        if(allGuessed[index] == testGuess)// if a character in the mass guess string is the same as the current guess, increase counter by one
                        {
                            counter++;
                        }
                    }
                    if(counter == 0)// as long as the guess was not already guessed, add the guess to the guesses string
                    {
                        strncat(allGuessed, &testGuess, 1);
                    }
                }
            }
        }
        else if(strcmp(starword, answer) == 0)// if the word was 100% guessed correctly, return 1, meaning they won the round
        {
            return 1;
        }
    }
    return 0;// if the user got 6 strikes, return 0, meaning they lost the round
}

int occurancesInWord(char userguess, char answer[])
{
    if(strchr(answer, userguess) == NULL)// if the guess did not appear at least once in the word, return 0
        return 0;
    else// otherwise return 1
    {
        return 1;
    }
}

void updateStarWord(char starword[], char answer[], char userguess)
{
    int length = strlen(answer);// find the how many characters the answer key has
    
    for(int index = 0; index < length; index++)// checks for every character in the answer key
    {   
        if(answer[index] == userguess)// if the answer key in a particular index is the same as the guess
        {
            starword[index] = answer[index];// change the respective character in the starword (aka what is being displayed) as the guess, meaning the correct position of the correct guess is being displayed
            
        }
    }
}

void playAgain(int *play)
{
    char choice;// char variable to store user's choice to play or not play again

    // asks user if they'd like to play another round
    printf("************************************************************************\n");
    printf("Would you like to play another round?\n");
    printf("1. Yes, this game is awesome and it took Andrea forever to code so I should keep playing\n");
    printf("2. No, I hate Andrea\n");
    printf("Choice: ");
    scanf(" %c", &choice);// stores user's choice

    if(choice == '1' || choice == '2')// if the user gave a valid option
    {
        if(choice == '1')// if the user chose to continue playing, dereference integer pointer named play back to the main and set it to 1
        {
            *play = 1;
        }
        else if(choice == '2')// if the user chose to NOT continue playing, dereference integer pointer named play back to the main and set it to 2
        {
            *play = 2;
        }
    }
    else// if user inputted any other option, tell them that their input was invalid and assume they want to stop the game
    {
        printf("\nThat is not a valid option. We will assume you want to stop!");
        *play = 2;
    }

    printf("\n************************************************************************\n");
}
