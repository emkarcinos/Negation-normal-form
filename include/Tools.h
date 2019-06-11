#pragma once

/* This file contains tools to manipulate strings, etc */

#include <string>

/* Replaces a substring of a string with another string and returns it. Replacement string can be any length. */
std::string replaceSlice(const std::string& rawStr, const unsigned int& begin, const unsigned int& end, const std::string& replacement);