//Andrea Marquez Tavera
//Dr. Steinberg
//COP3223C Section 1
//Large Program 2

#include <stdio.h> // preprocessor directive

void greeting(); //welcome the user
void order(double *balance); //user will make a purchase
void viewHand(double *balance); //display current amount in hand
void transaction(double *balance, double price); //transaction with user
void pullMoney(double *balance); //grab more money from the unlimited wallet
void displayVendingOptions(); //display beverage options and prices

int main() // main function
{

    greeting(); //call greeting function to greet user and explain game instructions

    char menuChoice; //To determine what to print depending on the user's choice in the main menu
    int trigger = 1; //Used to keep the while loop going and eventually stop once user exits the vending machine
    double inHand = 0.00; //the amount of money in user's hand, initiall $0.00
    double *balanceptr = &inHand; //pointer to reference user's money in hand 

    do //do-while loop since the menu must be shown at least once
    {   
        //menu for user to select, will loop indefinitely until user chooses to exit
        printf("*****************************************************\n");
        printf("Please select one of the following options!\n");
        printf("O: Order from the very cool, very magical unlimited vending machine.\n");
        printf("V: View what you have in your hand as of this moment.\n");
        printf("D: Display what the very cool, very magical unlimited vending machine contains.\n");
        printf("G: Grab money out of your very cool, very magical unlimited wallet\n");
        printf("E: Exit... where there is no magic...or unlimited money... or unlimited drinks... did I say unlimited?\n");
        printf("*****************************************************\n");

        printf("My oh my, dear user, what will you choose?\n");
        printf("I shall choose: ");
        scanf(" %c", &menuChoice);

        //used to determine what the user sees depending on user's choice from the menu
        switch(menuChoice)
        {
            case 'O':
            case 'o': 
                //if chosen to order, call order function
                printf("\nAh, so you want to order something from the VERY cool, VERY magical unlimited vending machine.\n");
                order(balanceptr);
                break;
            case 'V':
            case 'v':
                //if chosen to view what is currently on hand, call viewHand function
                printf("\nYou selected to see how much cash you have in your hand currently!\n");
                viewHand(balanceptr);
                break;
            case 'D':
            case 'd':
                //if chosen to display the vending options, call displayVendingOptions function
                printf("\nYou want to view the vending machine huh? Yeah, it is very cool and magical.\n");
                displayVendingOptions();
                break;
            case 'G':
            case 'g':
                //if chosen to pull money from wallet, call pullMoney function
                printf("\nYou have selected to pull more money out of the unlimited wallet, just don't think about inflation.\n");
                pullMoney(balanceptr);
                break;
            case 'E':
            case 'e':
                //if chosen to exit, thank user and show the amount of money currently on hand. 
                printf("\n*****************************************************\n");
                printf("Thank you for visiting the unlimited vending machine!\n");
                printf("You have $%0.2f in your hand. Make sure to put that back into your unlimited wallet.\n", inHand); 
                printf("Have a great day!\n");
                trigger--; //breaks loop since the user exited the program.
                break;
            default:
                //if chosen none of the above options, aka none of the allowed options, display that that is not an option
                printf("\nSorry! That option is not one of the menu options. Please try again.\n");
                break;
        }
    } while (trigger != 0); //continue loop until trigger is 0, this will only happen when user picks 'E' or 'e', aka exit

    return 0; //function terminator 
}

void greeting() //function to welcome the user
{
    printf("Welcome to the Unlimited Vending Machine\n");
    printf("We have an unlimted variety of drinks.\n");
    printf("With your unliminted wallet, you will never run out of cash!\n");
    printf("What would you like to order today?\n");
}

