
/* --------------------------------------------------------
 * Traffic.cpp
 *     Text-based version of the game RushHour, where the
 *     object is to move the vehicles such that the small
 *     car can exit the right of the board.
 *
 * Class: Program #2 for CS 141, Fall 2017.
 * Lab: Tuesday, 12pm
 * TA:  Minh Huynh Nguyen
 * System: Mac OS X, Cloud 9
 * Author: Aditya Vandanapu
 */

#include <iostream>
#include <cctype>      // for toupper()
using namespace std;

// Global variables and constants
// Variables to store the board pieces
char  p1, p2, p3, p4, p5, p6,
p7, p8, p9,p10,p11,p12,
p13,p14,p15,p16,p17,p18,
p19,p20,p21,p22,p23,p24,
p25,p26,p27,p28,p29,p30,
p31,p32,p33,p34,p35,p36;

string vehicle;
//--------------------------------------------------------------------
// Display ID info
void displayIDInfo()
{
    cout<< "Author:  Aditya Vandanapu" << endl;
    cout<< "Lab:     Tues 12pm " << endl;
    cout<<"Program: #2, Traffic" << endl;

}//end displayIDInfo()


//--------------------------------------------------------------------
// Display Instructions
void displayInstructions()
{
    cout << "Welcome to the traffic game!                          " << endl
    << "                                                      " << endl
    << "Move the vehicles so that the Red car (RR) can exit   " << endl
    << "the board to the right. Each move should be of the    " << endl
    << "of the form:   CDN   where:                           " << endl
    << "   C  is the vehicle to be moved                      " << endl
    << "   D  is the direction (u=up, d=down, l=left or r=right)" << endl
    << "   N  is the number of squares to move it             " << endl
    << "For example GR2  means move the G vehicle to the right" << endl
    << "2 squares.  Lower-case input such as   gr2  is also   " << endl
    << "accepted.  Enter '-' to reset board, or 'x' to exit.  " << endl;
}//end displayInstructions()



//--------------------------------------------------------------------
// Display the board, using the current values in the global variables.
void displayBoard( )
{
    // Your code should go here, to print out the values in all the
    // p1, p2, ... p36 variables.
    // ...

    cout<< "- - - - - - - -"<< endl;
    cout<< "| " <<p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << " " << p6 << " |" <<endl;
    cout<< "| " <<p7 << " " << p8 << " " << p9 << " " << p10 << " " << p11 << " " << p12 << " |" <<endl;
    cout<< "| " <<p13 << " " << p14 << " " << p15 << " " << p16 << " " << p17 << " " << p18 <<" " <<endl;
    cout<< "| " <<p19 << " " << p20 << " " << p21 << " " << p22 << " " << p23 << " " << p24 <<" |"<<endl;
    cout<< "| " <<p25 << " " << p26 << " " << p27 << " " << p28 << " " << p29 << " " << p30 <<" |" <<endl;
    cout<< "| " <<p31 << " " << p32 << " " << p33 << " " << p34 << " " << p35 << " " << p36 <<" |" <<endl;
    cout<< "- - - - - - - -"<< endl;
}
//end displayBoard()


//--------------------------------------------------------------------
/*  Board and corresponding global variable values are:
 - - - - - - - -
 1 | G G . . . Y |
 7 | P . . B . Y |
 13 | P R R B . Y >
 19 | P . . B . . |
 25 | O . . . T T |
 31 | O . F F F . |
 - - - - - - - -
 */

