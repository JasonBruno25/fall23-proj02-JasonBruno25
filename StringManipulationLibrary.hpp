// StringManipulationLibrary.hpp

#ifndef STRINGMANIPULATIONLIBRARY_HPP
#define STRINGMANIPULATIONLIBRARY_HPP

#include <string>
#include <vector>

// Function Declarations

std::string toUpperCase(const std::string& str);
std::string toLowerCase(std::string str);
void trim(std::string& str);
int countVowels(const std::string& str);
void reverse(std::string* str);
bool isPalindrome(std::string str);
std::string concatenate(const std::string& str1, const std::string& str2);
bool findSubstring(std::string str, const std::string& subStr);
std::vector<std::string> split(const std::string& str, char delimiter);
void replaceFirst(std::string& str, const std::string& oldSubStr, const std::string& newSubStr);
void replaceAll(std::string* str, const std::string& oldSubStr, const std::string& newSubStr);
std::string toTitleCase(const std::string& str);
void tokenize(std::string& str, std::vector<std::string>& tokens, const std::string& delimiters);
std::vector<int> findAll(std::string str, const std::string& subStr);
std::string repeat(const std::string& str, int times);
bool startsWith(const std::string& str, const std::string& prefix);
bool endsWith(const std::string* str, const std::string& suffix);
std::string join(const std::vector<std::string>& list, const std::string& delimiter);
void removeDuplicates(std::string* str);
int levenshteinDistance(const std::string& str1, const std::string& str2);
std::string longestCommonSubstring(const std::string& str1, const std::string& str2);
void urlEncode(std::string& str);
void urlDecode(std::string* str);
std::string ROT13(std::string str);

#endif // STRINGMANIPULATIONLIBRARY_HPP
