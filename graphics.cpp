#include "graphics.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include "PathGraphic.h"
#include "Blind.h"
#include "Rect.h"

using namespace std;

//Initialize a bunch of variables that will be used in the program

//window height and width
GLdouble width, height;
//window variable
int wd;
//side length of path
const int SIDE_LENGTH = 60;
//blind that will affect the user's field of view
Blind b;
//user object
Rect user;
//user score (will always be < 10000
int score = 10000;
//variable to hold completion status
bool complete = false;
//2D vector that will hold the different path objects
vector<vector<PathGraphic>> paths;


//init function will run at the start of runtime
void init() {
    //set width and height
    width = 600;
    height = 600;

    //get data from file to make maze paths
    ifstream inFile("../mazeData.txt");
    inFile >> noskipws;
    string line;

    //this nested for loop will make 10 vectors filled with 10 path objects that are constructed using data from the file
    //and then push each vector to the 2D paths vector
    for(int i = 0; i < 10; i++){
        vector<PathGraphic> row;
        for(int j = 0; j < 10; j++){
            getline(inFile, line);
            PathGraphic pg(line, j*SIDE_LENGTH + SIDE_LENGTH/2, i*SIDE_LENGTH + SIDE_LENGTH/2, SIDE_LENGTH);
            row.push_back(pg);
        }
        paths.push_back(row);
    }
    inFile.close();

    //set user dimensions and location
    user.setX(30);
    user.setY(30);
    user.width = 10;
    user.height = 10;

    //set blind dimensions and location
    b.setX(300);
    b.setY(300);
    b.sidelength = 600;

}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 153/255.0, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {

    //WRITTEN BY LISA DION-begin

    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);
    
    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

    //WRITTEN BY LISA DION-end

    // if the user is at the bottom-rightmost index, they have completed the maze
    if (user.x == 570 && user.y == 570){
        complete = true;
    }

    //if the user has completed the maze display a message with their score
    if (complete){
        string message = "You completed the maze. Your score is: " + to_string(score);
        glColor3f(0, 0, 0);
        glRasterPos2i(60, height/2);
        for (char letter : message) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
        }
    }
    //otherwise, display the maze the blind and the user
    else{
        //draw each path in the 2D vector
        for(int i = 0; i<10; i++){
            for(int j = 0; j<10; j++)
                paths[i][j].draw();
        }

        //draw the blind
        b.draw();
        //draw the user
        user.draw();
    }
    glFlush();  // Render now
}

//WRITTEN BY LISA DION-begin

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    switch(key) {
        case 27: {
            // escape
            glutDestroyWindow(wd);
            exit(0);
        }
    }
    glutPostRedisplay();
}
//WRITTEN BY LISA DION-end

void kbdUp(unsigned char key, int x, int y) {

    glutPostRedisplay();
}

//this keyboard listener function listens for the pressing of the arrow keys
//The user uses the arrow keys to move their avatar around the maze
void kbdS(int key, int x, int y) {
    switch(key) {
        //each key does a very similar thing. After subtracting points from the score,
        //the program checks the path data to ensure that the direction is valid (there's no wall)
        //then the user is moved in that direction and the blind is set to be centered on their location.
        case GLUT_KEY_DOWN:
            score -= 50;
            if(paths[(user.y-30)/60][(user.x-30)/60].data[2] == '1') {
                user.setY(user.y + SIDE_LENGTH);
                b.setY(user.y);
                b.setX(user.x);
            }
            break;
        case GLUT_KEY_LEFT:
            score -= 50;
            if(paths[(user.y-30)/60][(user.x-30)/60].data[3] == '1') {
                user.setX(user.x - SIDE_LENGTH);
                b.setY(user.y);
                b.setX(user.x);
            }
            break;
        case GLUT_KEY_RIGHT:
            score -= 50;
            if(paths[(user.y-30)/60][(user.x-30)/60].data[1] == '1') {
                user.setX(user.x + SIDE_LENGTH);
                b.setY(user.y);
                b.setX(user.x);
            }
            break;
        case GLUT_KEY_UP:
            score -= 50;
            if(paths[(user.y-30)/60][(user.x-30)/60].data[0] == '1') {
                user.setY(user.y - SIDE_LENGTH);
                b.setY(user.y);
                b.setX(user.x);
            }
            break;

    }
    glutPostRedisplay();
}

//the cursor function listens to the location of the cursor and sets the blind to be centered on it after it is moved
void cursor(int x, int y) {

    if(x >= 0 && x <= width && y >= 0 && y <= height){
        b.setX(x);
        b.setY(y);
    }

    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    // if the user clicks, expand the blind to the size of the window and center it and subtract 500 from the score
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        score -= 500;
        b.setX(300);
        b.setY(300);
        b.sidelength = 600;
    }
    glutPostRedisplay();
}


void timer(int dummy) {
    //subtract 2 from score
    if(!complete){
        score -=2;
    }

    //shrink the field of view
    b.sidelength -= 2;
    
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  WRITTEN BY LISA DION*/
int main(int argc, char** argv) {


    init();
    
    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Maze" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    glutKeyboardUpFunc(kbdUp);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, timer, 0);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
