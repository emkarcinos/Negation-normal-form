#include "NegationNormalForm.h"
#include "Finders.h"
#include "Tools.h"
#include <iostream>

int main(){
    std::string line="beginREend";
    std::cout << replaceSlice(line,5,6,"ASDASDASDA") << std::endl;
    std::cin.get();
    return 0;
}