/* ------------------------------------------------
 * Program 5 Boggle
 *
 * Class: CS 141, Fall 2017.  Tues 12pm lab
 * System: Mac OS, C9
 * Author: Aditya Vandanapu
 *
 * ToDo: Create the boggle game
 * -------------------------------------------------
 */
#include <iostream>   // For Input and Output
#include <fstream>    // For file input and output
#include <cassert>    // For the assert statement
#include <cctype>     // Allows using the tolower() function
#include <ctime>      // Timer functions
#include <cstring>    // For strlen
#include <string> //For string
using namespace std;

// Global constants
const char DictionaryFileName[] = "dictionary.txt";
const int MaxNumberOfWords = 263533; // Number of dictionary words
const int MinWordLength = 3;         // Minimum dictionary word size to be stored
const int MaxWordLength = 16;         // Max word size.  Add 1 for null
const int MaxUserInputLength = 81;   // Max user input length
const int NumberOfLetters = 26;      // Letters in the alphabet
const int TotalSecondsToPlay = 60;   // Total number of seconds to play per board
//const bool wordsFound[];
//const char boardValue[16];

//--------------------------------------------------------------------------------
// Display name and program information
void displayIdentifyingInformation()
{
    printf("\n");
    printf("Author: Aditya Vandanapu          \n");
    printf("Program: #5, Boggle        \n");
    printf("TA: Minh Huyn Nguyen, Tues 12 pm  \n");
    printf("Nov 13, 2017                \n");
    printf("\n");
}//end displayIdentifyingInformation()


//--------------------------------------------------------------------------------
// Display instructions
void displayInstructions()
{
    printf("Welcome to the game of Boggle, where you play against the clock   \n");
    printf("to see how many words you can find using adjacent letters on the  \n");
    printf("board.  Each letter can be used only once for a given word.       \n");
    printf("  \n");
    printf("When prompted to provide input you may also:                      \n");
    printf("     Enter 'r' to reset the board to user-defined values.         \n");
    printf("     Enter 's' to solve the board and display all possible words. \n");
    printf("     Enter 't' to toggle the timer on/off.                        \n");
    printf("     Enter 'x' to exit the program.                               \n");
    printf("  \n");
}//end displayInstructions()


//---------------------------------------------------------------------------
// Read in dictionary
//    First dynamically allocate space for the dictionary.  Then read in words
// from file.  Note that the '&' is needed so that the new array address is
// passed back as a reference parameter.
void readInDictionary(
                      char ** &dictionary,                      // dictionary words
                      long int &numberOfWords)                  // number of words stored
{
    // Allocate space for large array of C-style strings
    dictionary = new char*[ MaxNumberOfWords];
    
    // For each array entry, allocate space for the word (C-string) to be stored there
    for (int i=0; i < MaxNumberOfWords; i++) {
        dictionary[i] = new char[ MaxWordLength+1];
        // just to be safe, initialize C-strings to all null characters
        for (int j=0; j < MaxWordLength; j++) {
            dictionary[i][j] = '\0';
        }//end for (int j=0...
    }//end for (int i...
    
    // Now read in the words from the file
    ifstream inStream;                 // declare an input stream for my use
    numberOfWords = 0;                   // Row for the current word
    inStream.open( DictionaryFileName);
    assert( ! inStream.fail() );       // make sure file open was OK
    
    // Keep repeating while input from the file yields a word
    char theWord[ 81];    // declare input space to be clearly larger than largest word
    while( inStream >> theWord) {
        int wordLength = (int)strlen( theWord);
        if( wordLength >= MinWordLength && wordLength <= MaxWordLength) {
            strcpy( dictionary[ numberOfWords], theWord);
            // increment number of words
            numberOfWords++;
        }
    }//end while( inStream...
    
    cout << "The dictionary total number of words is: " << MaxNumberOfWords << endl;
    cout << "Number of words of the right length is:  " << numberOfWords << endl;
    
    // close the file
    inStream.close();
}//end readInDictionary()


