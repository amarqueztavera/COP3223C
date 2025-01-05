// Andrea Marquez Tavera
// Dr. Steinberg
// COP3223C Section 1
// Small Program 5

#include <stdio.h>// preprocessor directive
#include <ctype.h>// standard library

void change(double *paid, double *due);// problem 1 function prototype
void resterauntReceipt();// problem 2 function prototype
void gradeDistribution();// problem 3 function prototype
void incementUpdate(int *val);// problem 4 function prototype

int main()// main fuction
{
    // problem 1
    // variables for user to input the numbers needed to make the math for the change back
    double amtDue;
    double amtPaid;
    // pointers that point to the address of said variables, needed for function change
    double *due = &amtDue;
    double *paid = &amtPaid;
    // takes input from user
    printf("Amount Due: ");
    scanf("%lf", &amtDue);
    printf("Amount Paid: ");
    scanf("%lf", &amtPaid);

    change(paid, due);// call user defined function for problem 1

    //-------------------------------------------------------------------------------------------
    // problem 2
    resterauntReceipt();// call user defined function for problem 2

    //-------------------------------------------------------------------------------------------
    // problem 3
    gradeDistribution();// call user defined function for problem 3

    //-------------------------------------------------------------------------------------------
    // problem 4
    // starts variable value to be 0 so it can increment by one each time
    int value = 0;
    // pointer for function incrementUpdate that points to the address of value
    int *valueptr = &value;

    // displays value of variable value before incrementUodate is called begins
    printf("Before calling incrementUpdate\n");
    printf("val = %d\n", value);

    incementUpdate(valueptr);// call user defined function for problem 4

    // displays value of variable value after incrementUpdate was called 
    printf("After calling incrementUpdate\n");
    printf("val = %d\n", value);

    return 0;// function terminator
}

//-------------------------------------------------------------------------------------------
// problem 1 user defined function
void change(double *paid, double *due)
{
    // variable to keep track of each change category
    int dollars = 0;
    int quarters = 0;
    int dimes = 0;
    int nickles = 0;
    int pennies = 0;

    double change = *paid - *due; // math for how much change is supposed to be given

    // as long as change is greater than 0, determine each category of coins/dollars should be given back
    if(change > 0)
    {
        // while change is greater than $1.00, count one dollar and subtract it to keep counting the rest of the options
        while(change >= 1) {
            dollars++;
            change--;
        }
        // while change is greater than $0.25, count one quarter and subtract it to keep counting the rest of the options
        while(change >= .25){
            quarters++;
            change -= .25;
            change += .00025;
        }
        // while change is greater than $0.10, count one dime and subtract it to keep counting the rest of the options
        while(change >= .10){
            dimes++;
            change -= .1;
            change += .00025;
        }
        // while change is greater than $0.05, count one nickle and subtract it to keep counting the rest of the options
        while(change >= .05){
            nickles++;
            change -= .05;
            change += .00025;
        }
        // while change is greater than $0.01, count one penny and subtract it to keep counting the rest of the options
        while(change >= .01){
            pennies++;
            change -= 0.01;
            change += .00025;
        }
    }

    // display how many of each category are in the change 
    printf("Change\n");
    printf("%d dollars\n", dollars);
    printf("%d quarters\n", quarters);
    printf("%d dimes\n", dimes);
    printf("%d nickels\n", nickles);
    printf("%d pennies\n", pennies);
    
}

