// Andrea Marquez Tavera
// Dr. Steinberg
// COP3223C Section 1
// Small Program 4

#include <stdio.h> // preprocessor directive
#include <ctype.h> // standard library

void perfectSquare();// problem 1 function prototype
void elevator();// problem 2 function prototype
void pyramid();// problem 3 function prototype
double classAvg(int students);// problem 4 function prototype

int main() // main fuction
{
    // problem 1
    perfectSquare();// call user defined function for problem 1

    //-------------------------------------------------------------------------------------------
    // problem 2
    elevator();// call user defined function for problem 2

    //-------------------------------------------------------------------------------------------
    // problem 3
    pyramid();// call user defined function for problem 3

    //-------------------------------------------------------------------------------------------
    // problem 4
    int studentamount;// used to call classAvg function
    int looptrigger = 1;// used to keep asking until valid amount of students have been entered

    while(looptrigger != 0)
    {
        printf("How many students are in the class: ");
        scanf("%d", &studentamount);
        
        if(studentamount <= 0)// if the amount of students are not valid, try again
        {
            printf("Invalid input. Please try again.\n");
        }
        else// if amount of students is valid, calculate the average and print it
        {
            double amount = classAvg(studentamount);
            printf("The class average on the field trip exam was a %0.4f%%\n", amount);
            looptrigger--;// ends loop since the wanted information has been printed
        }
    }

    return 0; // function terminator
}

//-------------------------------------------------------------------------------------------
// problem 1 user defined function
void perfectSquare()
{
    int looptrigger = 1;// used to keep asking until valid amount of square size has been entered
    int size;

    while(looptrigger !=0)
    {
        printf("How big would you like the square to be?: ");
        scanf("%d", &size); 

        if (size <= 0)// if the size of the square is not valid, try again
        {
            printf("Invalid Input. Please try again.\n");
        }
        else// if size of square is valid, print the square
        {
            for(int top = 1; top <= size; top++)// prints the width of the square at the top
            {
                printf("*");
            }
            printf("\n");

            for(int height = 1; height <= size - 2; height++)// prints the height of the square on the left side
            {
                printf("*");

                for(int spacebetween = 0; spacebetween <= size - 3; spacebetween++)// prints the spaces between the left and right border of the square
                {
                    printf(" ");
                    
                }
                printf("*\n");// prints the right border of the square
            }
            for(int bottom = 1; bottom <= size; bottom++)// prints the width of the bottom of the square
            {
                printf("*");
            }
            printf("\n");
            looptrigger--;// ends the loop since the square has been successfully printed
        }
    }
}

//-------------------------------------------------------------------------------------------
// problem 2 user defined function
void elevator()
{
    // inputs + menu for problem 2 
    int looptrigger = 1;// used to keep asking until valid floor number has been entered
    int floor;

    printf("Welcome to the Elevator Ride.\n");// welcomes user to the elevator function/ride

    while(looptrigger != 0)
    {
        printf("Which floor would you like to go to? ");
        scanf("%d", &floor);

        if(floor <= 0 || floor > 12)// if user inputs invalid floor option, try again
        {
            printf("That is not a valid option.\n");
        }
        else// if user inputs valid floor option, switch statement tests to give proper print statement
        {
            switch(floor)// checks user's floor input to print proper print statment over and over until they choose floor five
            {
                case 1:
                    printf("Welcome to the first floor.\n");
                    break;
                case 2:
                    printf("Welcome to the second floor.\n");
                    break;
                case 3:
                    printf("Welcome to the third floor.\n");
                    break;
                case 4:
                    printf("Welcome to the fourth floor.\n");
                    break;
                case 5:
                    printf("Elevator door is now open. Please exit now.\n");
                    looptrigger--;// since they chose floor five, the function is over so the loop is broken so it doesn't keep asking for a floor
                    break;
                case 6:
                    printf("Welcome to the sixth floor.\n");
                    break;
                case 7:
                    printf("Welcome to the seventh floor.\n");
                    break;
                case 8:
                    printf("Welcome to the eighth floor.\n");
                    break;  
                case 9:
                    printf("Welcome to the ninth floor.\n");
                    break;
                case 10:
                    printf("Welcome to the tenth floor.\n");
                    break;
                case 11:
                    printf("Welcome to the eleventh floor.\n");
                    break;
                case 12:
                    printf("Welcome to the twelfth floor.\n");
                    break;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------
// problem 3 user defined function
void pyramid()
{   
    int steps;
    int looptrigger = 1;// used to keep asking until valid amount of steps for the pyramid is entered

    while(looptrigger != 0)
    {
        printf("How many steps would you like in the pyramid? ");
        scanf("%d", &steps);
        
        if(steps <= 0)// if the amount of steps in the pyramid is invalid, try again
        {
            printf("Invalid Input. Please try again.\n");
        }
        else// if the amount of steps in the pyramid is valid, prints pyramid picture
        {
            for(int image = 1; image <= steps; image++)// prints each line of the top part of the pyramid 
            {
                for (int top = image; top <= image && top > 0; top--) 
                {
                    printf("-");
                }
                printf("\n");
            }
            for(int image = steps - 1; image > 0; image--)// prints each line of the bottom part of the pyramid
            {
                for (int bottom = image; bottom <= image && bottom > 0; bottom--)
                {
                    printf("-");
                }
                printf("\n");
            }
            looptrigger--;// since the pyramid was successfully printed, ends loop so that it wont ask again
        }
    }
}

//-------------------------------------------------------------------------------------------
// problem 4 user defined function
double classAvg(int students)
{
    double scores = 0;
    double check;
    int classsize = students;// since the student variable will be altered in the while loop, this is for the average math calculations

    while(students > 0)// if students are more than 0, keep asking for scores for the average
    {
        printf("Enter the student's test score: ");
        scanf("%lf", &check);

        if(check < 0 || check > 100)// if the score given is not valid, try again
            printf("Invalid Student Score. Please try again.\n");
        else// if score given is valid, add the score to a mass score variable
        {   
            scores += check;
            students--;// decrease the number of students by one to keep asking for scores until there are no students left
        }
    }

    double average = scores / classsize;// calculates class test score average
    
    return average;// returns the average to the main so it can be printed
}