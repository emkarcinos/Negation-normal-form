#include "Finders.h"
#include "operators.h"

int findNearestNegation(const std::string& formula, const unsigned int& startPos){
    for(unsigned int pos=startPos; pos<formula.length(); pos++){
        if(formula[pos]==NOT)
            return pos;
    }
    return -1; //If nothing has been found
}

int findBracketCompletion(const std::string& formula, const unsigned int& pos){
    unsigned int count=1; // Counts of the 
    char bracket=formula[pos];
    if(bracket==P_CLOSE){ // If parenthesis on a given pos is a closed parenthesis, look for matching open parenthesis.
        for(unsigned int ptr=pos-1; ptr>=0; ptr--){
            if(formula[ptr]==P_OPEN && count==1) 
                return ptr;
            else if(formula[ptr]==P_CLOSE)
                count++;
            else if(formula[ptr]==P_OPEN)
                count--;
        }
    } else { // If parenthesis on a given pos is an open parenthesis, look for matching closed parenthesis.
        for(unsigned int ptr=pos+1; ptr!=0; ptr++){
            if(formula[ptr]==P_CLOSE && count==1) 
                return ptr;
            else if(formula[ptr]==P_OPEN)
                count++;
            else if(formula[ptr]==P_CLOSE)
                count--;
        }
    }
    return -1; //If nothing has been found
}

bool isBeforeBracketOrQuantifier(const std::string& formula, const unsigned int& pos){
    if(formula[pos+1]==Q_EXIST || formula[pos+1]==Q_UNI || formula[pos+1]==P_OPEN)
        return true;
    return false;
}

bool isalpha_quantifiers(const char& ch){
    if(ch==Q_EXIST || ch==Q_UNI || ch==OR)
        return false;
    else
        return isalpha(ch);
}

bool isPredicate(const std::string& formula, const unsigned int& pos){
    return isalpha_quantifiers(formula[pos+1]);
}

unsigned int findPredecessor(const std::string& formula, const unsigned int& pos){
    unsigned int result=-1;
    if(isalpha_quantifiers(formula[pos-1]))
        return pos-1;
    if(formula[pos-1]==P_CLOSE) {
        result = findBracketCompletion(formula, pos-1);
        if(result>0 && isalpha_quantifiers(formula[result-1]))
            return result-1;
    }
    return result;
}

unsigned int findSuccessor(const std::string& formula, const unsigned int& pos){
    return pos+1;
}

int findReduntantOperator(const std::string& formula, const unsigned int& pos){
    for(unsigned int i=pos+1; i<formula.length(); i++){
        if(formula[i]==IMPLIC || formula[i]==EQUAL)
            return i;
    }
    return -1;
}