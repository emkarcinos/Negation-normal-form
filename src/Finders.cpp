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

bool isPredicate(const std::string& formula, const unsigned int& pos){

}

unsigned int findPredecessor(const std::string& formula, const unsigned int& pos){

}

unsigned int findSuccessor(const std::string& formula, const unsigned int& pos){

}