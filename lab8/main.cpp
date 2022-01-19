#include "rhombus.h"
#include "tbinarytree.h"

int main()
{
    Rhombus *rhomb[4];
    for (int i = 0; i < 4; ++i) {
        std::cout << "Enter a Rhombus: ";
        Rhombus a;
        std::cin >> a;
        rhomb[i] = new Rhombus(a);
    
    }
    std::cout << "created\n";
    for (int i = 0; i < 4; i++) {
        std::cout << *rhomb[i] << "\n";
    }
    for (int i = 0; i < 4; ++i) {
        delete rhomb[i];
    }
    return 0;
}