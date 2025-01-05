//Andrea Marquez Tavera
//Dr. Steinberg
//COP3223C Section 1
//Small Program 8

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIMIT 50

typedef struct{
    char * fname; //first name
	char * lname; //last name
	char * show; //favorite show
}record_t;

record_t * createArray(int maxsize);
record_t * insert(record_t *myarray, int *maxsize, int *currentsize);// user defined function for problem 1
void display(record_t *myarray, int currentsize);
record_t *doubleIt(record_t *arr, int size); // user defined function for problem 2
int removeRecord(record_t *arr, int size, int index);// user defined function fro problem 3
void freeRecords(record_t *arr, int size); // user defined function for problem 4

int main(void)// main function
{
	int maxsize;// will store the maximum size of the dynamic array

	printf("Enter a size for the dynamic array: ");
	scanf("%d", &maxsize);// stores the maxsize


	record_t *myarray = createArray(maxsize);// allocates myarray in the heap space
	
	int currentsize = 0;// will store the current amount of valid holds
	int option = -1;// used to trigger while loop to keep asking the menu

	while(option != 0)// as long as user doesn't exit keep going
    {
        printf("What would you like to do?\n");
        printf("1: Insert a record\n");
        printf("2: Display records\n");
        printf("3: Remove record\n");
        printf("4: Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);// takes user's menu option

        switch(option)// depening on user's menu option
        {
            case 1:
                printf("Insert was selected...\n");
                myarray = insert(myarray, &maxsize, &currentsize);// calls user-defined function for problem 1
                break;

            case 2:
                printf("Display was selected...\n");
                display(myarray, currentsize);// calls user-defined function that displays the array
                break;

            case 3:
                printf("Remove was selected...\n");
                printf("Select an index of record to remove...\n");
                int index;// will store user's choice of index to remove from the array
                scanf("%d", &index);// user's choice of index to remove from the array
                currentsize = removeRecord(myarray,currentsize,index);// calls user-defined function for problem 3
                break;

            case 4:
                printf("Exiting...\n");
                option = 0;// breaks while loop and therefor ends the program
				break;

            default:
                printf("Invalid Selection...\n");// if the user picks an invalid option
        }
    }
	
	freeRecords(myarray, currentsize);// frees records from myarray since malloc was used when inserting

	free(myarray);// frees myarray since malloc was used

	myarray = NULL;

	return 0;// function terminator
}

record_t * createArray(int maxsize)
{
	record_t * arr = (record_t *) malloc(maxsize * sizeof(record_t));
	
	if(arr == NULL)
	{
		printf("malloc error in createArray...program exiting\n");
		exit(1);
	}
	
	return arr;
}

void display(record_t *myarray, int currentsize)
{
	printf("---------------------------------\n");

	for(int x = 0; x < currentsize; ++x)
	{
	    printf("myarray[%d].fname = %s\n", x, (x + myarray)->fname); //try it with myarray[x].name
		printf("myarray[%d].lname = %s\n", x, (x + myarray)->lname); //try it with myarray[x].name
		printf("myarray[%d].show = %s\n", x, (x + myarray)->show); //try it with myarray[x].show
	}

	printf("---------------------------------\n");
}

// user defined function for problem 1
record_t * insert(record_t *myarray, int *maxsize, int *currentsize)
{   
    if(*currentsize == *maxsize)// if the current valid entries the myarray holds is the same as the maximum amount of entires myarray CAN hold (aka if myarray is full)
    {
        printf("Array is full...Need to doubleIt...\n");
        myarray = doubleIt(myarray, *maxsize);// doubles my array, user-defined function for problem 2
        freeRecords(myarray, *currentsize);// frees records
        *maxsize *= 2;
    }

    // dynamic memory for each elemnt of myarray
    myarray[*currentsize].fname = (char *) malloc(sizeof(char) * (*maxsize));
    myarray[*currentsize].lname = (char *) malloc(sizeof(char) * (*maxsize));
    myarray[*currentsize].show = (char *) malloc(sizeof(char) * (*maxsize));
    
    if(myarray == NULL)// in case that malloc doesn't work
    {
        printf("Error!\n");
        freeRecords(myarray, *currentsize);// frees records
        exit(1);// Ends the program
    }
    else// otherwise
    {
        // stores inputs for the record 
        printf("Enter the first name: ");
        scanf("%s", myarray[*currentsize].fname);

        char newLine;// used for the new line that scanf adds, needed so that fgets can get input
        printf("Enter the last name: ");
        scanf("%s%c", myarray[*currentsize].lname, &newLine);

        printf("Enter favorite show: ");
        fgets(myarray[*currentsize].show, LIMIT, stdin);// fgets because the show can have spaces
        
        *currentsize += 1;// increases the current amount of records since one was just added
    
        freeRecords(myarray, *currentsize);// frees records
    }

    return myarray;
}

// user-defined function for problem 2
record_t *doubleIt(record_t *arr, int size)
{
    record_t *doubleOriginal = (record_t *) malloc((sizeof(record_t) * size) * 2);// doubles the size of the dynamic array

    if(doubleOriginal == NULL)// if malloc fails
    {
        printf("Error!\n");
        freeRecords(arr, size);// frees records
        exit(1);// ends the program
    }
    else// otherwise
    {
        for(int index = 0; index < size; index++)// goes through each record and copies it into the new array
        {
            doubleOriginal[index] = arr[index];
        }
        
        freeRecords(arr, size);// frees old components that used malloc
        free(arr);// frees the old array that used malloc

        arr = NULL;// nulls the old array

        return doubleOriginal;// returns the new, bigger array that hold all the old values
    }
}

// user defined function for problem 3
int removeRecord(record_t *arr, int size, int index)
{

    if(index < size && index >= 0)// if the record the user wants to delete is in bounds
    {
        // sets the element that the user wants to delete to null
        strcpy(arr[index].fname, "\0");
        strcpy(arr[index].lname, "\0");
        strcpy(arr[index].show, "\0");

        for(int index2 = index; index2 < size - 1; index2++)// goes through each record starting on the record that the user wants to delete 
        {
            int next = index2 + 1;// variable for the record after the current one

            // replaces current record for the next one
            strcpy(arr[index2].fname, arr[next].fname);
            strcpy(arr[index2].lname, arr[next].lname);
            strcpy(arr[index2].show, arr[next].show);
        }

        size -= 1;// resizes the current amount of valid records since one was just deleted

        freeRecords(arr, size);// frees records

        return size;// returns the new size
    }
    else// if record the user wants to delete is not in the bounds
    {
        printf("Invalid Index\n");

        freeRecords(arr, size);// frees records

        return size;// return current size
    }
}

// user-defined function for problemn 4
void freeRecords(record_t *arr, int size)
{
    for(int index = 0; index < size; index++)// goes through each record and frees each component that used malloc 
    {
        free(arr[index].fname);
        free(arr[index].lname);
        free(arr[index].show);
    }
}
