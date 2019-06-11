#include "NegationNormalForm.h"
#include "Finders.h"
#include "Tools.h"
#include "operators.h"

std::string applyDeMorgan(const std::string& formula, const unsigned int& pos){

}

std::string replaceImplication(const std::string& formula, const unsigned int& implicationPos){
    std::string result = formula; // used for returning
    unsigned int predecessorPos = findPredecessor(formula, implicationPos);
    result[implicationPos]=OR;
    result = replaceSlice(result, predecessorPos, predecessorPos, "!");
    return result;
}

std::string replaceEquality(const std::string& formula, const unsigned int& equalityPos){

}

std::string replaceRedundantOperators(const std::string formula){
    unsigned int currentPos=0;
    std::string result="";
    for(unsigned int curs=0; curs<formula.length(); curs++){
        curs=findReduntantOperator(formula, curs);

    }
    return result;
}

std::string removeMultipleNegations(const std::string& formula){

}