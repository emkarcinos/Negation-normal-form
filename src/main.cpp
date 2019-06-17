#include "NegationNormalForm.h"
#include "Finders.h"
#include "Tools.h"
#include <iostream>

int main(){
	// You have to explicitly write parenthesis specifying the power of the operator
    std::string line="!E((PvQ)>P)";
    std::cout << "Formula to bring: " << line << std::endl;
	line = bringToNNF(line);
    std::cout << "Formula after: " << line;
    std::cin.get();
    return 0;
}