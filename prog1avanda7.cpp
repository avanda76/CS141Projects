 /*
 Overall Score out of 100: 100
 Grading comments in the code below are marked with //-!-
 Program execution (55 points total)
 A.  5: Displays header information                            |
 B.  5: Displays table from 99 down to 0                       |
 C.  5: Columns are lined up                                   |
 D.  5: Table has random upper and lower-case values           |
 E.  5: Special character value in all multiple of 9 positions |
 F. 10: Table shown, prompt, then special character displayed  |
 G. 10: Special character is random                            |
 H. 10: Table changes each time program is run                 |
 Program Style (45 points total):
 A.  5: Followed program naming conventions     |
 B. 10: Meaningful identifier names             | 
 C. 10: Comments                                | 
 D.  5: Functional Decomposition                |
 E. 10: Appropriate data and control structures | 
 F.  5: Code Layout                             | 
 */
 
 
 
 /* ------------------------------------------------ 
  * Guess It
  *
  * Class: CS 141, Fall 2017.  Tues 12pm lab
  * System: C++ in Cloud 9
  * Author: Aditya Vandanapu
  *
  * ToDo: N/A
  * -------------------------------------------------
  */
#include <iostream>
#include <iomanip> // enables use of setw()
#include <ctime> //-!-required for time, without this it won't compile, be sure to add it next time!
#include <cstdlib> //-!-required for rand, without this it won't compile, be sure to add it next time!
using namespace std;

int main() {
  srand(time(0));  //Used to initialize the pseudo-random number generator by passing the argument seed

  cout << "Program #1: Guess It "<< endl;
  cout << "Author: Aditya Vandanapu" << endl;
  cout<< "Lab: Tues 12 pm, TA:  Minh Huynh Nguyen " << endl;
  cout << "Date: September 1, 2017" << endl;
  cout<< "System:  C++ in Cloud 9" << endl;
  
 
  
  char multNineLetter; // Declares a variable for a multiple of nine.
  


  for(int i = 99; i >= 0; i-- ) // runs a loop from 99 to 0
  {
   if ((rand() % 2) == 0 ) //Determines if the number is even
    {
      char c = (90 - (rand() % 26)); //Generates a capital letter
       if(i == 99) //Stores the value for c
       {
            multNineLetter = c;
       }
       if(i % 9 == 0) // Makes the same letter for every multiple of 9
       {
           c = multNineLetter;
       }
       if(i < 10) // The numbers are formatted in the last line
        {
            cout << " " << i << ":" << c << " ";
        }
       else // Numbers that are formatted in other lines
        {
            cout << i << ":"<< c << " ";
        }
        
        if(i%10 == 0) //Creates a new Line
        {
            cout<< endl;
        }
        
    } 
    //Generates a lowercase letter, assigns it to c, and prints it out.
    else 
    {
       char c;
       c = (rand() % 26) + 'a'; 
       if(i == 99)
        {
            multNineLetter = c;
        }
       if(i % 9 == 0)
        {
           c = multNineLetter;
        }
       if(i < 10)
        {
            cout << " " << i << ":" << c << " ";
        }
       else
        {
            cout<< i << ":"<< c << " ";
        }
       
       if (i%10 == 0) 
        {
            cout<< endl;
        }
     } 

  }
  

    
 
  cout<< "1. Choose any two-digit number in the table above (e.g. 73)." << endl;
  cout<< "2. Subtract its two digits from itself (e.g. 73 - 7 - 3 = 63)" << endl;
  cout<< "3. Find this new number (e.g. 63) and remember the letter next to it." << endl;
  cout<< "4. Now press 'r' and I'll read your mind..." << endl;
	
	//When user inputs 'r', it prints out multNineLetter.
	char input = 'r';
	cin.get(input);
	
	 if(input == 'r') 
	 {
       cout<< "You selected the character: " << multNineLetter;
	 }
	 else
	 {
	   cout<< "Please press 'r' !";
	 }
	return 0;

}
