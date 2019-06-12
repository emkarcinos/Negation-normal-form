#include "NegationNormalForm.h"
#include "Finders.h"
#include "Tools.h"
#include <iostream>

int main(){
    std::string line="((pvq)=(r^d))>r";
    std::cout << replaceRedundantOperators(line) << std::endl;
    std::cin.get();
    return 0;
}