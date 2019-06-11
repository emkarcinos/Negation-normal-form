#include "NegationNormalForm.h"
#include "Finders.h"
#include <iostream>

int main(){
    std::string line="(a(q,e))";
    int i = findBracketCompletion(line, 7);
    std::cout << i << std::endl;
    std::cin.get();
    return 0;
}