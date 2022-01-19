#include <iostream>
#include <string>
#include <cassert>
class Long {
    public : 
        Long() : low_digits(0), high_digits(0) {}
        Long(std::string number);
        Long(unsigned int first, unsigned int second) : high_digits(first), 	low_digits(second) {}
        friend Long operator+(const Long& first, const Long& second);
        friend Long operator-(const Long& first, const Long& second);
        friend Long operator*(const Long& first, const Long& second);
        friend Long operator/(const Long& first, const Long& second);
        friend Long operator%(const Long& first, const Long& second);
        friend bool operator<(const Long& first, const Long& second);
        friend bool operator==(const Long& first, const Long& second);
        friend bool operator>(const Long& first, const Long& second);
        friend bool operator!=(const Long& first, const Long& second);
        friend std::istream& operator>> (std::istream &in, Long& number);
        friend std::ostream& operator<< (std::ostream &out, const Long& number);
        Long& operator=(const Long& second) {
            low_digits = second.low_digits;
            high_digits = second.high_digits;
            return *this;
        }
        static const unsigned int MAX_UINT = 0-1;
    private :
        unsigned int low_digits;
        unsigned int high_digits;
};