/* This function controls the direction of G going left,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */
void moveCarGLeft(int reqCount, char car)
{
    int spaceCount = (int) reqCount - 48;

    int availCount = 0;
    if(p6 == 'G' && p5 == 'G'&& p4 == '.' && p3 == '.' && p2 == '.' && p1 == '.')
    {

        availCount = 4;

    }
    else if((p6 == 'G' && p5 == 'G'&& p4 == '.' && p3 == '.' && p2 == '.' ) || ( p5 == 'G'&& p4 == 'G' && p3 == '.' && p2 == '.' && p1 == '.'))
    {
        availCount = 3;
    }

    else if((p6 == 'G' && p5 == 'G'&& p4 == '.' && p3 == '.' ) || ( p5 == 'G'&& p4 == 'G' && p3 == '.' && p2 == '.') || (p4 == 'G' && p3 == 'G' && p2 == '.' && p1 == '.') )
    {
        availCount = 2;
    }
    else if((p6 == 'G' && p5 == 'G'&& p4 == '.') || ( p5 == 'G'&& p4 == 'G' && p3 == '.') || (p4 == 'G' && p3 == 'G' && p2 == '.') || (p3 == 'G' && p2 == 'G' && p1 == '.'))
    {
        availCount = 1;
    }


    cout<<"Space Count is" << spaceCount << endl;

    //If spaceCount is greater than available count, the space count will have to change assignment and execute the vehicle to move.
    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }


    if (spaceCount == 4)
    {
        if(p6 == 'G' && p5 == 'G'&& p4 == '.' && p3 == '.' && p2 == '.' && p1 == '.')
        {
            p6 = '.';
            p5 = '.';
            p4 = '.';
            p3 = '.';
            p2 = 'G';
            p1 = 'G';
        }
    }
    if (spaceCount == 3)
    {
        if(p6 == 'G' && p5 == 'G'&& p4 == '.' && p3 == '.' && p2 == '.' )
        {
            p6 = '.';
            p5 = '.';
            p4 = '.';
            p3 = 'G';
            p2 = 'G';
        }
        else if( p5 == 'G'&& p4 == 'G' && p3 == '.' && p2 == '.' && p1 == '.')
        {
            p5 = '.';
            p4 = '.';
            p3 = '.';
            p2 = 'G';
            p1 = 'G';
        }
    }
    if (spaceCount == 2)
    {
        if(p6 == 'G' && p5 == 'G'&& p4 == '.' && p3 == '.' )
        {
            p6 = '.';
            p5 = '.';
            p4 = 'G';
            p3 = 'G';
        }
        else if( p5 == 'G'&& p4 == 'G' && p3 == '.' && p2 == '.')
        {

            p5 = '.';
            p4 = '.';
            p3 = 'G';
            p2 = 'G';
        }
        else if(p4 == 'G' && p3 == 'G' && p2 == '.' && p1 == '.')
        {
            p4 = '.';
            p3 = '.';
            p2 = 'G';
            p1 = 'G';
        }
    }
    if (spaceCount == 1)
    {
        if(p6 == 'G' && p5 == 'G'&& p4 == '.')
        {
            p6 = '.';
            p5 = 'G';
            p4 = 'G';

        }
        else if( p5 == 'G'&& p4 == 'G' && p3 == '.')
        {

            p5 = '.';
            p4 = 'G';
            p3 = 'G';

        }
        else if(p4 == 'G' && p3 == 'G' && p2 == '.')
        {
            p4 = '.';
            p3 = 'G';
            p2 = 'G';

        }
        else if(p3 == 'G' && p2 == 'G' && p1 == '.')
        {

            p3 = '.';
            p2 = 'G';
            p1 = 'G';
        }
    }
}
/*
 void moveCarRLeft(char spaceCount, char car)
 {

 }
 */

/* This function controls the direction of T going left,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */

