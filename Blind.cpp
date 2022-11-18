//
// Created by kuoch on 11/15/2022.
//

#include "graphics.h"
#include "Blind.h"

//This function draws 4 rectangles that can form a whole in the middle that acts as the user's viewport
void Blind::draw() {
    //the color of the rectangles is black
    glColor3f(0, 0, 0);

    //TOP
    // the top should have vertices is the top right and top left and should go down to half a sidelength above the center (x,y)
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(0,y-sidelength/2);
    glVertex2i(600, y-sidelength/2);
    glVertex2i(600, 0);
    glEnd();

    //right
    // the right should have vertices is the top right and bottom right and should go over to half a sidelength to the right
    // of the center (x,y)
    glBegin(GL_QUADS);
    glVertex2i(x+sidelength/2,0);
    glVertex2i(x+sidelength/2,600);
    glVertex2i(600, 600);
    glVertex2i(600, 0);
    glEnd();

    //Bottom
    // the bottom should have vertices is the bottom right and bottom left and should go up to half a sidelength below
    // the center (x,y)
    glBegin(GL_QUADS);
    glVertex2i(0,y+sidelength/2);
    glVertex2i(0,600);
    glVertex2i(600, 600);
    glVertex2i(600, y+sidelength/2);
    glEnd();

    //left
    // the left should have vertices is the top left and bottom left and should go over to half a sidelength to the left
    // of the center (x,y)
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(0,600);
    glVertex2i(x-sidelength/2, 600);
    glVertex2i(x-sidelength/2, 0);
    glEnd();
}

void Blind::setX(int x) {
    this->x = x;
}

void Blind::setY(int y) {
    this->y = y;
}
