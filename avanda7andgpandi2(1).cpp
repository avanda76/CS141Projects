




// Graphics demo program for getting started with QtCreator
//
#include <cctype>       // For the letter checking functions
#include <fstream>        // For file input
#include <iostream>
#include <cstring> // For string based input
#include "gobjects.h"  // For all graphics objects
using namespace std;

//Global constants
#define VALID_COLORS "RBGMCYOP" // Displays valid colors red, blue, green, magenta, cyan, yellow, orange, pink
#define VALID_DIRECTIONS "LRUD" // Displays valid directions left, right, up, down

//Shows all the vehicle functions and values. We need to make a class in order to show an object of a vehicle.
class Vehicle
{


    public:
        //Constructor
        Vehicle(char color , char direction, int row, int column, int length);
        //static void displayInstructions();
        //static void displayIDInfo();
        void move(char direction, int howFar);
        void shadedOverRectangle();
        void reset();
        void exit();
        void invalidInput();
        void wrongDirection();
        void pieceOnEdge();

        // Makes the variables reset to 0 or nothing
        void setEmpty()
        {
            color = ' ';
            orientation = ' ';
            row = 0;
            column = 0;
            length = 0;
        }

        char getColor(){return color;} // gets valid color
        char getOrientation(){return orientation;} // gets valid position
        int getColumn(){return column;} // gets column
        int getRow(){return row;} // gets row
        int getLength(){return length;} // gets valid length
        GRect *gamepiece;

    //Defines column, row, length, orientation
    private:

       void createCar();
       char color;
       //Char direction;
       int column;
       int row;
       int length;
       char orientation;



};

    // Copy constructor
    Vehicle::Vehicle(char color , char orientation, int row, int column, int length)
    {
        this->color = color;
        this->orientation = orientation;
        this->column = column;
        this->row = row;
        this->length = length;
        createCar();
    }

    //Method to create the vehicle
    void Vehicle::createCar()
    {
        //Placeholders for the rectangles direction
        int width = 0;
        int height = 0;
        gamepiece = new GRect(row, column, width, height);

    }

    // Definition of which direction vehicle moves
    void Vehicle::move(char direction, int howFar)
     {

          //Direction of the vehicle is determined by how the vehicle moves in a specific direction.
         if(direction == 'R')
         {
             column = column + howFar;
         }
         if(direction == 'L')
         {
             column = column - howFar;
         }
         if(direction == 'U')
         {
             row = row - howFar;
         }
         if(direction == 'D')
         {
             row = row + howFar;
         }


     }






