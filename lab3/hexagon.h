#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"


class Hexagon : public Figure {
public:
    Hexagon();
    virtual ~Hexagon();
    Hexagon(std::istream &in);
    Hexagon(const Hexagon& r);
    Hexagon(Point& x1_, Point& x2_, Point& x3_, Point& x4_, Point &x5_, Point &x6_);
    double Area();
    size_t VertexesNumber();
    bool operator==(const Hexagon& h);
    
    Hexagon& operator=(const Hexagon& h);
    void Print(std::ostream& os);
    friend std::ostream& operator<<(std::ostream &out, const Hexagon& r);
    friend std::istream& operator>> (std::istream &in, Hexagon& r);

protected:
    Point x1, x2, x3, x4, x5, x6;
};

#endif
