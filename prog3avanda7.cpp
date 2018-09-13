/*
 Overall Score out of 100: 51.5 //-!- Score was 81.5 but applied 30 point late penalty

Grading comments in the code below are marked with //-!-
Not following the naming convention results in 5 pt. Deduction as stated above

 Program execution (55 points total)
 A. 5: Arrow marker moves left or right (on each move)         |
 B. 5: At +5 or -5 points, print message                       | -5 //-!- Does not display message
 C. 5: At +10 or -10 points, print message and end game        |
 D. 10: Display moves history table when toggled on            |
 E. 10: Use 2D array to store moves history table updates      | -5 //-!- Table is not updated correctly
 F.  3: Display previous 3 moves when moves history table on   |
 G.  5: User input of ‘r’ or ‘R’                               | -3 //-!- Does not update table with 16 numbers correctly
 H.  2: User input of ‘x’ or ‘X’                               |
 I.  5: Move number starts at 1 and increments each move       |
 J.  5: Display whether human or computer got the point        | 
 
 Program Style (45 points total):
 A.  5: Followed program naming conventions     | -2.5 //-!- naming convention is prog3netid1netid2.cpp
 B. 10: Meaningful identifier names             | -2
 C. 10: Comments                                | -1 //-!- Missing TA information in header
 D.  5: Functional Decomposition                |
 E. 10: Appropriate data and control structures |
 F.  5: Code Layout                             |
*/

/* ------------------------------------------------
 * 0/1 Guessing Game
 *
 * Class: CS 141, Fall 2017.  Tues 10am and 12pm lab
 * System: MacOS High Sierra, XCode
 * Author: Aditya Vandanapu and Syed Faizanuddin
 *
 * ToDo: Create a guessing game against the computer.
 * -------------------------------------------------
 */

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string.h>
#include <stdio.h>
//#include <malloc.h>

using namespace std;

//This Function is used to print the table
void PrintTable(int (*tab)[8][2],int (*PT)[3][2]) {
    cout << "\t\t  0   1" << endl;
    cout << "\t\t--- ---" << endl;
    cout << "\t000\t  " << (*tab)[0][0] << "   " << (*tab)[0][1] <<endl;
    cout << "\t001\t  " << (*tab)[1][0] << "   " << (*tab)[1][1] <<endl;
    cout << "\t010\t  " << (*tab)[2][0] << "   " << (*tab)[2][1] <<endl;
    cout << "\t011\t  " << (*tab)[3][0] << "   " << (*tab)[3][1] <<endl;
    cout << "\t100\t  " << (*tab)[4][0] << "   " << (*tab)[4][1] <<endl;
    cout << "\t101\t  " << (*tab)[5][0] << "   " << (*tab)[5][1] <<endl;
    cout << "\t110\t  " << (*tab)[6][0] << "   " << (*tab)[6][1] <<endl;
    cout << "\t111\t  " << (*tab)[7][0] << "   " << (*tab)[7][1] <<endl;
    cout << "\tPrevious Three:" <<  (*PT)[0][0] << (*PT)[1][0] << (*PT)[2][0] << ".  Forecast:" << (*tab)[0][0]+(*tab)[1][0]+(*tab)[2][0]+(*tab)[3][0]+(*tab)[4][0]+(*tab)[5][0]+(*tab)[6][0]+(*tab)[7][0] << endl;
}

//This writes the table and prints out the table.
void writedata(unsigned compteur,bool toggleDT, int score,int (*tab)[8][2],int (*PT)[3][2]){
    cout << "Computer          Human" << endl;
    cout << "x---------x+++++++++x" << endl;
    for (unsigned i=0;i<10 + score;i++){
        cout << " ";
    }
    cout << "^" << endl;
    if (toggleDT) {
        PrintTable(tab,PT);
    }
    cout << compteur << ". Your input : ";
}


//This will toggle the table based on user input
void ToggleDataTable(bool * TDT,unsigned compteur) {
    if (compteur > 3) {
        if((*TDT) == false) {
            *TDT = true;
        } else {
            *TDT = false;
        }
    } else {
        cout << "Data table is available from the 4th move";
    }
}

//This will update the score when the user inputs a move.
void UpdateScoreOnce(char input,unsigned * compteur,int * score,int (*PT)[3][2],int (*DT)[8][2]) {
    unsigned computerGuess = rand()%2;
    if(input != '0' && input != '1') {
        cout << "Undifined Choice ! Please try again";
    } else {
        int iinput = (int)input - 48;
        if (iinput == computerGuess) {
            if (*compteur < 4) {
                (*PT)[*compteur - 1][0]= iinput;
                (*PT)[*compteur - 1][1]= 0;
            } else {
                (*PT)[0][0] = (*PT)[1][0];
                (*PT)[1][0] = (*PT)[2][0];
                (*PT)[2][0] = iinput;
                (*PT)[0][1] = (*PT)[1][1];
                (*PT)[1][1] = (*PT)[2][1];
                (*PT)[2][1] = 0;
            }
            (*score)--;
            cout << "\tComputer gets a point."  << endl<< endl;
        } else {
            if (*compteur < 4) {
                (*PT)[*compteur - 1][0]= iinput;
                (*PT)[*compteur - 1][1]= 1;
            } else {
                cout << (*PT)[0][0];
                (*PT)[0][0] = (*PT)[1][0];
                (*PT)[1][0] = (*PT)[2][0];
                (*PT)[2][0] = iinput;
                (*PT)[0][1] = (*PT)[1][1];
                (*PT)[1][1] = (*PT)[2][1];
                (*PT)[2][1] = 1;
            }
            (*score)++;
            cout << "\tHuman gets a point." << endl<< endl;
        }
        if (*compteur > 3) {
            if(( (*PT)[0][1] + (*PT)[1][1] + (*PT)[2][1] ) > 1) {
                (*DT)[((*PT)[0][1] *4)+((*PT)[1][1]*2)+(*PT)[2][1]][1]++;
            } else {
                (*DT)[((*PT)[0][1] *4)+((*PT)[1][1]*2)+(*PT)[2][1]][0]++;
            }
        }
        (*compteur)++;
        if(*score == 10) {
            cout << endl << "Human win" << endl;
        } else if(*score == -10) {
            cout << endl<< "Computer win" << endl;
        }
    }
}

