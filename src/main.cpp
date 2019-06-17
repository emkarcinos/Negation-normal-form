#include "NegationNormalForm.h"
#include "Finders.h"
#include "Tools.h"
#include <iostream>

int main(){
	// You have to explicitly write parenthesis specifying the power of the operator
	std::string line = "";
	std::cout << "Formula to bring: ";
	std::cin >> line;
	line = bringToNNF(line);
    std::cout << "Formula after: " << line;
    std::cin.get();
	std::cout << "Press any key to exit this program... ";
	std::cin.get();
    return 0;
}