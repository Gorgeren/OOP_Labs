#include <iostream>
#include "rhombus.h"
#include "pentagon.h"
#include "hexagon.h"
#include <queue>
int main()
{
    char c;
    std::queue <Rhombus> rhomb;
    std::queue <Pentagon> pent;
    std::queue <Hexagon> hex;
    std::cout << "Press '?' for help:\n";
    while ((c = getchar()) != EOF) {
        if (c == '?') {
            std::cout << "U can:\n";
            std::cout << "press r -- Play with Rhombus\n";
            std::cout << "press p -- Play with Pentagon\n";
            std::cout << "press h -- Play with Hexagon\n";
            std::cout << "press e -- Exit\n";
        }
        else if (c == 'r') {
            std::cout << "Rhombus Mode...\nUse coodinates. Type of points - double\n";
            Rhombus a(std::cin);
            std::cout << "Area = " << a.Area() << std::endl;
            std::cout << "Vertex Number = " << a.VertexesNumber() << std::endl;
            a.Print(std::cout);
            std::cout << "Complete, press next button...\n";
            rhomb.push(a);
        }
        else if (c == 'p') {
            std::cout << "Pentagon Mode...\nUse coodinates. Type of points - double\n";
            Pentagon b(std::cin);
            std::cout << "Area = " << b.Area() << std::endl;
            std::cout << "Vertex Number = " << b.VertexesNumber() << std::endl;
            b.Print(std::cout);
            std::cout << "Complete, press next button...\n";
            pent.push(b);
        }
        else if (c == 'h') {
            std::cout << "Hexagon Mode...\nUse coodinates. Type of points - double\n";
            Hexagon c(std::cin);
            std::cout << "Area = " << c.Area() << std::endl;
            std::cout << "Vertex Number = " << c.VertexesNumber() << std::endl;
            c.Print(std::cout);  
            std::cout << "Complete, press next button...\n";  
            hex.push(c);        
        }
        else if (c == 'e') {
            std:: cout << "\n*******************************************************\n";
            std::cout << "Program LOG\n";
            std::cout << "_______________________________________________________\n";
            Rhombus c;
            std::cout << "Rhombuses:" << std::endl;
            int count = 0;
            while(!rhomb.empty()) {
                ++count;
                std::cout << count << '.';
                c = rhomb.front();
                c.Print(std::cout);
                std::cout <<"Area = " << c.Area() << std::endl;
                rhomb.pop();
            }
            std::cout << "\nPentagons:" << std::endl;
            Pentagon d;
            count = 0;
            while(!pent.empty()) {
                ++count;
                d = pent.front();
                std::cout << count << '.';
                d.Print(std::cout);
                std::cout <<"Area = " << d.Area() << std::endl;
                pent.pop();
            }
            Hexagon e;
            count = 0;
            std::cout << "\nHexagons:" << std::endl;
            while(!hex.empty()) {
                ++count;
                e = hex.front();
                std::cout << count << '.';
                e.Print(std::cout);
                std::cout << "Area = " << e.Area() << std::endl;
                hex.pop();
            }
            std::cout << "_______________________________________________________\n";
            std::cout << "End session..." << std::endl;
            return 0;
        }
        else if (c != ' ' && c != '\n' && c != '\t') {
            std::cout << "Unexpectable simbol\n";
        }
    }
return 0;
}
