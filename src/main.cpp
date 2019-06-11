#include "NegationNormalForm.h"
#include "Finders.h"
#include "Tools.h"
#include <iostream>

int main(){
    std::string line="!E((pv(q^p))>!r)";
    std::cout << findNearestNegation(line) << std::endl;
    std::cin.get();
    return 0;
}