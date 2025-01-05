// Andrea Marquez Tavera
// Dr. Steinberg
// COP3223C Section 1
// Small Program 7

#include <stdio.h>// preprocessor directive
#include <ctype.h>// standard library
#include <string.h>// string library

void deblank(char phrase[], char new[]);// problem 1 function prototype
void pluralize(char simpleNoun[]);// problem 2 function prototype
void fact(char longPhrase[]);// problem 3 function prototype
char *substring(char first[], char compare[]);// problem 4 function prototype

int main()// main fuction
{
    // problem 1
    char phraseInput[20];// declares input string of size 20
    char newOutput[20];// declares output string of size 20

    printf("Enter a string: ");// asks user for string
    fgets(phraseInput, sizeof(phraseInput), stdin);// stores phrase in input string

    deblank(phraseInput, newOutput);// calls user defined function for problem 1

    printf("Output String with no blanks: %s", newOutput);// displays new string without blanks
    //-------------------------------------------------------------------------------------------
    // problem 2
    char nounInput[20];// declares input string of size 20

    printf("Enter string to be pluralize: ");// asks user for string
    scanf("%s", nounInput);// stores singular word, hence scanf, in input string

    pluralize(nounInput);// calls user defined function for problem 2

    printf("Word pluralize: %s\n", nounInput);// displays new string that is pluralized
    //-------------------------------------------------------------------------------------------
    // problem 3
    char randomInput[20];// declares input string of size 20

    printf("Enter a string with no spaces: ");// asks user for string
    scanf("%s", randomInput);// stores singular word, hence scanf, in input string

    fact(randomInput);// calls user defined function for problem 3
    //-------------------------------------------------------------------------------------------
    // problem 4
    char testInput[20];// declares first input string of size 20
    char keyInput2[20];// declares second input string of size 20

    printf("Enter the string: ");// asks user for first string
    scanf("%s", testInput);// stores singular word, hence scanf, in the first input string

    printf("Enter the substring you would like to look for: ");// asks user for second string to compare against fist string
    scanf("%s", keyInput2);// stores singular word, hence scanf, in the second input string

    char *test = substring(testInput, keyInput2);// declares and initializes char pointer that contains the address or NULL from user defined function for problem 4

    if(test == NULL)// if address is NULL, then substring doesn't exist in first input string
    {
        printf("Substring %s doesn't exist!\n", keyInput2);
    }
    else// otherwise, it does exist
    {
        printf("Substring %s exists!\n", keyInput2);
    }

    return 0;// function terminator
}

//-------------------------------------------------------------------------------------------
// problem 1 user defined function
void deblank(char phrase[], char new[])
{
    int deleteIndex = 0;// counter to use for index of blank space to delete
    for(int indexP1 = 0; indexP1 < strlen(phrase); indexP1++)// checks each character of the phrase string
    {
        if(phrase[indexP1] != ' ')// if a character found is a blank space, reorganize phrase string 
        {   
            phrase[deleteIndex] = phrase[indexP1];// replaces blank with next character
            deleteIndex++;// increases counter to move to the next space
        }
    }
    phrase[deleteIndex] = '\0';// deletes extra characters

    strcpy(new, phrase);// copies changed phrase string into new output string
}

//-------------------------------------------------------------------------------------------
// problem 2 user defined function
void pluralize(char simpleNoun[])
{
    int lengthOfChar = strlen(simpleNoun);// finds length of noun

    if(simpleNoun[lengthOfChar - 1] == 'y')// if last character is y, then erase y and add ies
    {   
        simpleNoun[lengthOfChar - 1] = '\0';// erases y
        strcat(simpleNoun, "ies");// adds ies
    }
    else if(simpleNoun[lengthOfChar - 1] == 's')// if last character is s, add es
    {
        strcat(simpleNoun, "es");// add es
    }
    else if((simpleNoun[lengthOfChar - 2] == 's' || simpleNoun[lengthOfChar - 2] == 'c') && simpleNoun[lengthOfChar - 1] == 'h')// if last characters ar sh or ch, add es
    {
        strcat(simpleNoun, "es");// add es
    }
    else// everything else add s
    {
        strcat(simpleNoun, "s");// add s
    }
}

//-------------------------------------------------------------------------------------------
// problem 3 user defined function
void fact(char longPhrase[])
{
    // declares and initializes letters, digits, and punctuation characters counters
    int letters = 0;
    int digits = 0;
    int punctuationCharacters = 0;

    printf("%s has \n", longPhrase);

    for(int indexP3 = 0; indexP3 < strlen(longPhrase); indexP3++)// checks each character in the string
    {
        if(isalpha(longPhrase[indexP3]))// if character is a letter add to counter
            letters++;
        else if(isdigit(longPhrase[indexP3]))// if character is a digit add to counter
            digits++;
        else if(ispunct(longPhrase[indexP3]))// if character is punctuation add to counter
            punctuationCharacters++;
    }
    
    // displays how many of each catergory
    printf("%d letters\n", letters);
    printf("%d digits\n", digits);
    printf("%d punctuation characters\n", punctuationCharacters);
}

//-------------------------------------------------------------------------------------------
// problem 4 user defined function
char *substring(char first[], char compare[])
{
    int lengthOfCompareStr = strlen(compare);// length of the string to compare

    for(int indexP4 = 0; indexP4 < *first; indexP4++)// checks each character address in string
    {
        if(strncmp(first, compare, lengthOfCompareStr) == 0)// if the whole key is in the original string, return the it
        {
            return first;
        }
        else// if not, keep checking
        {
            first++;
        }
    }
    return NULL;// otherwise return null
}