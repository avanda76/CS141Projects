
/* steiner.cpp
 *  Graphics demo program for getting started with QtCreator for program 6, Steiner Trees.
 *
 * Author: Aditya Vandanapu
 * Date: 11/24/17
 * Class: CS 141, Fall 2017
 * System: QtCreator with Stanford graphics library, on iMac, OS Sierra
 *
 */

#include <iostream>
#include "gobjects.h"  // for all graphics objects
#include "gevents.h"   // for mouse events
#include <fstream>        // For file input
#include <cmath>
#include <ctime>
using namespace std;

// Global constants
const int PointRadius = 7;

// Create a graphics window, which will be used to draw graphical shapes.
// This can be a global variable, but you may not have any other global variables.
GWindow graphicsWindow;

//create a class for the point
class MyPoint
{
public:
    MyPoint(){}
    MyPoint(int theX, int theY, string theColor)
    {
        
        x= theX;
        y = theY;
        color  = theColor;
    }
    
    int getX(){return x;}
    int getY(){return y;}
    string getColor(){return color;}
    int getRadius(){return radius;}
    bool getVisibility(){return visibility;}
    
    void createPoints()
    {
        GOval *pPoint = new GOval(x, y, PointRadius*2, PointRadius*2);
        pPoint->setFilled(true);
        pPoint->setColor(color);
        graphicsWindow.add(pPoint);
        
    }
    
    
private:
    int x;
    int width;
    int height;
    int y;
    string color;
    int radius;
    bool visibility;
    GOval *theCircle;
    
    
    
};


//create a class for the buttons
class MyButton
{
public:
    MyButton();
    MyButton(int theX,int theY,int theWidth, int theHeight, string theColor, GRect *Rectangle, GLabel *Label, string theText)
    {
        
        theRectangle = new GRect( x,y, width, height);
        theLabel = new GLabel(text);
        
        x = theX;
        y = theY;
        width = theWidth;
        height = theHeight;
        color = theColor;
        *theRectangle = *Rectangle;
        *theLabel = *Label;
        text  = theText;
    }
    
    
private:
    int x;
    int y;
    int width;
    int height;
    string color;
    GRect * theRectangle;
    GLabel * theLabel;
    string text;
};

//find the line distance
int lineDistance(int startingX, int startingY, int endingX, int endingY)
{
    int distance;
    distance = sqrt(((endingY-startingY)*(endingY-startingY)) - ((endingX-startingX)*(endingX-startingX)));
    return distance;
}

//------------------------------------------------------------------------------------------
// Read in the sets of points information from the data file
// You muse make the pointsArray Vector a reference parameter so that read-in values are
// reflected back to the caller.
void readInputFile( Vector<MyPoint> &pointsArray, int &idealScore)
{
    ifstream inputFileStream;  // declare the input file stream
    
    // Open input file and verify.
    // You must first:
    //    1. Outside of QtCreator go into your project's resources folder, copy readme.txt into data.txt
    //    2. Edit data.txt to have the datafile information as shown on the assignment page
    //    3. Now WITHIN QtCreator right-click on the "res" folder (under "Other files") and
    //       choose "add new" and add the new data.txt file so it shows up in your environment.
    inputFileStream.open("data.txt");
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file data.txt.  Exiting..." << endl;
        exit( -1);
    }
    
    // Read sets of data from input file.  Each read operation reads the next set of data.
    // The first line in the input file indicates which set to use.
    int whichSetToUse;
    inputFileStream >> whichSetToUse;
    
    int howManyPoints;    // How many points are in the set of points
    int x, y;             // Store individual point x,y values from input file
    // Reserve some reasonable number of total points for the vector, so that
    pointsArray.ensureCapacity( 10);
    
    // Read in and discard some number of sets of points before we get the real set we will be using
    for( int i = 0; i < whichSetToUse-1; i++) {
        inputFileStream >> howManyPoints >> idealScore;
        for( int j = 0; j < howManyPoints; j++) {
            inputFileStream >> x >> y;    // Read in the points
        }
    }
    
    inputFileStream >> howManyPoints >> idealScore;
    
    // Read in and store the points information
    for( int i = 0; i < howManyPoints; i++) {
        inputFileStream >> x >> y;    // Read in the points
        // This is where you should take the points information and create points on the screen.
        // For now we will just print out the points information.
        MyPoint *pThePoint = new MyPoint( x, y, "black");
        pointsArray.push_back(*pThePoint);
        pThePoint->createPoints();
        cout << "Point " << i << " is at " << x << "," << y << endl;
    }
}//end readInputFile()


