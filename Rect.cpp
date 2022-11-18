//
// Created by kuoch on 11/15/2022.
//
#include "graphics.h"
#include "Rect.h"

void Rect::setX(int x) {
    this->x = x;
}

void Rect::setY(int y) {
    this->y = y;
}

void Rect::draw() {
    //draw a GL_QUAD with vertices half a side length away from the center in all directions
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex2i(x-width/2,y-height/2);
    glVertex2i(x-width/2,y+height/2);
    glVertex2i(x+width/2, y+height/2);
    glVertex2i(x+width/2, y-height/2);
    glEnd();
}
