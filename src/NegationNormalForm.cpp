#include "NegationNormalForm.h"
#include "Finders.h"
#include "Tools.h"
#include "operators.h"
#include <sstream>

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
    std::string result = formula;
    unsigned int predecessorPos = findPredecessor(formula, equalityPos);
    unsigned int successorEnd = findSuccessorEnd(formula, equalityPos);
    std::string leftSide=formula.substr(predecessorPos,equalityPos-predecessorPos);
    std::string rightSide=formula.substr(equalityPos+1, successorEnd-equalityPos);
    std::stringstream lhsStream;
    std::stringstream rhsStream;
    lhsStream << "(!" << leftSide << OR << rightSide << ")^";
    rhsStream << "(!" << rightSide << OR << leftSide << ")";
    std::string finalReplacement=lhsStream.str() + rhsStream.str();
    result=replaceSlice(result, predecessorPos, successorEnd+1, finalReplacement);
    return result;
}

std::string replaceRedundantOperators(const std::string formula){
    std::string result=formula;
    int op=findReduntantOperator(result);
    while(op!=-1){
        if(result[op]==IMPLIC)
            result=replaceImplication(result, op);
        else if (result[op]==EQUAL)
            result=replaceEquality(result, op);
        op=findReduntantOperator(result);
    }
    return result;
}

std::string removeMultipleNegations(const std::string& formula){

}