//--------------------------------------------------------------------------------------
// Use binary search to look up the search word in the dictionary array, returning index
// if found, -1 otherwise
int binarySearch( const char searchWord[ MaxWordLength+1], // word to be looked up
                 char **dictionary)               // the dictionary of words
{
    int low, mid, high;     // array indices for binary search
    int searchResult = -1;  // Stores index of word if search succeeded, else -1
    
    // Binary search for word
    low = 0;
    high = MaxNumberOfWords - 1;
    while ( low <= high)  {
        mid = (low + high) / 2;
        // searchResult negative value means word is to the left, positive value means
        // word is to the right, value of 0 means word was found
        searchResult = strcmp( searchWord, dictionary[ mid]);
        if ( searchResult == 0)  {
            // Word IS in dictionary, so return the index where the word was found
            return mid;
        }
        else if (searchResult < 0)  {
            high = mid - 1; // word should be located prior to mid location
        }
        else  {
            low = mid + 1; // word should be located after mid location
        }
    }
    
    // Word was not found
    return -1;
}//end binarySearch()



//---------------------------------------------------------------------------
// Get random character
//    Find random character using a table of letter frequency counts.
// Iterate through the array and find the first position where the random number is
// less than the value stored.  The resulting index position corresponds to the
// letter to be generated (0='a', 1='b', etc.)
char getRandomCharacter()
{
    // The following table of values came from the frequency distribution of letters in the dictionary
    float letterPercentTotals[ NumberOfLetters] = {
        0.07680,  //  a
        0.09485,  //  b
        0.13527,  //  c
        0.16824,  //  d
        0.28129,  //  e
        0.29299,  //  f
        0.32033,  //  g
        0.34499,  //  h
        0.43625,  //  i
        0.43783,  //  j
        0.44627,  //  k
        0.49865,  //  l
        0.52743,  //  m
        0.59567,  //  n
        0.66222,  //  o
        0.69246,  //  p
        0.69246,  //  q
        0.76380,  //  r
        0.86042,  //  s
        0.92666,  //  t
        0.95963,  //  u
        0.96892,  //  v
        0.97616,  //  w
        0.97892,  //  x
        0.99510,  //  y
        1.00000}; //  z
    
    // generate a random number between 0..1
    // Multiply by 1.0 otherwise integer division truncates remainders
    float randomNumber = 1.0 * rand() / RAND_MAX;
    
    // Find the first position where our random number is less than the
    // value stored.  The index corresponds to the letter to be returned,
    // where 'a' is 0, 'b' is 1, and so on.
    for( int i=0; i<NumberOfLetters; i++) {
        if( randomNumber < letterPercentTotals[ i]) {
            // we found the spot.  Return the corresponding letter
            return (char) 'a' + i;
        }
    }
    
    // Sanity check
    cout << "No alphabetic character generated.  This should not have happened. Exiting program.\n";
    exit( -1);
    return ' ';   // should never get this
}//end getRandomCharacter



//Board reset
void resetBoard()
{
    char boardValue [16];
    char userInput [16];
    cout << "Enter 16 characters for the new board: " << endl;
    cin >> userInput;
    
    for(int i = 0; i < 16; i++)
    {
        boardValue[i] = userInput[i];
    }
    
    int p = 0;
    // printing the board values into screen from single dimensional array
    for(int j = 0; j < 4; j++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << boardValue[p]  << " ";
            p++;
        }
        cout << endl;
    }
}

//Boolean statement to determine existence of the word by using recursion
bool recursionOfBoard(char board[], char userInputs[], int indexPosition, int lengthOfWord)
{
    bool done = false;
    int next = 0;
    int surround[8] = { 1, -1, 5, -5, 6, -6, 7, -7 };
    if (lengthOfWord == strlen(userInputs))
    {
        done = true;
        return done;
    }
    
    
    int w = 0;
    while (w < 8)
    {
        next = indexPosition + surround[w];
        if (userInputs[lengthOfWord] == board[next])
        {
            done = recursionOfBoard(board, userInputs, next, lengthOfWord+1);
        }
        else
        {
            continue;
        }
        w++;
    }
    return done;
}