void moveCarTLeft(char reqCount, char car)
{
    int spaceCount = (int) reqCount - 48;

    int availCount = 0;
    if(p30 == 'T' && p29 == 'T'&& p28 == '.' && p27 == '.' && p26 == '.' && p25 == '.')
    {
        availCount = 4;

    }
    if((p30 == 'T' && p29 == 'T'&& p28 == '.' && p27 == '.' && p26 == '.' ) || ( p29 == 'T'&& p28 == 'T' && p27 == '.' && p26 == '.' && p25 == '.'))
    {
        availCount = 3;
    }

    if((p29 == 'T' && p28 == 'T' && p27 == '.' && p26 == '.') || (p28 == 'T' && p27 == 'T' && p26 == '.' && p25 == '.'))
    {
        availCount = 2;
    }
    if((p27 == 'T' && p26 == 'T' && p25 == '.') || (p28 == 'T' && p27 == 'T' && p26 == '.'))
    {
        availCount = 1;
    }


    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }

    if (spaceCount == 4)
    {
        if(p30 == 'T' && p29 == 'T'&& p28 == '.' && p27 == '.' && p26 == '.' && p25 == '.')
        {
            p30 = '.';
            p29 = '.';
            p28 = '.';
            p27 = '.';
            p26 = 'T';
            p25 = 'T';
        }
    }
    if (spaceCount == 3)
    {
        if(p30 == 'T' && p29 == 'T'&& p28 == '.' && p27 == '.' && p26 == '.' )
        {
            p30 = '.';
            p29 = '.';
            p28 = '.';
            p27 = 'T';
            p26 = 'T';
        }
        else if( p29 == 'T'&& p28 == 'T' && p27 == '.' && p26 == '.' && p25 == '.')
        {
            p29 = '.';
            p28 = '.';
            p27 = '.';
            p26 = 'T';
            p25 = 'T';
        }
    }
    if (spaceCount == 2)
    {
        if(p30 == 'T' && p29 == 'T'&& p28 == '.' && p27 == '.' )
        {
            p30 = '.';
            p29 = '.';
            p28 = 'T';
            p27 = 'T';
        }
        else if( p29 == 'T'&& p28 == 'T' && p27 == '.' && p26 == '.')
        {

            p29 = '.';
            p28 = '.';
            p27 = 'T';
            p26 = 'T';
        }
        else if(p28 == 'T' && p27 == 'T' && p26 == '.' && p25 == '.')
        {
            p28 = '.';
            p27 = '.';
            p26 = 'T';
            p25 = 'T';
        }
    }
    if (spaceCount == 1)
    {
        if(p30 == 'T' && p29 == 'T'&& p28 == '.')
        {
            p30 = '.';
            p29 = 'T';
            p28 = 'T';

        }
        else if( p29 == 'T'&& p28 == 'T' && p27 == '.')
        {

            p29 = '.';
            p28 = 'T';
            p27 = 'T';

        }
        else if(p28 == 'T' && p27 == 'T' && p26 == '.')
        {
            p28 = '.';
            p27 = 'T';
            p26 = 'T';

        }
        else if(p27 == 'T' && p26 == 'T' && p25 == '.')
        {

            p27 = '.';
            p26 = 'T';
            p25 = 'T';
        }
    }
}
/* This function controls the direction of F going left,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */
void moveCarFLeft(char reqCount, char car)
{
    int spaceCount = (int) reqCount - 48;

    int availCount = 0;

    if(p36 == 'F' && p35 == 'F'&& p34 == 'F' && p33 == '.' && p32== '.' && p31 == '.')
    {
        availCount = 3;
    }
    else if(p36 == 'F' && p35 == 'F'&& p34 == 'F' && p33 == '.' && p32 == '.')
    {
        availCount = 2;
    }


    else if(p35 == 'F' && p34 == 'F' && p33 == 'F' && p32 == '.' && p31 == '.')
    {
        availCount = 2;
    }
    else if((p36 == 'F' && p35 == 'F' && p34 == 'F' && p33 == '.') ||(p35 == 'F' && p34 == 'F' && p33 == 'F' && p32 == '.') || (p34 == 'F' && p33 == 'F' && p32 == 'F' && p31 == '.'))
    {
        availCount = 1;
    }


    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }

    if (spaceCount == 3)
    {
        if(p36 == 'F' && p35 == 'F' && p34 == 'F' && p33 == '.' && p32 == '.' && p31 == '.' )
        {
            p36 = '.';
            p35 = '.';
            p34 = '.';
            p33 = 'F';
            p32 = 'F';
            p31 = 'F';
        }

    }
    if (spaceCount == 2)
    {
        if(p36 == 'F' && p35 == 'F'&& p34 == 'F' && p33 == '.' && p32 == '.')
        {
            p32 = 'F';
            p33 = 'F';
            p34 = 'F';
            p35 = '.';
            p36 = '.';
        }
        else if(p35 == 'F' && p34 == 'F'&& p33 == 'F' && p32 == '.' && p31 == '.')
        {
            p35 = '.';
            p34 = '.';
            p33 = 'F';
            p32 = 'F';
            p31 = 'F';
        }
    }
    if (spaceCount == 1)
    {
        if(p36 == 'F' && p35 == 'F'&& p34 == 'F' && p33 == '.')
        {
            p36 = '.';
            p35 = 'F';
            p34 = 'F';
            p33 = 'F';

        }
        else if( p35 == 'F'&& p34 == 'F' && p33 == 'F' && p32 == '.')
        {

            p35 = '.';
            p34 = 'F';
            p33 = 'F';
            p32 = 'F';

        }
        else if(p34 == 'F' && p33 == 'F' && p32 == 'F' && p31 == '.')
        {
            p34 = '.';
            p33 = 'F';
            p32 = 'F';
            p31 = 'F';

        }

    }

}
//This function describes the user input when the user enters the vehicle for the car that wants to move left.
void moveLeft(char spaceCount, char car)
{
    if (toupper(car) == 'G')
    {
        moveCarGLeft(spaceCount, car);
    }
    else if (toupper(car) == 'T')
    {
        moveCarTLeft(spaceCount, car);
    }
    else if (toupper(car) == 'F')
    {
        moveCarFLeft(spaceCount, car);
    }
}

/* This function controls the direction of G going right,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */

