#include "pentagon.h"

Pentagon::Pentagon() :x1(0, 0),x2(0, 0),x3(0, 0), x4(0, 0), x5(0, 0) {}

size_t Pentagon::VertexesNumber() {
    return 5;
}
Pentagon::Pentagon(const Pentagon& r) : x1(r.x1), x2(r.x2), x3(r.x3), x4(r.x4), x5(r.x5) {}
Pentagon::Pentagon(Point& x1_, Point& x2_, Point& x3_, Point& x4_, Point &x5_): x1(x1_), x2(x2_), x3(x3_), x4(x4_), x5(x5_) {}
double triangleArea(double a, double b, double c) {
    double p = (a + b + c) / 2;
    double s = std::sqrt(p * (p - a) * (p - b) * (p - c));
    return s;
}
double Pentagon::Area() {
    return triangleArea(x1.dist(x2), x2.dist(x3), x1.dist(x3)) +
           triangleArea(x1.dist(x3), x3.dist(x4), x1.dist(x4)) +
           triangleArea(x1.dist(x4), x4.dist(x5), x1.dist(x5));
}

std::ostream &operator<<(std::ostream &os, const Pentagon &r) {
    os << "Pentagon: (" << r.x1.x_ << ", " << r.x1.y_ << ") " 
       << '(' <<r.x2.x_ << ", " << r.x2.y_ << ") " 
       << '(' <<r.x3.x_ << ", " << r.x3.y_ << ") " 
       << '(' <<r.x4.x_ << ", " << r.x4.y_ << ") " 
       << '(' <<r.x5.x_ << ", " << r.x5.y_ << ") " 
       << std::endl;
    return os;
}

std::istream &operator>>(std::istream &in, Pentagon &r) {
    in >> r.x1.x_ >> r.x1.y_>> r.x2.x_ >> r.x2.y_ >> r.x3.x_ >> r.x3.y_ >> r.x4.x_ >> r.x4.y_ >> r.x5.x_ >> r.x5.y_;
    return in;
}

void Pentagon::Print(std::ostream& os) {
    os << "Pentagon: ("<< x1.x_ << ", " << x1.y_ << ") " 
       << '(' <<x2.x_ << ", " << x2.y_ << ") " 
       << '(' <<x3.x_ << ", " << x3.y_ << ") " 
       << '(' <<x4.x_ << ", " << x4.y_ << ") " 
       << '(' <<x5.x_ << ", " << x5.y_ << ") " 
       << std::endl;
}

Pentagon::Pentagon(std::istream &in) {
    in >> x1.x_ >> x1.y_>> x2.x_ >> x2.y_ >> x3.x_ >> x3.y_ >> x4.x_ >> x4.y_ >> x5.x_ >> x5.y_;
}

Pentagon &Pentagon::operator=(const Pentagon &p) {
    if(&p == this)
        return *this;
    x1 = p.x1;
    x2 = p.x2;
    x3 = p.x3;
    x4 = p.x4;
    x5 = p.x5;
    return *this;
}

bool Pentagon::operator==(const Pentagon &p) {
    return x1 == p.x1 && x2 == p.x2 && x3 == p.x3 && x4 == p.x4 && x5 == p.x5;
}

Pentagon::~Pentagon() {

}




