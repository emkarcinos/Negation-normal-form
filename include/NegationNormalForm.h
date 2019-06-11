#pragma once

#include <string>
/* Returns a formula with all reduntant operators (implication, equality) brought to a normal form */
std::string replaceRedundantOperators(const std::string formula);

/* Return a formula with applied DeMorgan's law on a formula after a given position */
std::string applyDeMorgan(const std::string& formula, const unsigned int& pos);

/* Returns a formula with removed multiplicated negations */
std::string removeMultipleNegations(const std::string& formula);