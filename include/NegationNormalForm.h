/* Logical operators */
#define NOT     '!'
#define AND     '^'
#define OR      'v'
#define EQUAL   '='
#define IMPLIC  '>'
#define Q_EXIST 'E'
#define Q_UNI   'V'
/* Parenthesis */
#define P_OPEN  '('
#define P_CLOSE ')'

#include <string>

/* Returns an index of the first negation occurrence from a formula, with a given start position. Returns -1 if it wasn't found.*/
int findNearestNegation(const std::string& formula, const unsigned int& startPos);

/* Cheks whether the next character in a formula is a bracket */
bool isBeforeBracket(const std::string& formula, const unsigned int& pos);

/* Checks if there's a double negation */
bool isDoubleNegation(const std::string& formaula, const unsigned int& pos);