void moveCarGRight(char reqCount, char car)
{
    int spaceCount = (int) reqCount - 48;

    int availCount = 0;

    if(p1 == 'G' && p2 == 'G'&& p3 == '.' && p4 == '.' && p5 == '.' && p6 == '.')
    {
        availCount = 4;

    }
    if((p1 == 'G' && p2 == 'G'&& p3 == '.' && p4 == '.' && p5 == '.' ) || ( p2 == 'G' && p3 == 'G' && p4 == '.' && p5 == '.' && p6 == '.'))
    {
        availCount = 3;
    }

    if((p3 == 'G' && p4 == 'G' && p5 == '.' && p6 == '.') || (p2 == 'G' && p3 == 'G' && p4 == '.' && p5 == '.'))
    {
        availCount = 2;
    }
    if((p4 == 'G' && p5 == 'G' && p6 == '.') || (p3 == 'G' && p4 == 'G' && p5 == '.'))
    {
        availCount = 1;
    }


    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }
    if (spaceCount == 4)
    {
        if(p1 == 'G' && p2 == 'G'&& p3 == '.' && p4 == '.' && p5 == '.' && p6 == '.')
        {
            p1 = '.';
            p2 = '.';
            p3 = '.';
            p4 = '.';
            p5 = 'G';
            p6 = 'G';
        }
    }
    if (spaceCount == 3)
    {
        if(p1 == 'G' && p2 == 'G'&& p3 == '.' && p4 == '.' && p5 == '.' )
        {
            p1 = '.';
            p2 = '.';
            p3 = '.';
            p4 = 'G';
            p5 = 'G';
        }

        else if( p2 == 'T'&& p3 == 'T' && p4 == '.' && p5 == '.' && p6 == '.')
        {
            p2 = '.';
            p3 = '.';
            p4 = '.';
            p5 = 'G';
            p6 = 'G';
        }
    }
    if (spaceCount == 2)
    {
        if(p1 == 'G' && p2 == 'G'&& p3 == '.' && p4 == '.' )
        {
            p1 = '.';
            p2 = '.';
            p3 = 'G';
            p4 = 'G';
        }

        else if( p2 == 'G'&& p3 == 'G' && p4 == '.' && p5 == '.')
        {

            p2 = '.';
            p3 = '.';
            p4 = 'G';
            p5 = 'G';
        }

        else if(p3 == 'G' && p4 == 'G' && p5 == '.' && p6 == '.')
        {
            p3 = '.';
            p4 = '.';
            p5 = 'G';
            p6 = 'G';
        }
    }
    if (spaceCount == 1)
    {
        if(p1 == 'G' && p2 == 'G'&& p3 == '.')
        {
            p1 = '.';
            p2 = 'G';
            p3 = 'G';

        } else if( p2 == 'G'&& p3 == 'G' && p4 == '.')
        {

            p2 = '.';
            p3 = 'G';
            p4 = 'G';

        }

        else if(p3 == 'G' && p4 == 'G' && p5 == '.')
        {
            p3 = '.';
            p4 = 'G';
            p5 = 'G';

        }

        else if(p4 == 'G' && p5 == 'G' && p6 == '.')
        {

            p4 = '.';
            p5 = 'G';
            p6 = 'G';
        }
    }
}

/* This function controls the direction of R going right,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */

void moveCarRRight(char reqCount, char car)
{
    int spaceCount = (int) reqCount - 48;

    int availCount = 0;
    if(p14 == 'R' && p15 == 'R'&& p16 == '.' && p17 == '.' && p18 == '.' )
    {
        availCount = 3;
    }
    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }
    if (spaceCount == 3)
    {
        if(p14 == 'R' && p15 == 'R'&& p16 == '.' && p17 == '.' && p18 == '.' )
        {
            p14 = '.';
            p15 = '.';
            p16 = '.';
            p17 = 'R';
            p18 = 'R';


        }
    }
}

/* This function controls the direction of T going right,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */

void moveCarTRight(char reqCount, char car)
{
    int spaceCount = (int) reqCount - 48;

    int availCount = 0;

    if(p25 == 'T' && p26 == 'T'&& p27 == '.' && p28 == '.' && p29 == '.' && p30 == '.')
    {
        availCount = 4;

    }
    else if((p25 == 'T' && p26 == 'T'&& p27 == '.' && p28 == '.' && p29 == '.' ) || ( p26 == 'T'&& p27 == 'T' && p28 == '.' && p29 == '.' && p30 == '.'))
    {
        availCount = 3;
    }

    else if ( (p25 == 'T' && p26 == 'T' && p27 == '.' && p28 == '.') || (p26 == 'T' && p27 == 'T' && p28 == '.' && p29 == '.') || (p27 == 'T' && p28 == 'T' && p29 == '.' && p30 == '.'))
    {
        availCount = 2;
    }
    else if( (p25 == 'T' && p26 == 'T' && p27 == '.' ) || (p26 == 'T' && p27 == 'T' && p28 == '.') || (p27 == 'T' && p28 == 'T' && p29 == '.') || (p28 == 'T' && p29 == 'T' && p30 == '.'))
    {
        availCount = 1;
    }


    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }

    if (spaceCount == 4)
    {
        if(p30 == 'T' && p29 == 'T'&& p28 == '.' && p27 == '.' && p26 == '.' && p25 == '.')
        {
            p30 = '.';
            p29 = '.';
            p28 = '.';
            p27 = '.';
            p26 = 'T';
            p25 = 'T';
        }
    }
    if (spaceCount == 3)
    {
        if(p30 == '.' && p29 == '.'&& p28 == '.' && p27 == 'T' && p26 == 'T' )
        {
            p30 = 'T';
            p29 = 'T';
            p28 = '.';
            p27 = '.';
            p26 = '.';
        }
        else if( p29 == 'T'&& p28 == 'T' && p27 == '.' && p26 == '.' && p25 == '.')
        {
            p29 = '.';
            p28 = '.';
            p27 = '.';
            p26 = 'T';
            p25 = 'T';
        }
    }
    if (spaceCount == 2)
    {
        if(p25 == 'T' && p26 == 'T'&& p27 == '.' && p28 == '.' )
        {
            p25 = '.';
            p26 = '.';
            p27 = 'T';
            p28 = 'T';
        }

        else if( p26 == 'T'&& p27 == 'T' && p28 == '.' && p29 == '.')
        {

            p26 = '.';
            p27 = '.';
            p28 = 'T';
            p29 = 'T';
        }

        else if(p27 == 'T' && p28 == 'T' && p29 == '.' && p30 == '.')
        {
            p27 = '.';
            p28 = '.';
            p29 = 'T';
            p30 = 'T';
        }
    }
    if (spaceCount == 1)
    {
        if(p25 == 'T' && p26 == 'T'&& p27 == '.')
        {
            p25 = '.';
            p26 = 'T';
            p27 = 'T';

        }
        else if( p26 == 'T'&& p27 == 'T' && p28 == '.')
        {

            p26 = '.';
            p27 = 'T';
            p28 = 'T';

        }
        else if(p27 == 'T' && p28 == 'T' && p29 == '.')
        {
            p27 = '.';
            p28 = 'T';
            p29 = 'T';

        }
        else if(p28 == 'T' && p29 == 'T' && p30 == '.')
        {

            p28 = '.';
            p29 = 'T';
            p30 = 'T';
        }
    }

}