//-------------------------------------------------------------------------------------------
// problem 2 user defined function
void resterauntReceipt()
{
    FILE *filePtr;
    int trigger = 1;// trigger for while loop so it keeps going until the user ends the order
    int order;// variable to determine what to add to the receipt based on user's choice
    double total;// variable to determine how much in total was the order

    // variables to keep count of how many of each category was ordered
    int regular = 0;
    int special = 0;
    int cheese = 0;
    int fries = 0;
    int salad = 0;
    int softDrink = 0;

    printf("Welcome to Bob's Burgers! Our burger of the day is Say Cheese Burger!\n");

    while(trigger != 0)// while loop keeps asking user to order until they specify they are done
    {
        // menu for user to pick
        printf("Please enter your order by selecting the option number. Otherwise type 0 and your order receipt will be printed.\n");
        printf("-----------------------\n");
        printf("1: Regular	$5.00\n");
        printf("2: Special	$5.95\n");
        printf("3: Cheese	$5.50\n");
        printf("4: Fries	$2.00\n");
        printf("5: Salad	$2.50\n");
        printf("6: Soft Drink	$2.00\n");
        printf("-----------------------\n");
        printf("What will you add to your order: ");
        scanf("%d", &order);// takes user's order

        switch(order)// keeps count of appropriate user's order
        {
            case 0:// if user exits the while loop will end
                printf("Order is now placed. Printing receipt.\n");
                trigger--;
                break;
            case 1:
                regular++;
                total += 5.00;
                printf("Adding regular to your order.\n");
                break;
            case 2: 
                special++;
                total += 5.95;
                printf("Adding special to your order.\n");
                break;
            case 3:
                cheese++;
                total += 5.50;
                printf("Adding cheese to your order.\n");
                break;
            case 4:
                fries++;
                total += 2.00;
                printf("Adding fries to your order.\n");
                break;
            case 5:
                salad++;
                total += 2.50;
                printf("Adding salad to your order.\n");
                break;
            case 6:
                softDrink++;
                total += 2.00;
                printf("Adding soft drink to your order.\n");
                break;
            default:// if user inputs any other option it will print that is not an available option
                printf("That is not an available option.\n");
                break;
        }        
    }
    
    filePtr = fopen("myreceipt.txt", "w");// makes a new file named myreceipt
    // prints the receipt from the count of the user's orders
    fprintf(filePtr, "Bob's Burgers Restaurant Receipt Order\n");
    fprintf(filePtr, "-----------------------\n");
    fprintf(filePtr, "%d Regular(s)\n", regular);
    fprintf(filePtr, "%d Special(s)\n", special);
    fprintf(filePtr, "%d Cheese(s)\n", cheese);
    fprintf(filePtr, "%d Fries\n", fries);
    fprintf(filePtr, "%d Salad(s)\n", salad);
    fprintf(filePtr, "%d Soft Drink(s)\n", softDrink);
    fprintf(filePtr, "-----------------------\n");
    fprintf(filePtr, "Total: $%0.2f\n", total);// prints total money due from user's order
    fprintf(filePtr, "Thank you and come again!\n");
    fclose(filePtr);// closes file
}

//-------------------------------------------------------------------------------------------
// problem 3 user defined function
void gradeDistribution()
{
    FILE *gradePtr;

    char test;// variable to check file for each letter grade on file

    // variables to keep count of each letter grade
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;
    int dCount = 0;
    int fCount = 0;

    gradePtr = fopen("grades.txt", "r");// opens file named grades

    // checks to see if file exists 
    if(gradePtr == NULL)
        printf("File did not open successfully!\n");
    else// if file exists, then as long as the file can be scanned keep counting, otherwise (when it is -1) stop
    {
        while(fscanf(gradePtr, " %c", &test) != -1)
        {
            switch(test)
            {
                case 'A':
                case 'a':
                    aCount++;
                    break;
                case 'B':
                case 'b':
                    bCount++;
                    break;
                case 'C':
                case 'c':
                    cCount++;
                    break;
                case 'D':
                case 'd':
                    dCount++;
                    break;
                case 'F':
                case 'f':
                    fCount++;
                    break;
            }
        }

        // displays grade count from file
        printf("Here is the grade distribution.\n");
        printf("A: %d\n", aCount);
        printf("B: %d\n", bCount);
        printf("C: %d\n", cCount);
        printf("D: %d\n", dCount);
        printf("F: %d\n", fCount);
    }

    fclose(gradePtr);// closes file
}

//-------------------------------------------------------------------------------------------
// problem 4 user defined function
void incementUpdate(int *val)
{
    // checks user's input to know if the program should terminate or not, made as a char so if user inputs something that is not a number the program doesn't have an infinite loop
    char userInput;

    // trigger for while loop to continue until user picks anything other than 0
    int trigger = 1;

    *val += 1;// initial increment since the program was called
    while(trigger != 0)
    {
        printf("Updating val now...\n");
        printf("Would you like to update ...\n");
        printf("Enter 0 if you would like to update again. Anything else will exit the update.\n");
        printf("Option: ");
        scanf(" %c", &userInput);// takes user's input to check if the program should continue or not

        if(userInput == '0')// if user inputs zero, then continue
        {
            *val += 1;
        }
        else// if user picks anything excpet 0 then the program ends
        {
            printf("val is now done updating...\n");
            trigger--;// decreases trigger so that the while loop ends
        }
    }

}