#include <iostream>
#include "myLine.h"
using namespace std;
Line::Line(int x1, int y1, int x2, int y2) {
    A = y2 - y1;
    B = x1 - x2;
    C = x2 * y1 - x1 * y2;
}

Dot Line::intersect(Line l) {
    float a1 = float(Line::A);
    float b1 = float(Line::B);
    float c1 = float(Line::C);
    float a2 = float(l.A);
    float b2 = float(l.B);
    float c2 = float(l.C);
    if ((a1 * b2 - a2 * b1)==0)
    {
        throw exception();
    }
    float x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
    float y = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1);
    return Dot(x,y);
}
bool Line::parallel(Line l) {
    if ((Line::A * l.B - l.A * Line::B) == 0)
    {
        return true;
    }
    return false;
}