/* This function controls the direction of F going Right,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */

void moveCarFRight(char reqCount, char car)
{

    int spaceCount = (int) reqCount - 48;

    int availCount = 0;

    if(p31 == 'F' && p32 == 'F'&& p33 == 'F' && p34 == '.' && p35 == '.' && p36 == '.')
    {
        availCount = 3;
    }
    else if(p31 == 'F' && p32 == 'F'&& p33 == 'F' && p34 == '.' && p35 == '.')
    {
        availCount = 2;
    }

    else if(p32 == 'F' && p33 == 'F' && p34 == 'F' && p35 == '.' && p36 == '.')
    {
        availCount = 2;
    }
    else if((p31 == 'F' && p32 == 'F' && p33 == 'F' && p34 == '.') ||(p32 == 'F' && p33 == 'F' && p34 == 'F' && p35 == '.') || (p33 == 'F' && p34 == 'F' && p35 == 'F' && p36 == '.'))
    {
        availCount = 1;
    }


    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }

    if (spaceCount == 3)
    {
        if(p31 == 'F' && p32 == 'F' && p33 == 'F' && p34 == '.' && p35 == '.' && p36 == '.' )
        {
            p31 = '.';
            p32 = '.';
            p33 = '.';
            p34 = 'F';
            p35 = 'F';
            p36 = 'F';
        }

    }
    if (spaceCount == 2)
    {
        if(p31 == 'F' && p32 == 'F'&& p33 == 'F' && p34 == '.' && p35 == '.')
        {
            p31 = '.';
            p32 = '.';
            p33 = 'F';
            p34 = 'F';
            p35 = 'F';
        }
        else if(p32 == 'F' && p33 == 'F'&& p34 == 'F' && p35 == '.' && p36 == '.')
        {
            p32 = '.';
            p33 = '.';
            p34 = 'F';
            p35 = 'F';
            p36 = 'F';
        }
    }
    if (spaceCount == 1)
    {
        if(p31 == 'F' && p32 == 'F'&& p33 == 'F' && p34 == '.')
        {
            p31 = '.';
            p32 = 'F';
            p33 = 'F';
            p34 = 'F';
        }
        else if( p32 == 'F'&& p33 == 'F' && p34 == 'F' && p35 == '.')
        {
            p32 = '.';
            p33 = 'F';
            p34 = 'F';
            p35 = 'F';
        }
        else if(p33 == 'F' && p34 == 'F' && p35 == 'F' && p36 == '.')
        {
            p33 = '.';
            p34 = 'F';
            p35 = 'F';
            p36 = 'F';

        }

    }
}

//This function describes the user input when the user enters a vehicle that can move right.
void moveRight(char spaceCount, char car)
{
    if (toupper(car) == 'G')
    {
        moveCarGRight(spaceCount, car);
    }
    else if(toupper(car) == 'R')
    {
        moveCarRRight(spaceCount, car);
    }
    else if (toupper(car) == 'T')
    {
        moveCarTRight(spaceCount, car);
    }
    else if (toupper(car) == 'F')
    {
        moveCarFRight(spaceCount, car);
    }
}

/* This function controls the direction of P going up,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */

void moveCarPUp(char reqCount, char car)
{

    int spaceCount = (int) reqCount - 48;
    int availCount = 0;

    if(p1 == '.' && p7 == 'P' && p13 == 'P' && p19 == 'P')
    {
        availCount = 1;
    }

    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }

    if(spaceCount == 1)
    {
        if(p1 == '.' && p7 == 'P'&& p13 == 'P' && p19 == 'P')
        {
            p1 = 'P';
            p7 = 'P';
            p13 = 'P';
            p19 = '.';
        }
    }
}

/* This function controls the direction of O going up,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */

void moveCarOUp(char reqCount, char car)
{
    int spaceCount = (int) reqCount - 48;
    int availCount = 0;

    if(p19 == '.' && p25 == 'O' && p31 == 'O')
    {
        availCount = 1;
    }

    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }

    if(spaceCount == 1)
    {
        if(p19 == '.' && p25 == 'O'&& p31 == 'O')
        {
            p19 = 'O';
            p25 = 'O';
            p31 = '.';

        }
    }
}

/* This function controls the direction of B going Up,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */

void moveCarBUp(char reqCount, char car)
{
    int spaceCount = (int) reqCount - 48;
    int availCount = 0;

    if(p4 == '.' && p10 == '.' && p16 == '.' && p22 == 'B' && p28 == 'B' && p34 == 'B')
    {
        availCount = 3;
    }
    if((p4 == '.' && p10 == 'B' && p16 == 'B' && p22 == 'B') || (p10 == '.' && p16 == '.' && p22 == 'B' && p28 == 'B' && p34 == 'B'))
    {
        availCount = 2;
    }
    if((p4 == '.' && p10 == 'B' && p16 == 'B' && p22 == 'B' && p28 == '.' && p34 == '.') || (p10 == '.' && p16 == 'B' && p22 == 'B' && p28 == 'B' && p34 == '.') )
    {
        availCount = 1;
    }

    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }

    if(spaceCount == 3)
    {
        if(p4 == '.' && p10 == '.'&& p16 == '.' && p22 == 'B' && p28 == 'B' && p34 == 'B')
        {
            p4 = 'B';
            p10 = 'B';
            p16 = 'B';
            p22 = '.';
            p28 = '.';
            p34 = '.';

        }
    }
    if(spaceCount == 2)
    {
        if(p4 == '.' && p10 == '.'&& p16 == 'B' && p22 == 'B' && p28 == 'B' && p34 == '.' )
        {
            p4 = 'B';
            p10 = 'B';
            p16 = 'B';
            p22 = '.';
            p28 = '.';
            p34 = '.';

        }
        if(p10 == '.' && p16 == '.' && p22 == 'B' && p28 == 'B' && p34 == 'B')
        {
            p10 = 'B';
            p16 = 'B';
            p22 = 'B';
            p28 = '.';
            p34 = '.';
        }
    }
    if(spaceCount == 1)
    {
        if(p4 == '.' && p10 == 'B'&& p16 == 'B' && p22 == 'B' && p28 == '.' && p34 == '.')
        {
            p4 = 'B';
            p10 = 'B';
            p16 = 'B';
            p22 = '.';
            p28 == '.';
            p34 == '.';

        }
        if(p4 == '.' && p10 == '.'&& p16 == 'B' && p22 == 'B' && p28 == 'B' && p34 == '.')
        {
            p4 = '.';
            p10 = 'B';
            p16 = 'B';
            p22 = 'B';
            p28 == '.';
            p34 == '.';
        }
    }
}

/* This function controls the direction of Y going up,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */

void moveCarYUp(char reqCount, char car)
{
    int spaceCount = (int) reqCount - 48;
    int availCount = 0;

    if(p6 == '.' && p12 == '.' && p18 == '.' && p24 == 'Y' && p30 == 'Y' && p36 == 'Y')
    {
        availCount = 3;
    }
    if(p4 == '.' && p10 == '.' && p16 == 'Y' && p22 == 'Y' && p28 == 'Y' && p36 == '.')
    {
        availCount = 2;
    }
    if((p4 == '.' && p10 == 'Y'&& p16 == 'Y' && p22 == 'Y' && p28 == '.' && p36 == '.' ) || (p6 == '.' && p12 == 'Y'&& p18 == 'Y' && p24 == 'Y'))
    {
        availCount = 1;
    }

    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }

    if(spaceCount == 3)
    {
        if(p6 == '.' && p12 == '.'&& p18 == '.' && p24 == 'Y' && p30 == 'Y' && p36 == 'Y')
        {
            p6 = 'Y';
            p12 = 'Y';
            p18 = 'Y';
            p24 = '.';
            p30 = '.';
            p36 = '.';

        }
    }
    if(spaceCount == 2)
    {
        if(p6 == '.' && p12 == '.' && p18 == 'Y' && p24 == 'Y' && p30 == 'Y' && p36 == '.' )
        {
            p6 = 'Y';
            p12 = 'Y';
            p18 = 'Y';
            p24 = '.';
            p30 = '.';
            p36 = '.';

        }
    }
    if(spaceCount == 1)
    {
        if(p6 == '.' && p12 == 'Y'&& p18 == 'Y' && p24 == 'Y' && p30 == '.' && p36 == '.')
        {
            p6 = 'Y';
            p12 = 'Y';
            p18 = 'Y';
            p24 = '.';
            p30 = '.';
            p36 = '.';

        }
        else if(p6 == '.' && p12 == 'Y'&& p18 == 'Y' && p24 == 'Y')
        {
            p6 = 'Y';
            p12 = 'Y';
            p18 = 'Y';
            p24 = '.';


        }
    }
}

