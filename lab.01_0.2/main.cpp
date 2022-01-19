#include "long.h"
#include <iostream>
int main() {
    std::cout << "Введите выражения в формате: <число1> <оператор> <число2> " << std::endl;
    std::cout << "Поддерживаемые операторы: +, -, *, /, %, >, <, ==, != " << std::endl;
    while (true)
    {
        std::string operate;
        Long number1, number2;
        std::cout << "> ";
        std::cin >> number1 >> operate >> number2;
        if (operate == "+") {
            std::cout << "Результат: " << number1 + number2 << std::endl;
        }
        else if (operate == "-") {
            std::cout << "Результат: " << number1 - number2 << std::endl;
        }
        else if (operate == "*") {
            std::cout << "Результат: " << number1 * number2 << std::endl;
        }
        else if (operate == "/") {
            std::cout << "Результат: " << number1 / number2 << std::endl;
        }
        else if (operate == "%") {
            std::cout << "Результат: " << number1 % number2 << std::endl;
        }
        else if (operate == ">") {
            std::cout << "Результат: " << (number1 > number2? "Истина" : "Ложь") << std::endl;
        }
        else if (operate == "<") {
            std::cout << "Результат: " << (number1 < number2? "Истина" : "Ложь") << std::endl;
        }
        else if (operate == "==") {
            std::cout << "Результат: " << (number1 == number2? "Истина" : "Ложь") << std::endl;
        }
        else if (operate == "!=") {
            std::cout << "Результат: " << (number1 != number2? "Истина" : "Ложь") << std::endl;
        }
        else {
            std::cout << "Ошибка! Неправильный ввод!" << std::endl;
        }
    }
}
