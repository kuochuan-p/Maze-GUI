//
// Created by kuoch on 11/14/2022.
//

#include "PathGraphic.h"
#include "graphics.h"
#include <iostream>


void PathGraphic::draw() const {
    //draw corners
    glColor3f(.5, .5, .5);
    //top left
    glBegin(GL_QUADS);
    glVertex2i(xCenter-sideLength/2, yCenter-sideLength/2);
    glVertex2i(xCenter-sideLength/2, yCenter-sideLength/4);
    glVertex2i(xCenter-sideLength/4, yCenter-sideLength/4);
    glVertex2i(xCenter-sideLength/4, yCenter-sideLength/2);
    glEnd();
    //top right
    glBegin(GL_QUADS);
    glVertex2i(xCenter+sideLength/2, yCenter-sideLength/2);
    glVertex2i(xCenter+sideLength/4, yCenter-sideLength/2);
    glVertex2i(xCenter+sideLength/4, yCenter-sideLength/4);
    glVertex2i(xCenter+sideLength/2, yCenter-sideLength/4);
    glEnd();
    //bottom right
    glBegin(GL_QUADS);
    glVertex2i(xCenter+sideLength/2, yCenter+sideLength/2);
    glVertex2i(xCenter+sideLength/4, yCenter+sideLength/2);
    glVertex2i(xCenter+sideLength/4, yCenter+sideLength/4);
    glVertex2i(xCenter+sideLength/2, yCenter+sideLength/4);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(xCenter-sideLength/2, yCenter+sideLength/2);
    glVertex2i(xCenter-sideLength/4, yCenter+sideLength/2);
    glVertex2i(xCenter-sideLength/4, yCenter+sideLength/4);
    glVertex2i(xCenter-sideLength/2, yCenter+sideLength/4);
    glEnd();

    //draw walls
    //north
    if(!(data[0]=='1')){
        glBegin(GL_QUADS);
        glVertex2i(xCenter-sideLength/4, yCenter-sideLength/2);
        glVertex2i(xCenter-sideLength/4, yCenter-sideLength/4);
        glVertex2i(xCenter+sideLength/4, yCenter-sideLength/4);
        glVertex2i(xCenter+sideLength/4, yCenter-sideLength/2);
        glEnd();
    }
    //east
    if(!(data[1]=='1')){
        glBegin(GL_QUADS);
        glVertex2i(xCenter+sideLength/4, yCenter-sideLength/4);
        glVertex2i(xCenter+sideLength/2, yCenter-sideLength/4);
        glVertex2i(xCenter+sideLength/2, yCenter+sideLength/4);
        glVertex2i(xCenter+sideLength/4, yCenter+sideLength/4);
        glEnd();
    }
    //WRITTEN BY ELIJAH COOLIDGE-begin
    //South
    if(!(data[2]=='1')){
        glBegin(GL_QUADS);
        glVertex2i(xCenter-sideLength/4, yCenter+sideLength/4);
        glVertex2i(xCenter-sideLength/4, yCenter+sideLength/2);
        glVertex2i(xCenter+sideLength/4, yCenter+sideLength/2);
        glVertex2i(xCenter+sideLength/4, yCenter+sideLength/4);
        glEnd();
    }
    //west
    if(!(data[3]=='1')){
        glBegin(GL_QUADS);
        glVertex2i(xCenter-sideLength/2, yCenter-sideLength/4);
        glVertex2i(xCenter-sideLength/4, yCenter-sideLength/4);
        glVertex2i(xCenter-sideLength/4, yCenter+sideLength/4);
        glVertex2i(xCenter-sideLength/2, yCenter+sideLength/4);
        glEnd();
    }
    //Draw start
    glBegin(GL_TRIANGLES);
    glColor3f(0, 1, 0);
    glVertex2i(16, 16);
    glVertex2i(44, 16);
    glVertex2i(30, 30);
    glEnd();


    //Draw end
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2i(600 - 16, 600 -16);
    glVertex2i(600 - 16, 600 - 44);
    glVertex2i(600 - 30, 600 - 30);
    glColor3f(1, 0, 0);
    glEnd();

    //WRITTEN BY ELIJAH COOLIDGE-end



}

PathGraphic::PathGraphic(string data, int x, int y, int SL) {
    xCenter = x;
    yCenter = y;
    this->data = data;
    sideLength = SL;
}
