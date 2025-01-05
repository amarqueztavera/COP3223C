// Andrea Marquez Tavera
// Dr. Steinberg
// COP3223 Section 1
// Large Program 4

#include <stdio.h>// preprocessor directive
#include <ctype.h>// standard library
#include <string.h>// string library
#define SIZE 30// used for length of strings and length of struct array

typedef struct {// creates typedef struct that has all the elements needed for records

    // elements
    int id;
    char fname[SIZE];
    char lname[SIZE];
    double score;

}record_t;// struct name


int menu();// function that welcomes the user to the database, returns their choice from the menu
void insertRecord(record_t record[], int *amount);// add a brand new record to the array
void removeRecord(record_t record[], int *amount);// remove an existing record from the array
void searchRecord(record_t record[], int amount);// check to see if a record exists in the array
void displayRecord(record_t record[], int amount);// display all records in the array
void exitProgram(record_t record[], int amount, int * trigger);// program exists and writes to a text file all records of the array
void hardcode(record_t record[]);// original entries that are automatically populates (total of 6)

int main()// main function
{
    int trigger = 1;// used to keep menu looping until user chooses to exit
    int amount = 6;// used to keep track of how many records have been made, initially 6 because of hardcode function
    
    record_t student[SIZE];// declares struct array to the name student and size of 30
    
    hardcode(student);// calls hardcode function that populates the first 6/30 records in the struct array
    
    // Greet user
    printf("Hello! Welcome to your personal book characters database!\n");
    printf("Here you can store your favorite book character!\n");
    printf("I've gone ahead and added some of my personal favorites! But feel free to edit it however you'd like!\n\n");
    while(trigger != 0)// while loop to keep menu looping until user exits
    {
        int choice = menu();// calls welcome function to get user's menu option

        switch(choice)// switch statement depending on user's menu option 
        {
            case 1:
                printf("\n------------------------------------------\n");
                printf("You have selected to insert a record!\n\n");
                insertRecord(student, &amount);// calls insertRecord function to add record
                printf("\nAction finished successfully! Select Display to see it :D\n\n");
                break;
            case 2: 
                printf("\n------------------------------------------\n");
                printf("You have selected to remove a record!\n\n");
                removeRecord(student, &amount);// calls removeRecord function to remove record
                printf("\nAction finished successfully! Select Display to see it :D\n\n");
                break;
            case 3:
                printf("\n------------------------------------------\n");
                printf("You have selected to search for a record!\n\n");
                searchRecord(student, amount);// calls searcRecord to find a record
                break;
            case 4:
                printf("\n------------------------------------------\n");
                printf("You have selected to display the records!\n\n");
                displayRecord(student, amount);// calls sisplayRecord to show records in output, not file
                break;
            case 5:
                printf("\n------------------------------------------\n");
                printf("You have selected to exit the program!\n\n");
                exitProgram(student, amount, &trigger);// exits programs and creates file with records
                break;
            default:
                printf("\n------------------------------------------\n");
                printf("That was not an acceptable option! ;(\n\n");
        }
    }
    return 0;
}

int menu()
{
    int choice;// will store user's choice 

    // shows menu options
    printf("Please choose from the following options: \n");
    printf("1. Insert record\n");
    printf("2. Remove record\n");
    printf("3. Search a record\n");
    printf("4. Display records\n");
    printf("5. Exit database\n");

    printf("\nChoice: ");
    scanf("%d", &choice);// takes user's choice

    return choice;// returns user's choice to main
}

