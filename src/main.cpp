#include "NegationNormalForm.h"
#include "Finders.h"
#include "Tools.h"
#include <iostream>

int main(){
    std::string line="(pvq)>r";
    std::cout << "Formula to bring: " << line << std::endl;
	line = bringToNNF(line);
    std::cout << "Formula after: " << line;
    std::cin.get();
    return 0;
}