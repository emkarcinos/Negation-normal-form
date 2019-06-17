#include "NegationNormalForm.h"
#include "Finders.h"
#include "Tools.h"
#include <iostream>

int main(){
    std::string line="!E(p^q)";
    std::cout << "Formula to bring: " << line << std::endl;
	line = applyDeMorgan(line);
    std::cout << "Formula after: " << line;
    std::cin.get();
    return 0;
}