void insertRecord(record_t record[], int *amount)
{
    int inRange = 1;// used for while loop to check if there is space for the insert
    int upadtedUserAmount;// used to do remaining records math and to add information
    int available;// used to check if there is space for the amount of records the user wishes to input
    int userAmount;// used to store how many records the user wishes to insert
    
    while(inRange != 0)// while loop to check if there is space for the insert
    {
        printf("Insert the amount of records you'd life to insert: ");
        scanf("%d", &userAmount);// takes the amount of records user wishes to input

        upadtedUserAmount = *amount + userAmount;// temporary variable that stores all of the records that were filled in (including the amount the user wishes to input)
        available = SIZE - upadtedUserAmount;// subtraction to make sure there is space for records

        if(userAmount > SIZE)// if user wants to put more than the size of the struct array, tell them there's no space
        {
            printf("That is too mant entries! There's no spaces for that\n");
        }
        else if(available < 0)// if user wants to put more than there's space for, tell them there's no space and how many there currently are
        {
            int amountLeft = SIZE - *amount;// math to know how many spaces are left
            printf("That is too many entries! There are only %d spaces left\n", amountLeft);
        }
        else// if the amount the user wishes to input is available, continue on and break the loop
        {
            inRange--;// breaks the loop
        }
    }
    
    int triggerID = 1;// used to keep loop that tests if inputed ID is acceptable
    int triggerScore = 1;// used to keep loop that tests if inputed score is in range

    // goes through each index from the current amount of records to the total amount of records (aka the current amount + the amount of records that will be inserted)
    for(int index = *amount; index < upadtedUserAmount; index++)
    {
        *amount += 1;// increases current amount of records by one

        while(triggerID != 0)// loop to test ID to make sure it's acceptable
        {
            printf("\nEnter the book's ID from 1 - 30 (Do not put 0 or negative numbers!): ");
            scanf("%d", &record[index].id);// stores user's id

            int idDup = 0;// variable to keep track of if the ID is already in used (dup stands for duplicate)
            
            if(record[index].id <= 0 || record[index].id > 30)// if ID is not in the range of 1-30, tell them it's invalid and ask again
            {
                printf("\nThat is is a invalid ID! Try again!\n");
            }
            else if(record[index].id <= 30 && record[index].id > 0)// if ID is in range
            {
                for(int index2 = 0; index2 < (*amount - 1); index2++)// checks for each ID that has already been inputed
                {   
                    if(record[index2].id == record[index].id)// if the given ID already exists
                    {
                        idDup = 1;// increase variable to signal ID is already in use
                    }
                }
                if(idDup == 1)// if ID already in use tell them and try again
                {
                    printf("\nThat is an ID already taken! Try again!\n");
                }
                else if(idDup != 1)// otherwise move on
                {   
                triggerID--;// breaks the loop
                }
            }
        }
        
        printf("Enter the character's first name: ");
        scanf("%s", record[index].fname);// Stores character's first name. Pointer so therefore no need for &
            
        printf("Enter the character's last name: ");
        scanf("%s", record[index].lname);// Stores character's last name. Pointer so therefore no need for &
        
        while(triggerScore!= 0)// loop to check if score is in range of 0-5
        {
            printf("Enter the character's rating out of 5: ");
            scanf("%lf", &record[index].score);// stores character's score

            if(record[index].score < 0 || record[index].score > 5)// if score is not in range, tell them and try again
            {
                printf("\n\nThat is not valid input! Try again!\n\n");
            }
            else// otherwise move on
            {
                triggerScore--;// breaks loop
            }
        }

        // restores loop triggers to original value for next time 
        triggerID++;
        triggerScore++;
    }
}

void removeRecord(record_t record[], int *amount)
{
    int userDelete;// variable to store what the ID is of the character the user wants to delete
    int found;// variable to keep track of whether or not the ID is available
    
    // variables for for loops, outside of for loop since they will be used outside of them
    int trueIndex;
    int index;

    printf("Please enter the character's ID of the character record you would like to delete: ");
    scanf("%d", &userDelete);// stores the ID of the character the user wants to delete

    printf("\nYou selected character #%d\n", userDelete);

    for(index = 0; index < SIZE; index++)// checks each record
    {
        if(userDelete == record[index].id)// if the ID is found in the records
        {
            found = 1;// update found to know it was found

            // delete record information
            record[index].id = 0;
            strcpy(record[index].fname, "\0");
            strcpy(record[index].lname, "\0");
            record[index].score = 0.0;

            trueIndex = index;// updates trueIndex to know which index the ID the user wants to delete is, since index will continue to go on
        }
    }

    if(found != 1)// if record is not found tell them so
    {
        printf("\nRecord not found!\n");
    }
    else if(found == 1)// if record is found
    {   
        for(int index2 = trueIndex; index2 < *amount; index2++)// goes through each record starting on where the ID the user wants to delete is
            {
                int next = index2 + 1;// variable for the record after the current one

                // replaces current record for the next one
                record[index2].id = record[index2 + 1].id;
                strcpy(record[index2].fname, record[index2 + 1].fname);
                strcpy(record[index2].lname, record[index2 + 1].lname);
                record[index2].score = record[index2 + 1].score;
            }
        // replaces last record made to null since it's not supposed to exist
        record[*amount].id = 0;
        strcpy(record[*amount].fname, "\0");
        strcpy(record[*amount].lname, "\0");
        record[*amount + 1].score = 0.0;

        *amount -= 1;// updates total amount of records filled in
    }
}