//This function is utilized when the user inputs a letter that has capabilities to move up.
void moveUp(char spaceCount, char car)
{

    if (toupper(car) == 'P')
    {
        moveCarPUp(spaceCount, car);
    }
    else if(toupper(car) == 'O')
    {
        moveCarOUp(spaceCount, car);
    }
    else if (toupper(car) == 'B')
    {
        moveCarBUp(spaceCount, car);
    }
    else if (toupper(car) == 'Y')
    {
        moveCarYUp(spaceCount, car);
    }
}

/* This function controls the direction of P going down,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */

void moveCarPDown(char reqCount, char car)
{
    int spaceCount = (int) reqCount - 48;
    int availCount = 0;

    if(p1 == 'P' && p7 == 'P' && p13 == 'P' && p19 == '.')
    {
        availCount = 1;
    }

    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }

    if(spaceCount == 1)
    {
        if(p1 == 'P' && p7 == 'P'&& p13 == 'P' && p19 == '.')
        {
            p1 = '.';
            p7 = 'P';
            p13 = 'P';
            p19 = 'P';

        }
    }
}

/* This function controls the direction of O going down,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */

void moveCarODown(char reqCount, char car)
{
    int spaceCount = (int) reqCount - 48;
    int availCount = 0;

    if(p19 == 'O' && p25 == 'O' && p31 == '.')
    {
        availCount = 1;
    }

    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }

    if(spaceCount == 1)
    {
        if(p19 == 'O' && p25 == 'O'&& p31 == '.')
        {
            p19 = '.';
            p25 = 'O';
            p31 = 'O';

        }
    }
}

/* This function controls the direction of B going Down,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */

void moveCarBDown(char reqCount, char car)
{
    int spaceCount = (int) reqCount - 48;
    int availCount = 0;

    if(p4 == 'B' && p10 == 'B' && p16 == 'B' && p22 == '.' && p28 == '.' && p34 == '.')
    {
        availCount = 3;
    }
    else if(p4 == '.' && p10 == 'B' && p16 == 'B' && p22 == 'B' && p28 == '.' && p34 == '.')
    {
        availCount = 2;
    }
    else if( p10 == 'B' && p16 == 'B' && p22 == 'B' && p28 == '.' && p34 == '.')
    {
        availCount = 2;
    }
    else if(p4 == '.' && p10 == 'B'&& p16 == 'B' && p22 == 'B' && p28 == '.')
    {
        availCount = 1;
    }

    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }

    if(spaceCount == 3)
    {
        if(p4 == 'B' && p10 == 'B'&& p16 == 'B' && p22 == '.' && p28 == '.' && p34 == '.')
        {
            p4 = '.';
            p10 = '.';
            p16 = '.';
            p22 = 'B';
            p28 = 'B';
            p34 = 'B';

        }
    }
    if(spaceCount == 2)
    {
        if(p4 == '.' && p10 == 'B'&& p16 == 'B' && p22 == 'B' && p28 == '.' && p34 == '.' )
        {
            p4 = '.';
            p10 = '.';
            p16 = '.';
            p22 = 'B';
            p28 = 'B';
            p34 = 'B';

        }
        if( p10 == 'B'&& p16 == 'B' && p22 == 'B' && p28 == '.' && p34 == '.')
        {
            p10 = '.';
            p16 = '.';
            p22 = 'B';
            p28 = 'B';
            p34 = 'B';
        }
    }
    if(spaceCount == 1)
    {
        if(p4 == '.' && p10 == '.'&& p16 == 'B' && p22 == 'B' && p28 == 'B' && p34 == '.')
        {
            p4 = '.';
            p10 = '.';
            p16 = '.';
            p22 = 'B';
            p28 = 'B';
            p34 = 'B';

        }
    }
}

/* This function controls the direction of Y going Down,
 and shows the available number of spaces for the car to make a place into the empty spots. */
/* reqCount describes the number of spaces the car needs to move, spaceCount shows how many spaces the user can go, and char car represents the vehicle. */

