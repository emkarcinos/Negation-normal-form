#include "NegationNormalForm.h"
#include "Finders.h"
#include <iostream>

int main(){
    std::string line="(a(q,e)va)va";
    unsigned int i = 0;
    i = findPredecessor(line, 10);
    std::cout << i << std::endl;
    std::cin.get();
    return 0;
}