//This function will update the score after thew user enters a move.
void UpdateScore(string input,unsigned * compteur,int * score,bool toggleDT,int (*PT)[3][2],int (*DT)[8][2]) {
    unsigned i =0;
    while(i< input.size()) {
        if(input[i] != '0' && input[i] != '1') {
            break;
        } else {
            i++;
        }
    }
    if(i == input.size()) {
        for(i=0;i<input.size()-1;i++) {
            UpdateScoreOnce(input[i],compteur,score,PT,DT);
            writedata(*compteur, toggleDT,*score,DT,PT);
            if(*score == 10 || *score == -10){
                break;
            }
        }
        if(*score != 10 && *score != -10){
            UpdateScoreOnce(input[i],compteur,score,PT,DT);
        }
    } else {
        cout << "Undifined Choice ! Please try again";
    }
}

//This function will reset the board.
void Reset(int (*DT)[8][2],int * score,unsigned * compteur) {
    char resetStr[32];
    unsigned i,j,k; //-!- Use more meaningful variable names than i,j,k -2
    bool test;
    do {
        cout << "Game Reset" << endl;
        cout << "Please enter 16 single-digit numbers separated by spaces to set the moves :";
        gets(resetStr);
        if(strlen(resetStr) == 31) { 
            i =0;
            while(i< 32) {
                if(i % 2 == 0) {
                    if(!isdigit(resetStr[i]))
                        break;
                    else
                        i++;
                } else {
                    if(resetStr[i] != ' ')
                        break;
                    else
                        i++;
                }
            }
            if(i == 31) {
                test = true;
            } else {
                test = false;
            }
        } else {
            test = false;
        }
    } while(test == false);
    i=0;j=0;
    while(i<16 && j<8){
        (*DT)[0][j]=i;
        i+=2;
        j++;
    }
    j=0;
    while(i<31 && j<8){
        (*DT)[1][j]=i;
        i+=2;
        j++;
    }
    *score = 0;
    *compteur = 1;
    cout << endl << endl;
}

int main()
{
    cout << "Author: Syed Faizanuddin and Aditya Vandanapu " << endl;
    cout << "Lab:   10 am and 12 pm   " << endl;
    cout << "Program: #3, 0/1 Guessing Game" << endl << endl;
    cout << "Welcome to the 0/1 guessing game!" << endl << endl;
    cout << "Enter 0 or 1, trying to outsmart the computer, which is going to" << endl;
    cout << "attempt to forecast your guesses.  On each move the score indicator" << endl;
    cout << "moves to the left if the computer guesses correctly, and moves" << endl;
    cout << "to the right if the computer does not." << endl;
    cout << "\tEnter 't' to toggle displaying the data table." << endl;
    cout << "\tEnter 'r' to reset the board." << endl;
    cout << "\tEnter 'x' to exit." << endl;
    cout << "Good luck, you'll need it!" << endl << endl << endl;
    int DT[8][2];
    for (int n=0; n<8; n++)
        for (int m=0; m<2; m++)
        {
            DT[n][m]=0;
        }
    int PT [3][2];
    bool exit = false;
    char *input=(char *) malloc(sizeof(char));
    unsigned compteur(1);
    int score(0);
    bool toggleDT = false;
    //while loop for the board data and for the game.
    do {
        writedata( compteur, toggleDT,score,&DT,&PT);
        gets(input);
        if (strlen(input) == 1) {
            switch ( input[0] ) {
                case 't':
                    ToggleDataTable(&toggleDT,compteur);
                    break;
                case 'T':
                    ToggleDataTable(&toggleDT,compteur);
                    break;
                case 'r':
                    Reset(&DT,&score,&compteur);
                    break;
                case 'R':
                    Reset(&DT,&score,&compteur);
                    break;
                case 'x':
                    exit = true;
                    break;
                case 'X':
                    exit = true;
                    break;
                default:
                    UpdateScoreOnce(input[0],&compteur,&score,&PT,&DT);
                    break;
            }
        } else {
            UpdateScore(input,&compteur,&score,toggleDT,&PT,&DT);
        }
        if(score == 10 || score == -10) {
            exit=true;
        }
    } while(!exit);
    return 0;
}
