// Andrea Marquez Tavera
// Dr. Steinberg
// COP3223C Section 1
// Small Program 3

#include <stdio.h> // preprocessor directive
#include <ctype.h> // standard library

void letters();// problem 1 function prototype
void greenLawyer();// problem 2 function prototype
void coordinates(double x, double y);// problem 3 function prototype
int triangle(int a, int b, int c);// problem 4 function prototype

int main() // main fuction
{
    // problem 1
    letters();// call user defined function for problem 1

    //-------------------------------------------------------------------------------------------
    // problem 2
    greenLawyer();// call user defined function for problem 2

    //-------------------------------------------------------------------------------------------
    // problem 3
    // inputs for problem 3
    double x;
    double y;
    printf("Enter the x-coordinate: ");
    scanf("%lf", &x);
    printf("Enter the y-coordinate: ");
    scanf("%lf", &y);

    coordinates(x, y);// call user defined function for problem 3

    //-------------------------------------------------------------------------------------------
    // problem 4
    int a;
    int b;
    int c;
    printf("Enter three sides separated by a whitespace: ");
    scanf("%d%d%d", &a, &b, &c);
    int tri = triangle(a, b, c);

    if (tri == 1)
        printf("Triangle!\n");
    else
        printf("Not Triangle!\n");

    return 0; // function terminator
}

//-------------------------------------------------------------------------------------------
// problem 1 user defined function
void letters()
{
    // inputs for problem 1
    char ltr;
    
    printf("Enter a key from the keyboard: ");
    scanf(" %c", &ltr);

    // logic for output for problem 1
    if (islower(ltr))
        printf("Lower!\n");
    else if (isupper(ltr))
        printf("Upper!\n");
    else if (!(isalpha(ltr)))
        printf("Not a Letter!\n");
}

//-------------------------------------------------------------------------------------------
// problem 2 user defined function
void greenLawyer()
{
    // inputs + menu for problem 2 
    int selection;
    printf("Hi! Thank you for calling the Superhuman Law Division at GLK&H!\n");
    printf("Our associates are currently working hard for super people like you.\n");
    printf("Please listen carefully to the options of who you would like to speak to in regards to your situation.\n");
    printf("Option 1: Fined for thousands of dollars worth of damage to the city you were trying to protect.\n");
    printf("Option 2: Accidentally create a sentient robot who got the feels and tried to destroy the world.\n");
    printf("Option 3: You are an Asgardian god who unintentionally leaves a giant burning imprint on private\nproperty every time you visit Earth.\n");
    printf("Option 4: You just gained new superhero strength that is not recognized by the department of\ndamage control, and they are chasing you down after you performed a good deed.\n");
    printf("Option 5: Your secret identity was revealed by a notorious person and now your personal life\nis no longer the same.\n");
    printf("Option 6: Another super being issue that was not mentioned previously in the options given.\n");
    printf("Selection: ");
    scanf("%d", &selection);

    // logic for output for problem 2
    switch(selection) 
    {
        case 1:
            printf("You have selected option 1. Do not worry! I will make sure you don't give up that green.\n");
            break;
        case 2:
            printf("You have selected option 2. Do not worry! You probably had a good intention that just didn't work out properly.\n");
            break;
        case 3:
            printf("You have selected option 3. Do not worry! I understand you like to make a grand entrance.\n");
            break;
        case 4:
            printf("You have selected option 4. Do not worry! We will talk to the department of damage control.\n");
            break;
        case 5:
            printf("You have selected option 5. Do not worry! We will make sure that you are protected. Please be cautious if you decide to seek Dr. Strange's help.\n");
            break;
        case 6:
            printf("You have selected option 6. Do not worry! I will make sure to use my superhero mind to solve your super problem!\n");
            break;
        default:
            printf("I'm sorry. I don't recognize that super being option.\n");
    }
}

//-------------------------------------------------------------------------------------------
// problem 3 user defined function
void coordinates(double x, double y)
{
    if ((x > 0) && (y > 0) )
        printf("(%0.2f, %0.2f) is in quadrant I.\n", x, y);
    else if ((x < 0) && (y > 0))
        printf("(%0.2f, %0.2f) is in quadrant II.\n", x, y);
    else if ((x < 0) && (y < 0))
        printf("(%0.2f, %0.2f) is in quadrant III.\n", x, y);
    else if ((x > 0) && (y < 0))
        printf("(%0.2f, %0.2f) is in quadrant IV.\n", x, y);
    else
        printf("(%0.2f, %0.2f) is in the origin or in an axis.\n", x, y);
}

//-------------------------------------------------------------------------------------------
// problem 4 user defined function
int triangle(int a, int b, int c)
{
    printf("Checking these logistics from the input.\n");
    printf("%d + %d > %d\n", a, b, c);
    printf("%d + %d > %d\n", a, c, b);
    printf("%d + %d > %d\n", b, c, a);
    if ((a + b > c) && (a + c > b) && (b + c > a))
        return 1;
    else
        return -1;
}