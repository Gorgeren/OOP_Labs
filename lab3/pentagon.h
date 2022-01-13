#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"

class Pentagon : public Figure {
public:
    Pentagon();
    virtual ~Pentagon();
    Pentagon(std::istream &in);
    Pentagon(const Pentagon&);
    Pentagon(Point& x1_, Point& x2_, Point& x3_, Point& x4_, Point &x5_);
    double Area();
    size_t VertexesNumber();
    bool operator==(const Pentagon& p);
    
    Pentagon& operator=(const Pentagon& p);
    void Print(std::ostream& os);
    friend std::ostream& operator<<(std::ostream &out, const Pentagon& r);
    friend std::istream& operator>> (std::istream &in, Pentagon&r);

protected:
    Point x1, x2, x3, x4, x5;
};

#endif
