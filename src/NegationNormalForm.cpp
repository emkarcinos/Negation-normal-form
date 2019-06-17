#include "NegationNormalForm.h"
#include "Finders.h"
#include "Tools.h"
#include "operators.h"
#include <sstream>

std::string applyDeMorgan(const std::string& formula, const unsigned int& pos){
	std::string result = formula;
	int ptr = pos;
	while (ptr != result.length()) {
		ptr = findNearestNegation(result, ptr);
		if (ptr == -1) return result;
		if (isBeforeBracketOrQuantifier(result, ptr)) {
			// Swaps quantifiers
			if (result[ptr + 1] == Q_EXIST) {
				result[ptr + 1] = Q_UNI;
				result.insert(ptr + 2, "!");
				result.erase(ptr, 1);
			} else if (result[ptr + 1] == Q_UNI) {
				result[ptr + 1] = Q_EXIST;
				result.insert(ptr + 2, "!");
				result.erase(ptr, 1);
			} else if (result[ptr + 1] == P_OPEN) {
				result.insert(ptr + 2, "!");
				int helpPtr = ptr + 3;
				// Looks for an operator
				while (helpPtr != result.length()) {
					if (result[helpPtr] == OR || result[helpPtr] == AND)
						break;
					helpPtr++;
				}
				result.insert(helpPtr + 1, "!");
				if (result[helpPtr] == OR) result[helpPtr] = AND;
				else result[helpPtr] = OR;
				result.erase(ptr, 1);
			}
		}
		result = removeMultipleNegations(result);
		ptr++;
	}
	return result;
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
    std::string result = formula;
    for(unsigned int pos=0; pos<result.length(); pos++){
        pos=findNearestNegation(result, pos);
        if (pos==-1) return result;
        for(unsigned int negationCount=1; pos+1<result.length(); negationCount++){
            pos++;
            if(result[pos]==NOT){
                result.erase(pos-1,2);
                pos--;
				negationCount = 0;
            } else break;
        }
    }
	return result;
}

std::string bringToNNF(const std::string& formula) {
	std::string result = formula;
	result = replaceRedundantOperators(result);
	result = removeMultipleNegations(result);
	result = applyDeMorgan(result);
	return result;
}