//Letters that exist on the board with the recurisive function
bool lettersOfBoard(char boardVal[], char userInputs[])
{
    
    char first = userInputs[0];
    int index = 0;
    int lengthSize = 0;
    bool done = false;
    int x = 0;
    while (x < 36)
    {
        if (userInputs[lengthSize] == boardVal[x])
        {
            index = x;
            done = recursionOfBoard(boardVal,userInputs,index,length+1);
        }
        else
        {
            continue;
        }
        x++;
    }
    return done;
}



/*Attempted code for user input of 's'*/

// void solvetheBoard(char boardValue[], char **dictionary, int MaxNumberOfWords, bool wordsFound[], int MaxWordLength, int MinWordLength)
// {
//     for(int i = 0; i < MaxNumberOfWords; i ++ )
//     {
//         wordsFound[i] == false;
//     }

//     for(int i = 0; i < MaxNumberOfWords; i ++)
//     {
//         wordsFound[i] = baseOfBoard(board[i], userInput[]);
//     }

//     for(int i = 0; i < MaxNumberOfWords; i ++ )
//     {
//         if(wordsFound[i] == true && dictionary[i] != NULL && wordsFound[i] != false)
//         {
//             if(strlen(dictionary[i]) <= MaxWordLength && strlen(dictionary[i]) >= MinWordLength)
//             {
//                 cout<<dictionary[i]<<" ";
//             }
//         }
//     }
// }

//---------------------------------------------------------------------------
int main()
{
    // declare variables
    srand(time(0));
    char **dictionary;                // 2d array of dictionary words, dynamically allocated
    long int numberOfWords;           // how many words actually found in dictionary
    char userInput[ MaxUserInputLength];
    
    
    // Declare a variable to hold a time, and get the current time
    time_t startTime = time( NULL);
    
    displayIdentifyingInformation();
    displayInstructions();
    
    // read in dictionary.  numberOfWords returns the actual number of words found
    readInDictionary( dictionary, numberOfWords);
    
    // Demonstrate how to get random characters
    char boardValues [16];
    char generateLetter;
    int i = 0;
    while (i < 16)
    {
        generateLetter = getRandomCharacter();
        boardValues[i] = generateLetter;
        i++;
    }
    
    int x = 0;
    // printing the board values into screen from single dimensional array
    for(int j = 0; j < 4; j++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << boardValues[x]  << " ";
            x++;
        }
        cout << endl;
    }
    
    cout << endl << endl;
    
    // Loop to while there is still time left
    cout << "Do word lookups for 60 seconds." << endl;
    int elapsedSeconds = 0;
    while( elapsedSeconds < TotalSecondsToPlay) {
        // Prompt for and get user input
        cout << endl;
        cout << "Enter a word: ";
        cin >> userInput;
        
        //if word is on board
        if(lettersOfBoard(boardValues, userInput) == true)
        {
            cout << "Word on the board."<<endl;
        }
        //if word is not on board
        else if (lettersOfBoard(boardValues, userInput) == false)
        {
            cout << "Word is NOT on the board"<<endl;
        }
        //sees if its in the dictionary
        if( binarySearch( userInput, dictionary) != -1)
        {
            cout << userInput << " is in the dictionary." << endl;
        }
        //Displays the computers answer
        else if(userInput[0] == 's'  && userInput[1] == '\0')
        {
            //solvetheBoard(char my_board[], char **dictionary, long int &numberOfWords, bool wordsFound[], int maxWord, int minWord );
            cout<<"This part is incomplete"<<endl;
        }
        //toggles time.
        else if(userInput[0] == 't'  && userInput [1] == '\0')
        {
            cout<<"This part is incomplete"<<endl;
        }
        //exit board
        else if(userInput[0] == 'x'  && userInput [1] == '\0')
        {
            cout<<"Thanks for playing" << endl;
            break;
        }
        //resets board
        else if(userInput [0] == 'r' && userInput [1] == '\0')
        {
            resetBoard();
        }
        //error check
        else
        {
            cout << userInput << " is NOT in the dictionary." << endl;
        }
        
        // Calculate how many seconds have elapsed since we started the timer.
        elapsedSeconds = difftime( time( NULL), startTime);
        cout << "There are " << TotalSecondsToPlay - elapsedSeconds << " seconds left." << endl;
    }
    cout << "I let you finish your last move. Time is up!" << endl;
    
    return 0;
}//end main()

