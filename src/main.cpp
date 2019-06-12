#include "NegationNormalForm.h"
#include "Finders.h"
#include "Tools.h"
#include <iostream>

int main(){
    std::string line="E!((pvq)=(r^d))>r";
    std::cout << "Formula to bring: " << line << std::endl;
    line=replaceRedundantOperators(line);
    line=removeMultipleNegations(line);
    std::cout << "Formula after: " << line;
    std::cin.get();
    return 0;
}