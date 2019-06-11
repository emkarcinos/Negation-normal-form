#include "NegationNormalForm.h"
#include "Finders.h"
#include "Tools.h"
#include <iostream>

int main(){
    std::string line="(pvq)>(r^d)";
    std::cout << replaceImplication(line, 5) << std::endl;
    std::cin.get();
    return 0;
}