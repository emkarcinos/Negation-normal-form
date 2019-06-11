#include "Tools.h"

#include <string>

std::string replaceSlice(const std::string& rawStr, const unsigned int& begin, const unsigned int& end, const std::string& replacement){
    
    std::string beginStr = rawStr.substr(0, begin);
    std::string endStr = rawStr.substr(end);
    std::string result = "";
    result+=beginStr;
    result+=replacement;
    result+=endStr;
    return result;
}