//--------------------------------------------------------------------
// Display ID info
void displayIDInfo()
{
    cout<<"Author:  Gokulraj Pandiyaraj  and Aditya Vandanapu"<<endl;
    cout<<"Lab:     Tues 11am   and 12 pm"<<endl;
    cout<<"Program: #2, Traffic"<<endl;
    cout<<"                    "<<endl;
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

//--------------------------------------------------------------------------------------------//

void drawBoard(Vehicle *cars[], int carCount, GWindow graphicsWindow)
{
    // Create a graphics window, which will be used to draw graphical shapes

    graphicsWindow.setWindowTitle("CS 141: Prog 4 Graphical Traffic");

  GRect *rectangle8 = new GRect(10, 10, 270, 270);
  rectangle8->setFilled(true);
  rectangle8->setColor("darkGray");
  // Add it to the graphics window.  Without this it will exist, but will not show up.
  graphicsWindow.add(rectangle8);

  GRect *rectangle9 = new GRect(20, 20, 250, 250);
  rectangle9->setFilled(true);
  rectangle9->setColor("gray");
  // Add it to the graphics window.  Without this it will exist, but will not show up.
  graphicsWindow.add(rectangle9);

  GRect *rectangle10 = new GRect(270, 100, 10, 50);
  rectangle10->setFilled(true);
  rectangle10->setColor("lightGray");
  // Add it to the graphics window.  Without this it will exist, but will not show up.
  graphicsWindow.add(rectangle10);

  int xPos = 20;
  int yPos = 20;
//Vertical lines
  for(int i = 0; i < 7; i++)
  {
     GRect *column = new GRect(xPos, yPos, 10, 250);
     column->setFilled(true);
     column->setColor("lightGray");
     graphicsWindow.add(column);
     xPos +=40;

  }

   xPos = 20;
   yPos = 20;
//Horizontal lines
  for(int i = 0; i < 7; i++)
  {
     GRect *row = new GRect(xPos, yPos, 250, 10);
     row->setFilled(true);
     row->setColor("lightGray");

     graphicsWindow.add(row);
     yPos += 40;
  }

  //Draws the gamepieces
  for(int i = 0; i < carCount; i++)
  {

      int xCor = 0;
      xCor = 30 + ((cars[i]->getColumn() - 1) * 40);
      int yCor = 0;
      yCor =  30 + ((cars[i]->getRow() - 1) * 40);
      int width = 0;

      int height = 0;
//Find out height and width based orientation
    if(cars[i]->getOrientation() == 'H')
      {
       width = (40*cars[i]->getLength()) - 10;
       height = 30;
      }
    if(cars[i]->getOrientation() == 'V')
      {
       width = 30;
       height = (40*cars[i]->getLength()) - 10;
      }
      GRect *rectangle1 = new GRect(xCor, yCor, width, height);
      rectangle1->setFilled(true);
      string rect_color;

      // Displays the colors of the user's gampieces
      switch(cars[i]->getColor())
      {
          case('G'): rect_color = "GREEN"; break;
          case('Y'): rect_color = "YELLOW"; break;
          case('M'): rect_color = "MAGENTA"; break;
          case('R'): rect_color = "RED"; break;
          case('B'): rect_color = "BLUE"; break;
          case('O'): rect_color = "ORANGE"; break;
          case('C'): rect_color = "CYAN"; break;
          case('P'): rect_color = "PINK"; break;
          default:   rect_color = "GRAY"; break;

      }
      rectangle1->setColor(rect_color);
      // Add it to the graphics window.  Without this it will exist, but will not show up.
      graphicsWindow.add(rectangle1);
 }
  graphicsWindow.requestFocus();
  // Close the windows, first the graphics window, then the console window.
  graphicsWindow.requestFocus();


}

// Allows user input to enter both uppercase and lowercase letters
void convertToUpperCase(string &userInput)
{
    int i = 0;
    do
    {
     userInput[i] = toupper(userInput[i]);
     i++;
    }
    while(i < userInput.length());

}

// Shows if cars will collide each other or not.
char checkCollide(Vehicle *moveCar,int howfar,char direction,Vehicle *allCars[], int numOfCars)
{
    char checkFlag;
int allCar_XCor;
int allCar_YCor;
int moveCar_XCor = moveCar->getRow();
int moveCar_YCor = moveCar->getColumn();

//Move car based on directions right, left, up, down
if (direction == 'R')
{
    moveCar_YCor = moveCar_YCor + moveCar->getLength() + howfar - 1;

}
if (direction == 'L')
{
    moveCar_YCor = moveCar_YCor -  howfar;

}
if (direction == 'U')
{
    moveCar_XCor = moveCar_XCor - howfar;

}
if (direction == 'D')
{
    moveCar_XCor = moveCar_XCor + moveCar->getLength() + howfar - 1;

}

 //For loop end for all Car per length
for (int m = 0; m < moveCar->getLength(); m++)
{
    for(int i = 0; i < numOfCars; i++)
    {
    // If same color then goto next car
    if (allCars[i]->getColor() == moveCar->getColor())
    {
    continue;
    }

    allCar_XCor = allCars[i]->getRow();
    allCar_YCor = allCars[i]->getColumn();

    //For loop to check if the cars collide
for (int n = 0; n < allCars[i]->getLength(); n++)
{
    if((allCar_XCor == moveCar_XCor) && (allCar_YCor == moveCar_YCor))
     {
        //check error
        checkFlag = 'y';
        return checkFlag;
        // exit;
     }

// Shows which car pieces move horizontal or vertical
    if (allCars[i]->getOrientation() == 'H')
    {
        allCar_YCor = allCar_YCor + 1;
    }
    else
    {
         allCar_XCor = allCar_XCor + 1;
    }

    }
}
//Calculate X, Y coordination for each move based on orientation and direction
    if (moveCar->getOrientation() == 'H' && direction == 'R')
    {
         moveCar_YCor = moveCar_YCor - 1;
    }
    else if (moveCar->getOrientation() == 'V' && direction == 'D')
    {
        moveCar_XCor = moveCar_XCor - 1;
    }
    else if (moveCar->getOrientation() == 'H' && direction == 'L')
    {
        moveCar_YCor = moveCar_YCor + 1;
    }
    else if (moveCar->getOrientation() == 'V' && direction == 'U')
    {
        moveCar_XCor = moveCar_XCor + 1;
    }

    }
    return checkFlag;
}

int main()
{
    ifstream inputFileStream;  // Declare the input file stream
    string userInput; // Gets valid input from user
    int carCount; // Number of Cars
    inputFileStream.open("board.txt"); // Information from board.txt is used for reset
    inputFileStream>> carCount;
    Vehicle* cars[carCount]; // Define (multiple) cars objects based on class Vehicle
    char gameover = ' ';
    char error = ' ';
    int counter = 0; // Tells the number of times user plays the game

    cout << "Welcome to CS 141" << endl;
    cout << "This program is a graphical traffic program \n"
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

  GWindow graphicsWindow(300, 300);   // Set the size

    // Open input file and verify
      if( !inputFileStream.is_open())
      {
        cout << "Could not find input file.  Exiting..." << endl;
        exit( -1);
      }

      for(int i = 0; i < carCount; i++)
      {
          char color, direction;
           int column, row, length;
           inputFileStream >> color >> direction >> row >> column >> length;
/* Gets user input based on color,
  direction, row, column, length
  */
           cars[i] = new Vehicle(color, direction, row, column, length);
      }

    drawBoard(cars, carCount, graphicsWindow);

 // Game can keep going continously when there are no errors
 while(gameover == ' ')
 {
        error = ' ';
        counter++; // Increases the number of times user plays the game
        userInput = " ";
        cout << counter<<". Your move -> ";
        cin >> userInput;
        convertToUpperCase(userInput); // Allows user to enter both uppercase and lowercase inputs
        cout << "userInput-" << userInput << endl;

    // Will end the game when typed exit
    if(userInput == "EXIT")
    {
        break;
    }

//Resets the boards and makes the loop startover
    else if(userInput == "RESET")
    {
        for(int i = 0; i < carCount; i++)
        {
            cars[i]->setEmpty();

        }

    drawBoard(cars, carCount, graphicsWindow);

    cout << "Enter the information for the new board, in the same format as the board.txt file " << endl;
    cin >> carCount; // user enters new information

// Accepts the new information direction, color, row, column, length
        for(int i = 0; i < carCount; i++)
        {
            char color, direction;
            int row, column, length;
            cin >> color >> direction >> row >> column >> length;
            cars[i] = new Vehicle(color, direction, row, column, length);
            drawBoard(cars, carCount, graphicsWindow);

        }
    }
    else
    {
        char color = userInput.at(0);
// Vehicle letter input is not a valid color.
        if(strchr(VALID_COLORS, color) == NULL)
        {
              cout << "*** User input is not one of the valid color or action items.  Please retry." << endl;
              continue;
        }
        char direction = userInput.at(1);
// Vehicle letter input is not a valid direction.
        if(strchr(VALID_DIRECTIONS, direction) == NULL)
        {
            cout << "*** User input is not one of the valid direction or action items.  Please retry." << endl;
            continue;
        }
        int howfar = userInput.at(2) - '0';
        int row_next = 1; int col_next = 1;

        for(int i = 0; i < carCount; i++)
        {

            if(color == cars[i]->getColor())
            {

//Move cars in horizontal only to Right or Left only
//Move cars in vertical only to Up or Down
               if(cars[i]->getOrientation() == 'V')
                {
                    if(direction == 'R' || direction == 'L')
                    {
                         error = 'y';
                    }
                }
            else
            {
                if(direction == 'U' || direction == 'D')
                {
                        error = 'y';
                }
            }
//Any error then go to next input
            if(error == 'y')
            {
                break;
            }
//Calculate next (after move) row and column for first block
            if(direction == 'R')
            {
                row_next = cars[i]->getColumn() + howfar;
                row_next = row_next + cars[i]->getLength() - 1;
            }

            if(direction == 'L')
            {
                row_next = cars[i]->getColumn() - howfar;

            }
            if(direction == 'U')
            {
                col_next = cars[i]->getRow() - howfar;

            }
            if(direction == 'D')
            {
                col_next = cars[i]->getRow() + howfar;
                col_next = col_next + cars[i]->getLength() - 1;

            }

            // Shows that any gampiece trying to be moved off the board will result in an error
            if (col_next < 1 || col_next > 6 || row_next < 1 || row_next > 6)
            {

                cout << "*** Attempt is made to move a piece off the edge of the board.  Please retry. ***" << endl;
                break;
            }

            char checkCollideFlag = ' ';
            checkCollideFlag = checkCollide(cars[i],howfar,direction, cars, carCount);

            // Shows that if gampiece is attempted to move on top of a piece it will result in an error
            if (checkCollideFlag == 'y')
            {
                cout << "*** Attempt is made to move a piece on top of another piece. Please retry ***" << endl;
                break;
            }
//Move the car
            cars[i]->move(direction, howfar);

// Shows if red gampiece reaches to position 18 then the user wins the game
            if(color == 'R' && cars[i]->getColumn() == (7 - cars[i]->getLength()) && (cars[i]->getRow() == 3))
            {
                cout << "*** Congratulations, you did it! ***" << endl;
                gameover = 'y';

            }

            }
        }

            // Shows if user tries to move a car in the wrong direction it will result in an error
            if(error == 'y')
             {
                cout << "***Attempt was made to move a piece in the wrong direction.  Please retry.***" << endl;
             }

            drawBoard(cars, carCount, graphicsWindow);
        }
}
        cout << "Thank you for playing.  Exiting..." << endl;
        drawBoard(cars, carCount, graphicsWindow);
        pause(5000);   // time in milliseconds
        graphicsWindow.close();
        exitGraphics();
//------------------------------------------------------------------------------------//


    displayIDInfo();        // Display ID info
    displayInstructions();  // Display game instructions
    int num_times = 0; // this displays how much times you are giving an input



//------------------------------------------------------------------------------------//
    return 0;
}
