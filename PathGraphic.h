//
// Created by kuoch on 11/14/2022.
//

#ifndef M4OEP_KPONZIO_EPCOOLID_PATHGRAPHIC_H
#define M4OEP_KPONZIO_EPCOOLID_PATHGRAPHIC_H

#include <string>
using namespace std;

class PathGraphic {
public:
    //constructor that takes in wall data, x and y location, and sidelength
    PathGraphic(string data, int x, int y, int SL);

    int xCenter;
    int yCenter;
    //data represents the directions in which travel from and to this path are valid
    string data;
    int sideLength;

    void draw() const;
};


#endif //M4OEP_KPONZIO_EPCOOLID_PATHGRAPHIC_H