void searchRecord(record_t record[], int amount)
{
    int lookUpId;// will store what ID the user wants to find
    int found;// variable to keep track of whether or not the ID exists

    printf("Enter the character's ID you'd to search: ");
    scanf("%d", &lookUpId);// stores the ID the user wants to find

    for(int index = 0; index < amount; index++)// checks each ID
    {
        if(lookUpId == record[index].id)// if the ID the user wants to find exits, display it
        {
            found = 1;// updates whether or not record was found

            // displays record
            printf("\nCharacter ID = %d\n", record[index].id);
            printf("Character's First Name = %s\n", record[index].fname);
            printf("Character's Last Name= %s\n", record[index].lname);
            printf("Character's rating = %0.2lf\n", record[index].score);
            printf("\n");
        }
    }
    if(found != 1)// if record was not found tell user
    {
        printf("\nRecord not found!\n\n");
    }
}

void displayRecord(record_t record[], int amount)
{
    for(int index = 0; index < amount; index++)// goes through each record to display it
    {
        // displays records
        printf("\nCharacter ID = %d\n", record[index].id);
        printf("Character's First Name = %s\n", record[index].fname);
        printf("Character's Last Name= %s\n", record[index].lname);
        printf("Character's rating = %0.2lf\n", record[index].score);
        printf("\n");
    }
}

// populates first six records of the database
void hardcode(record_t record[])
{
    record[0].id = 1;
    strcpy(record[0].fname, "Percy");
    strcpy(record[0].lname, "Jackson");
    record[0].score = 5.00;

    record[1].id = 2;
    strcpy(record[1].fname, "Annabeth");
    strcpy(record[1].lname, "Chase");
    record[1].score = 5.00;

    record[2].id = 3;
    strcpy(record[2].fname, "Katniss");
    strcpy(record[2].lname, "Everdeen");
    record[2].score = 4.25;

    record[3].id = 4;
    strcpy(record[3].fname, "Sam");
    strcpy(record[3].lname, "Cortland");
    record[3].score = 4.75;

    record[4].id = 5;
    strcpy(record[4].fname, "Harry");
    strcpy(record[4].lname, "Potter");
    record[4].score = 4.00;

    record[5].id = 6;
    strcpy(record[5].fname, "Conrad");
    strcpy(record[5].lname, "Fisher");
    record[5].score = 4.00;
}

void exitProgram(record_t record[], int amount, int *trigger)
{
    FILE *ptr;// creates file pointer
    ptr = fopen("Records.txt", "w");// creates file

    if(ptr != NULL)// as long as the file is able to be created
    {
        // prints header of the file
        printf("Creating a text file of your records!\n");
        fprintf(ptr, "Favorite Book Character Records\n");
        fprintf(ptr, "------------------------------------------\n");

        // prints each record
        for(int index = 0; index < amount; index++)// goes through each record
        {
            fprintf(ptr, "------------------------------------------\n");
            fprintf(ptr, "\nCharacter ID = %d\n", record[index].id);
            fprintf(ptr, "Character's First Name = %s\n", record[index].fname);
            fprintf(ptr, "Character's Last Name= %s\n", record[index].lname);
            fprintf(ptr, "Character's rating = %0.2lf\n", record[index].score);
            fprintf(ptr, "\n");
        }
    
        fclose(ptr);// closes file
        printf("File written Successfully! Goodbye!.\n");// Updates user that the file has been created and tells them goodbye

        *trigger -= 1;// ends while loop in the main
    }
    else// if file was not successfully created print error
        printf("Error");
} 