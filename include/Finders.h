#pragma once

/* This file contains function declarations for finding elements in a formula */

#include <string>

/* Returns an index of the first negation occurrence from a formula, with a given start position. Returns -1 if it wasn't found.*/
int findNearestNegation(const std::string& formula, const unsigned int& startPos=0);

/* Returns an index of the bracket's completor, i.e where the braket closes/opens. Returns -1 if it wasn't found.*/
int findBracketCompletion(const std::string& formula, const unsigned int& pos);

/* Same as isalpha() but quantifiers are not considered an alphanumerical letter */
bool isalpha_quantifiers(const char& ch);

/* Cheks whether the next character after given position in a formula is a bracket or a quantifier */
bool isBeforeBracketOrQuantifier(const std::string& formula, const unsigned int& pos);

/* Checks if there's a predicate before an index in a string NOTE: Predicate is a letter. */
bool isPredicate(const std::string& formula, const unsigned int& pos);

/* Returns an index of the predecesor of an operator from a given formula */
unsigned int findPredecessor(const std::string& formula, const unsigned int& pos);

/* Returns an index of the successor of an operator from a given formula */
unsigned int findSuccessor(const std::string& formula, const unsigned int& pos);

/* Returns an index of the first encountered reduntant operator (implication or equality). Returns -1 if it wasn't found. */
int findReduntantOperator(const std::string& formula, const unsigned int& pos=0);