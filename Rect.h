//
// Created by kuoch on 11/15/2022.
//

#ifndef M4OEP_KPONZIO_EPCOOLID_RECT_H
#define M4OEP_KPONZIO_EPCOOLID_RECT_H


class Rect {
public:
    // x and y coordinates for the center of the rectangle
    int x;
    int y;
    // sidelengths
    int width;
    int height;

    //setters
    void setX(int x);
    void setY(int y);
    //draw function
    void draw();
};


#endif //M4OEP_KPONZIO_EPCOOLID_RECT_H