void order(double *balance) //function to let user order from the vending machine
{
    printf("*****************************************************\n");
    displayVendingOptions(); //calls displayVendingOptions function to display the options so user is more easily able to order an option

    int vendingChoice; //used to determine the appropriate output for user's order

    printf("What would you like today?\n");
    printf("Option Selected: ");
    scanf("%d", &vendingChoice);     

    double SPrice = 2.50;
    double CCPrice = 2.50;
    double WPrice = 2.00;
    double GPrice = 3.00;
    double DCPrice = 2.55;
    double FPrice = 2.55;
    double RBPrice = 1.50;
    double DPPrice = 1.55;

    //if user picks an option that is not one displayed on the vending machine, then tell them that is not an option
    if(vendingChoice < 1 || vendingChoice > 8)
    {
        printf("Sorry, that is not one of the options recognized.\n");
        printf("*****************************************************\n");
    }
    else{ //if user picks an acceptable option, continue the appropriate transaction
        switch(vendingChoice) //checks the user's order choice to give appropriate transaction/output
        {
            case 1:
                printf("Sprite has been selected. Total cost is: $%0.2f\n", SPrice);
                transaction(balance, SPrice); //calls transaction output using pointer that tells what money the user has currently on their hand and the price of sprite, as that is what they wanted
                break;
            case 2:
                printf("Coca-Cola has been selected. Total cost is: $%0.2f\n", CCPrice);
                transaction(balance, CCPrice); //calls transaction output using pointer that tells what money the user has currently on their hand and the price of coke, as that is what they wanted
                break;
            case 3:
                printf("Water has been selected. Total cost is: $%0.2f\n", WPrice);
                transaction(balance, WPrice); //calls transaction output using pointer that tells what money the user has currently on their hand and the price of water, as that is what they wanted
                break;
            case 4:
                printf("Gatorade has been selected. Total cost is: $%0.2f\n", GPrice);
                transaction(balance, GPrice); //calls transaction output using pointer that tells what money the user has currently on their hand and the price of gatorade (go knights...), as that is what they wanted
                break;
            case 5:
                printf("Diet Cola has been selected. Total cost is: $%0.2f\n", DCPrice);
                transaction(balance, DCPrice); //calls transaction output using pointer that tells what money the user has currently on their hand and the price of diet coke, as that is what they wanted
                break;
            case 6:
                printf("Fanta has been selected. Total cost is: $%0.2f\n", FPrice);
                transaction(balance, FPrice); //calls transaction output using pointer that tells what money the user has currently on their hand and the price of fanta, as that is what they wanted
                break;
            case 7:
                printf("Root Beer has been selected. Total cost is: $%0.2f\n", RBPrice);
                transaction(balance, RBPrice); //calls transaction output using pointer that tells what money the user has currently on their hand and the price of root beer, as that is what they wanted
                break;
            case 8:
                printf("Dr. Pepper has been selected. Total cost is: $%0.2f\n", DPPrice);
                transaction(balance, DPPrice); //calls transaction output using pointer that tells what money the user has currently on their hand and the price of Dr. pepper, as that is what they wanted
                break;
        }
    }
}

void viewHand(double *balance) //function to display what is cureently in the user's hand
{
    printf("*****************************************************\n");
    printf("You have $%0.2f in your hand currently.\n", *balance);
    printf("*****************************************************\n");
}

void transaction(double *balance, double price) //function to do transaction, aka take the money from the user and return the drink
{
    printf("Beginning Transaction Process.\n");
    int trigger = 1; //trigger so the loop can continue until function has done its job

    do //do-while loop since th transaction must happen at least once, unless the user does not have enough money on hand, in which case the loop will continue
    {
        if (price > *balance) //if user does not have enough money on hand to pay, take more money from wallet
        {
            printf("You do not have enough in your account.\n");
            printf("Please pull more money from the very, very cool and magical unlimited wallet.\n");
            pullMoney(balance); //calls pullMoney function to take money out of wallet
        }
        else //if user has enough money, take required money and return change 
        {   
            printf("You have $%0.2f in your hand before transaction.\n", *balance);
            *balance -= price;
            printf("Putting $%0.2f into the vending machine.\n", price);
            printf("Transaction was successful!\n");
            printf("You have now $%0.2f in your hand.\n", *balance);
            printf("*****************************************************\n");
            trigger--; //end the loop as the transaction was done succesfully, return to menu
        }
    } while (trigger != 0); //loop in case that user does not have enough money in hand, will continue until there is enough to finish a succesful transaction
}

void pullMoney(double *balance) //function to take money off of infinite wallet
{
    int moneyChoice; //used to know what user wants from wallet from the three options ($1, $5, $10)

    printf("*****************************************************\n");
    printf("How much would you like to pull from the unlimited wallet?\n");
    printf("1: $1.00\n");
    printf("2: $5.00\n");
    printf("3: $10.00\n");

    printf("Option Selected: ");
    scanf("%d", &moneyChoice);

    if(moneyChoice < 1 || moneyChoice > 3) //if user takes unacceptable option, tell user that is not available
    {
        printf("Sorry, that is not one of the options recognized.\n");
    }   
    else //if user chose acceptable option, add choice to hand
    {
        printf("*****************************************************\n");
        switch(moneyChoice) //using user's choice, add appropriate money to hand
        {
            case 1:
                *balance += 1.00;
                printf("$1.00 has been added to your hand successfully!\n");
                break;
            case 2:
                *balance += 5.00;
                printf("$5.00 has been added to your hand successfully!\n");
                break;
            case 3:
                *balance += 10.00;
                printf("$10.00 has been added to your hand successfully!\n");
                break;
        }
        printf("*****************************************************\n");
    }
}

void displayVendingOptions() //function to display the options available in the vending machine
{
    printf("Here are the options!\n");
    printf("*****************************************************\n");
    printf("1. Sprite        $2.50\n");
    printf("2. Coca-Cola     $2.50\n");
    printf("3. Water         $2.00\n");
    printf("4. Gatorade      $3.00\n");
    printf("5. Diet Cola     $2.55\n");
    printf("6. Fanta         $2.55\n");
    printf("7. Root Beer     $1.50\n");
    printf("8. Dr. Pepper    $1.55\n");
    printf("*****************************************************\n");
}