void moveCarYDown(char reqCount, char car)
{
    int spaceCount = (int) reqCount - 48;
    int availCount = 0;

    if(p6 == 'Y' && p12 == 'Y' && p18 == 'Y' && p24 == '.' && p30 == '.' && p36 == '.')
    {
        availCount = 3;
    }
    else if((p6 == '.' && p12 == 'Y' && p18 == 'Y' && p24 == 'Y' && p30 == '.' && p36 == '.') || (p6 == 'Y' && p12 == 'Y'&& p18 == 'Y' && p24 == '.' && p30 == '.' ))
    {
        availCount = 2;
    }
    else if((p6 == '.' && p12 == '.'&& p18 == 'Y' && p24 == 'Y' && p30 == 'Y' && p36 == '.' ) || (p6 == 'Y' && p12 == 'Y'&& p18 == 'Y' && p24 == '.'))
    {
        availCount = 1;
    }

    if(spaceCount > availCount)
    {
        spaceCount = availCount;
        cout<<"*** Move was attempted, but couldn't be completed. *** " << endl;
    }


    if(spaceCount == 3)
    {
        if(p6 == 'Y' && p12 == 'Y'&& p18 == 'Y' && p24 == '.' && p30 == '.' && p36 == '.')
        {
            p6 = '.';
            p12 = '.';
            p18 = '.';
            p24 = 'Y';
            p30 = 'Y';
            p36 = 'Y';
        }
    }
    if(spaceCount == 2)
    {
        if(p6 == '.' && p12 == 'Y'&& p18 == 'Y' && p24 == 'Y' && p30 == '.' && p36 == '.')
        {
            p6 = '.';
            p12 = '.';
            p18 = '.';
            p24 = 'Y';
            p30 = 'Y';
            p36 = 'Y';

        }
        else if(p6 == 'Y' && p12 == 'Y'&& p18 == 'Y' && p24 == '.' && p30 == '.' )
        {
            p6 = '.';
            p12 = '.';
            p18 = 'Y';
            p24 = 'Y';
            p30 = 'Y';


        }
    }
    if(spaceCount == 1)
    {
        if(p6 == '.' && p12 == '.'&& p18 == 'Y' && p24 == 'Y' && p30 == 'Y' && p36 == '.')
        {
            p6 = '.';
            p12 = '.';
            p18 = '.';
            p24 = 'Y';
            p30 = 'Y';
            p36 = 'Y';
        }
        else if(p6 == 'Y' && p12 == 'Y'&& p18 == 'Y' && p24 == '.' && p30 == '.' && p36 == '.')
        {
            p6 = '.';
            p12 = 'Y';
            p18 = 'Y';
            p24 = 'Y';
            p30 = '.';
            p36= '.';

        }
    }
}

//This function shows that when the user inputs a vehicle that has the capability of
//moving down, it will call this function.
void moveDown(char spaceCount, char car)
{
    //cout<<"In Move Right function" << endl;
    if (toupper(car) == 'P')
    {
        moveCarPDown(spaceCount, car);
    }
    else if(toupper(car) == 'O')
    {
        moveCarODown(spaceCount, car);
    }
    else if (toupper(car) == 'B')
    {
        moveCarBDown(spaceCount, car);
    }
    else if (toupper(car) == 'Y')
    {
        moveCarYDown(spaceCount, car);
    }
}



int main()
{
    // Declare your variables here
    // ...
    //Max number of moves a user can make.
    const int MOVE = 500;

    displayIDInfo();        // Display ID info
    displayInstructions();  // Display game instructions

    // Set the board values
    p1='G'; p2='G'; p3='.'; p4='.'; p5='.'; p6='Y';
    p7='P'; p8='.'; p9='.';p10='B';p11='.';p12='Y';
    p13='P';p14='R';p15='R';p16='B';p17='.';p18='Y';
    p19='P';p20='.';p21='.';p22='B';p23='.';p24='.';
    p25='O';p26='.';p27='.';p28='.';p29='T';p30='T';
    p31='O';p32='.';p33='F';p34='F';p35='F';p36='.';

    // Display the initial board
    displayBoard();    // you must fill in that function for this to work

    //For loop is used to display the board continuously until the user wins the game.
    for(int i = 1; i <= MOVE; i++)
    {
        cout<< i << "." << "Your move ->  ";
        getline(cin, vehicle);

        //These if statement shows that when a user inputs X, the game will break
        if(vehicle.at(0) == 'x' || vehicle.at(0) == 'X')
        {
            cout<<"Thanks for playing. Don't come back!" << endl;
            return 0;
        }

        string abc="x";

        //if the user enters a certain character it will call the command and the vehicle would move.

        if(vehicle.at(1) == 'l' || vehicle.at(1) == 'L')
        {

            moveLeft(vehicle.at(2), vehicle.at(0));
        }

        if(vehicle.at(1) == 'r' || vehicle.at(1) == 'R')
        {

            moveRight(vehicle.at(2), vehicle.at(0));
        }
        if(vehicle.at(1) == 'u' || vehicle.at(1) == 'U')
        {
            moveUp(vehicle.at(2), vehicle.at(0));
        }
        if(vehicle.at(1) == 'd' || vehicle.at(1) == 'D')
        {
            moveDown(vehicle.at(2), vehicle.at(0));
        }
        // If the R vehicle is at position p18 and p17,
        //then it will show the comment and break the program.
        if(p18 == 'R' && p17 == 'R')
        {
            displayBoard();
            cout << "**** Congratulations!! You did it ****" << endl;
            break;
        }
        displayBoard();
    }
    // You should add more code here, and will likely also need to create some functions.
    // ...


    cout << endl;
    cout << "Thank you for playing.  Exiting..." << endl;

    return 0;
}//end main()
