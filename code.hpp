#ifndef CODE_HPP
#define CODE_HPP

#include "StringManipulationLibrary.hpp"
#include <string>
#include <vector>


// Define the Summary struct
struct Summary {
    int length;
    bool startsWithHttp;
    int levenshteinDist;
};



// TO DO

// task 1
std::string canonicalizeURL(std::string& str);

// task 2
Summary summarizeString(const std::string& str);

// task 3
std::string reverseAndUniqueEachWord(const std::string& sentence);

// task 4
std::string extractAndConcatQueryParams(const std::string& url);

// task 5
int redactSensitiveInfo(std::string& paragraph, const std::vector<std::string>& sensitiveWords);

// task 6
std::string findMostRepeatedWord(std::string& paragraph);

// task 7
std::string summarizeText(const std::string& paragraph);



#endif // CODE_HPP
