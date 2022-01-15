#include <iostream>
#include "rhombus.h"
#include "tbinarytree.h"
#include <queue>
int main()
{
    char c;
    TBinaryTree tree;
    std::queue <Rhombus> rhomb;

    std::cout << "Press '?' for help:\n";
    while ((c = getchar()) != EOF) {
        if (c == '?') {
            std::cout << "U can:\n";
            std::cout << "press r -- Play with Rhombus\n";
            std::cout << "press p -- Print tree\n";
            std::cout << "press c -- Clear tree\n";
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
            tree.Push(make_shared<Rhombus>(a));
        }
        else if (c == 'p') {
            std::cout << tree << std::endl;
        }
        else if (c == 'c') {
            tree.Clear();
            std::cout << "tree was cleared" << std::endl;
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
            if (!tree.Empty()) {
                std::cout << tree << std::endl;
            }
            std::cout << "_______________________________________________________\n";
            std::cout << "End session..." << std::endl;
            return 0;
        } else if (c != ' ' && c != '\n' && c != '\t') {
            std::cout << "Unexpectable simbol\n";
        }
    }
    tree.Clear();
    return 0;
}