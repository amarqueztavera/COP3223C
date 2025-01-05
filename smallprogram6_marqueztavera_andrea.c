// Andrea Marquez Tavera
// Dr. Steinberg
// COP3223C Section 1
// Small Program 6

#define SIZE 1000
#include <stdio.h>// preprocessor directive
#include <stdlib.h>

void display(int arr[]);// function prototype used to display numbers in array
void meanMinMax(int arrProb1[]);// problem 1 function prototype
void mySort(int arrProb2[]);// problem 2 function prototype
void doubleShift(int arrProb3[]);// problem 3 function prototype
void reverse(int arrProb4[]);// problem 4 function prototype

int main(void)// main function
{
	int arr[SIZE];
	int seed;
	printf("Enter a seed: ");
	
	scanf("%d", &seed);
	srand(seed);
	
	//generate numbers for the array
	for (int x = 0; x < SIZE; x++)
	{
		arr[x] = (rand() % (1000 - 1 + 1)) + 1; //1-1000
	}
	
	//call your functions for small program 6
    // problem 1
    meanMinMax(arr);// call user defined function for problem 1
    //-------------------------------------------------------------------------------------------
    // problem 2
    mySort(arr);// call user defined function for problem 2
    display(arr);// call user defined function to show numbers in array
    //-------------------------------------------------------------------------------------------
    // problem 3
    doubleShift(arr);// call user defined function for problem 3
    display(arr);// call user defined function to show numbers in array
    //-------------------------------------------------------------------------------------------
    // problem 4
    reverse(arr);// call user defined function for problem 4
    display(arr);// call user defined function to show numbers in array
	
	return 0;// function terminator
}

void display(int arr[])// user-defined function to show numbers in array
{
	for (int x = 0; x < SIZE; x++)
		printf("%6d ", arr[x]);
	
	printf("\n");
}

//-------------------------------------------------------------------------------------------
// problem 1 user defined function
void meanMinMax(int arrProb1[])
{
    double avg = 0;// variable store the average
    int total = 0;// variable to take track of the sum of all of the elements in the arr[] array
    int max = arrProb1[0];// variable to store the max number in the array, starting from the first number
    int min = arrProb1[0];// variable to store the min number in the array, starting from the first number
    
    // adds each number in the array by going through each element in the array, starting from the first one (0) and ending on the last possible element (indexforavg < SIZE)
    for(int indexforavg = 0; indexforavg < SIZE; indexforavg++)
    {
        total += arrProb1[indexforavg];
    }
    avg = (double)total / SIZE;// calculates the average by casting the sum of all the elements into a double
    printf("Average: %f\n", avg);

    // for loop that goes through each element in the array
    for(int indexformin = 0; indexformin < SIZE; indexformin++)
    {
        if(arrProb1[indexformin] < min)// compares every single element to the current min variable, starting off with the first element in the array
        {
            min = arrProb1[indexformin];// if the element being compared to the current min in less that it, the min value is replaced with it 
        }
    }

    for(int indexformax = 0; indexformax < SIZE; indexformax++)// smae as avobe but instead with the max
    {
        if(arrProb1[indexformax] > max)
        {
            max = arrProb1[indexformax];
        }
    }

    // prints max and min
    printf("Max: %d\n", max);
    printf("Min: %d\n\n", min);
}

//-------------------------------------------------------------------------------------------
// problem 2 user defined function
void mySort(int arrProb2[])
{
    for(int indexP2 = 0; indexP2 < SIZE; indexP2++)// keeps loop as long as index is less than SIZE
    {
        for(int compareTo = indexP2 + 1; compareTo < SIZE; compareTo++)// keeps loop as long as the second number being compared to the first number (index) is less than SIZE
        {
            if(arrProb2[indexP2] > arrProb2[compareTo])// if the first number is greater than the second number, then replace the two
            {
                int newOrder = arrProb2[indexP2];// temporary variable to keep track of the first number
                arrProb2[indexP2] = arrProb2[compareTo];// replaces first number with second number
                arrProb2[compareTo] = newOrder;// second number is replaced with the temporary varible
            }
        }
    }
}

//-------------------------------------------------------------------------------------------
// problem 3 user defined function
void doubleShift(int arrProb3[])
{
    int trigger = 2;// trigger to do loop twice
    while(trigger != 0)// loop so that numbers are replaced twice
    {
        int original = arrProb3[SIZE - 1];// temporary variable that stores the last element in the array
        for(int indexP3 = SIZE - 1; indexP3 > 0; indexP3--)// for loop that will continue until the count down of elements available is 0
        {
            arrProb3[indexP3] = arrProb3[indexP3 - 1];// replacesthe last element with the second to last one so it shifts once to the right
        }
        arrProb3[0] = original;// first element is the last element from original order

        trigger--;// ends loop after two times going through it so elements are overall shifted twice
    }
}

//-------------------------------------------------------------------------------------------
// problem 4 user defined function
void reverse(int arrProb4[])
{
    for(int indexP4 = 0; indexP4 < (SIZE / 2); indexP4++)// for loop that will continue as long as the counter is less than half of the array size
    {
        int tempToRepace = arrProb4[indexP4];// temporary variable that stores an element, originally the first one and so forth
        arrProb4[indexP4] = arrProb4[SIZE - indexP4 - 1];// replaces the an element with its mirror order from the end-backwards
        arrProb4[SIZE - indexP4 - 1] = tempToRepace;// the mirror element is now the original
    }
}