//------------------------------------------------------------------------------------------
int main()
{
    graphicsWindow.setCanvasSize( 400, 400);   // Set the size
    graphicsWindow.setWindowTitle(" AVANDA7  QtCreator Program 6");
    
    Vector<MyPoint> pointsArray;    // Store all points that are created.
    // ... Create something similar to store all GLine * lines
    int idealScore = 0;             // Precomputed ideal score for each puzzle
    
    // Get the set of data to use from the input file
    readInputFile( pointsArray, idealScore);
    
    // Create the Control and message components.
    // First create the messages label at the top of the window
    GLabel *messagesLabel = new GLabel();
    messagesLabel->setText("Find the minimal spanning tree, using additional points.");
    messagesLabel->setLocation( 30,20);
    graphicsWindow.add( messagesLabel);  // As with all components, after creating them you must also
    // add them to the graphics window, otherwise they will
    // exist but won't show up.
    
    // Create the Exit button enclosing red rectangle
    int exitButtonX = 250;
    int exitButtonY = 350;
    int exitButtonWidth = 50;
    int exitButtonHeight = 30;
    GRect *exitButton = new GRect(exitButtonX, exitButtonY, exitButtonWidth, exitButtonHeight);
    exitButton->setColor( "red");
    exitButton->setFilled( true);
    graphicsWindow.add( exitButton);
    
    // Create the Exit button text that appears on top of the rectangle
    GLabel *exitButtonLabel = new GLabel();
    exitButtonLabel->setText("Exit");
    // Find size of text, to determine placement relative to enclosing rectangle
    int xOffset = (exitButtonWidth  - exitButtonLabel->getBounds().getWidth()) / 2;
    int yOffset = (exitButtonHeight - exitButtonLabel->getBounds().getHeight()) + 5;
    exitButtonLabel->setLocation( exitButtonX + xOffset, exitButtonY + yOffset);
    graphicsWindow.add( exitButtonLabel);
    
    //add a addpoint button
    int addPointButtonX = 10;
    int addPointButtonY = 350;
    int addPointButtonWidth = 70;
    int addPointButtonHeight = 30;
    GRect *addPointButton = new GRect(addPointButtonX, addPointButtonY, addPointButtonWidth, addPointButtonHeight);
    addPointButton->setColor( "green");
    addPointButton->setFilled( true);
    graphicsWindow.add(addPointButton);
    
    //create an add point button
    GLabel *addPointButtonLabel = new GLabel();
    addPointButtonLabel->setText("Add Points");
    
    int xOffset1 = (addPointButtonWidth  - addPointButtonLabel->getBounds().getWidth()) / 2;
    int yOffset1 = (addPointButtonHeight - addPointButtonLabel->getBounds().getHeight()) + 5;
    addPointButtonLabel->setLocation( addPointButtonX + xOffset1, addPointButtonY + yOffset1);
    graphicsWindow.add(addPointButtonLabel);
    
    //create a draw lines button
    int drawLinesButtonX = 90;
    int drawLinesButtonY = 350;
    int drawLinesButtonWidth = 70;
    int drawLinesButtonHeight = 30;
    GRect *drawLinesButton = new GRect(drawLinesButtonX, drawLinesButtonY, drawLinesButtonWidth, drawLinesButtonHeight);
    drawLinesButton->setColor( "lightgray");
    drawLinesButton->setFilled( true);
    graphicsWindow.add(drawLinesButton);
    
    //add a draw lines label
    GLabel *drawLinesButtonLabel = new GLabel();
    drawLinesButtonLabel->setText("Draw Lines");
    
    int xOffset2 = (drawLinesButtonWidth  - drawLinesButtonLabel->getBounds().getWidth()) / 2;
    int yOffset2 = (drawLinesButtonHeight - drawLinesButtonLabel->getBounds().getHeight()) + 5;
    drawLinesButtonLabel->setLocation( drawLinesButtonX + xOffset2, drawLinesButtonY + yOffset2);
    graphicsWindow.add(drawLinesButtonLabel);
    
    //add a show length label
    GLabel *showLengthLabel = new GLabel();
    int showLengthX = 325;
    int showLengthY = 360;
    showLengthLabel->setText("Length: ");
    showLengthLabel->setLocation( showLengthX, showLengthY);
    graphicsWindow.add(showLengthLabel);
    
    //add a show length distance label.
    int showLengthX1 = 325;
    int showLengthY1 = 375;
    GLabel *showLengthDistance = new GLabel();
    showLengthDistance->setText("0");
    showLengthDistance->setLocation( showLengthX1, showLengthY1);
    graphicsWindow.add(showLengthDistance);
    
    
    // Make the graphics window have focus, since all interaction will be through the window
    graphicsWindow.requestFocus();
    
    // Set values to use for keeping track of program modes
    const int Default = 0;
    const int DrawPoints = 1;
    const int DrawLines = 2;
    int programMode = Default;  // Modes are Default, DrawPoints, DrawLines. Start in Default mode
    // Change to the other modes when those buttons are pressed.
    bool buttonWasPressed = false;    // Set to false when a button is pressed.  Used to avoid drawing on buttons
    
    int startingX;  // immediately when they are pressed.
    int startingY;
    int endingX = 0;
    int endingY = 0;
    char distance[1000];
    int mouseX = -1;                    // Will store mouse position
    int mouseY = -1;
    int score = 0;
    
    char message[ 81];                  // Used to construct message to be displayed at top of window
    GLine *pLine = new GLine(0,0,0,0);  // Line to be drawn on the screen.  It starts out as a single unseen point.
    pLine->setLineWidth(2);
    graphicsWindow.add(pLine);
    
    GMouseEvent e;      // Stores the mouse event each time through the event loop
    int counter = 0;    // Used to display debugging information, to help understand how the event loop works.
    
    
    
    // Main event loop.  Most of your code will go in here, to handle the different mouse events.
    while (true)
    {
        // Wait for a mouse event, then get the x,y coordinates
        e = waitForEvent(MOUSE_EVENT);
        // Get the current mouse x,y location
        mouseX = e.getX();
        mouseY = e.getY();
        
        counter++;    // Iterations counter
        // Use the sprintf string function to print into a string, which in turn will be displayed in the messages label
        sprintf( message,"%d. Mouse at %d,%d", counter, mouseX, mouseY);  // print into a string
        messagesLabel->setLabel(message);
        
        //  -------- Perform actions for different kinds of mouse events --------
        //if mouse got pressed.
        if (e.getEventType() == MOUSE_PRESSED) {
            sprintf( message,"Mouse pressed at %d,%d", mouseX, mouseY);  // print into a string
            messagesLabel->setLabel(message);
            
            // See if Exit button was clicked by seeing if mouse press location is inside the rectangle
            if( exitButton->contains( mouseX, mouseY) )
            {
                messagesLabel->setLabel("Exiting...");
                break;
            }
            if( addPointButton->contains(mouseX, mouseY) )
            {
                programMode = DrawPoints;
                buttonWasPressed = false;
            }
            if( programMode == DrawPoints && !addPointButton->contains(mouseX, mouseY) )
            {
                MyPoint *point = new MyPoint(mouseX, mouseY, "blue");
                point->createPoints();
                pointsArray.push_back(*point);
            }
            
            if( drawLinesButton->contains(mouseX, mouseY) )
            {
                programMode = DrawLines;
                buttonWasPressed = true;
            }
            if(buttonWasPressed == true)
            {
                if( programMode == DrawLines && ! drawLinesButton->contains(mouseX, mouseY) )
                {
                    buttonWasPressed = true;
                    startingX = mouseX;
                    startingY = mouseY;
                    pLine->setStartPoint(mouseX, mouseY);
                    pLine->setEndPoint(mouseX, mouseY);
                }
            }
            else
            {
                cout << "Setting line start and end points to " << mouseX << "," << mouseY << endl;
                messagesLabel->setLabel(message);
                // Set the start point of the already existing line
                pLine->setStartPoint( mouseX, mouseY);
                pLine->setEndPoint( mouseX, mouseY);
            }
        }
        
        //if mouse event is released.
        else if( e.getEventType() == MOUSE_RELEASED) {
            
            score = score + lineDistance(startingX, startingY, mouseX, mouseY);
            
            sprintf(distance,"%d", lineDistance(startingX, startingY, mouseX, mouseY));  // print into a string
            messagesLabel->setLabel(message);
            cout << "Mouse was released at : " << mouseX << "," << mouseY << endl;
            // Depending on your program mode (DrawPoints or DrawLines), draw points or create a new line and store it somewhere,";
            
            // Set the end point of the previously created line that currently has the same begin & end points
            pLine->setEndPoint(mouseX, mouseY);
            GLine *pLine = new GLine(startingX, startingY, mouseX, mouseY);
            pLine->setLineWidth(2);
            graphicsWindow.add(pLine);
        }
        
        //if mouse got dragged
        else if(e.getEventType() == MOUSE_DRAGGED)
        {
            sprintf( distance, " %d", lineDistance(startingX, startingY, mouseX, mouseY) );
            showLengthDistance->setLabel(distance);
            cout << "Mouse dragged to " << mouseX << "," << mouseY << endl;
            // The previous MOUSE_PRESSED event created the line, though with beginning and ending points being the same.
            // Now set the end point to be at the new mouse destination.  Don't create the new line here, since we don't
            // want to do that until the MOUSE_RELEASED event.
            pLine->setEndPoint(mouseX, mouseY);
        }//else if( e.getEventType()...
        
    }
    //end while( true)
    
    // Close the windows, first the graphics window
    graphicsWindow.requestFocus();
    graphicsWindow.close();
    exitGraphics();
    return 0;
}

