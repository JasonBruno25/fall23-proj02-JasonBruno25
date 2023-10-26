#include "StringManipulationLibrary.hpp"
#include <vector>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>

// Converts all characters in a string to uppercase.
std::string toUpperCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Converts all characters in a string to lowercase.
std::string toLowerCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Removes leading and trailing whitespaces from a string.
void trim(std::string& str) {
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
}

// Counts the number of vowels in a string.
int countVowels(const std::string& str) {
    int count = 0;
    std::string vowels = "AEIOUaeiou";
    for (char c : str) {
        if (vowels.find(c) != std::string::npos) {
            count++;
        }
    }
    return count;
}

// Reverses a string.
void reverse(std::string* str) {
    std::reverse(str->begin(), str->end());
}

// Checks if a string is a palindrome.
bool isPalindrome(std::string str) {
    std::string original = str;
    std::reverse(str.begin(), str.end());
    return original == str;
}

// Concatenates two strings.
std::string concatenate(const std::string& str1, const std::string& str2) {
    return str1 + str2;
}

// Finds a substring within a string.
bool findSubstring(std::string str, const std::string& subStr) {
    return str.find(subStr) != std::string::npos;
}

// Splits a string into a vector of strings based on a delimiter.
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string temp;
    while (std::getline(iss, temp, delimiter)) {
        tokens.push_back(temp);
    }
    return tokens;
}

// Replaces the first occurrence of a substring with another substring.
void replaceFirst(std::string& str, const std::string& oldSubStr, const std::string& newSubStr) {
    size_t pos = str.find(oldSubStr);
    if (pos != std::string::npos) {
        str.replace(pos, oldSubStr.length(), newSubStr);
    }
}

// Replaces all occurrences of a substring with another substring.
void replaceAll(std::string* str, const std::string& oldSubStr, const std::string& newSubStr) {
    size_t pos = 0;
    while ((pos = str->find(oldSubStr, pos)) != std::string::npos) {
        str->replace(pos, oldSubStr.length(), newSubStr);
        pos += newSubStr.length();
    }
}

// Converts the first letter of each word in a string to uppercase.
std::string toTitleCase(const std::string& str) {
    std::string result = str;
    bool newWord = true;
    for (char &c : result) {
        if (newWord && std::isalpha(c)) {
            c = std::toupper(c);
            newWord = false;
        } else if (std::isspace(c)) {
            newWord = true;
        }
    }
    return result;
}

// Splits the string into tokens based on multiple delimiters.
void tokenize(std::string& str, std::vector<std::string>& tokens, const std::string& delimiters) {
    size_t start = str.find_first_not_of(delimiters), end = 0;
    while ((end = str.find_first_of(delimiters, start)) != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = str.find_first_not_of(delimiters, end);
    }
    if (start != std::string::npos) {
        tokens.push_back(str.substr(start));
    }
}

// Finds all occurrences of a substring and returns their positions.
std::vector<int> findAll(std::string str, const std::string& subStr) {
    std::vector<int> positions;
    size_t pos = 0;
    while ((pos = str.find(subStr, pos)) != std::string::npos) {
        positions.push_back(pos);
        pos += subStr.length();
    }
    return positions;
}

// Repeats a string n times.
std::string repeat(const std::string& str, int times) {
    std::string result;
    for (int i = 0; i < times; ++i) {
        result += str;
    }
    return result;
}

// Checks if a string starts with a given prefix.
bool startsWith(const std::string& str, const std::string& prefix) {
    return str.rfind(prefix, 0) == 0;
}

// Checks if a string ends with a given suffix.
bool endsWith(const std::string* str, const std::string& suffix) {
    return str->rfind(suffix) == (str->size() - suffix.size());
}

// Joins a list of strings using a delimiter.
std::string join(const std::vector<std::string>& list, const std::string& delimiter) {
    std::string result;
    for (const auto &item : list) {
        if (&item != &list[0]) {
            result += delimiter;
        }
        result += item;
    }
    return result;
}

// Removes duplicate characters from a string.
void removeDuplicates(std::string* str) {
    std::string result;
    for (size_t i = 0; i < str->length(); ++i) {
        bool isDuplicate = false;
        for (size_t j = 0; j < result.length(); ++j) {
            if ((*str)[i] == result[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            result += (*str)[i];
        }
    }
    *str = result;
}

// Calculates the Levenshtein distance between two strings.
int levenshteinDistance(const std::string& str1, const std::string& str2) {
    int m = str1.size();
    int n = str2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            dp[i][j] = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost});
        }
    }
    return dp[m][n];
}

// Finds the longest common substring between two strings.
std::string longestCommonSubstring(const std::string& str1, const std::string& str2) {
    int m = str1.size();
    int n = str2.size();
    int maxLength = 0, end = 0;
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    end = i - 1;
                }
            }
        }
    }
    return str1.substr(end - maxLength + 1, maxLength);
}

// URL-encodes a string.
void urlEncode(std::string& str) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (char c : str) {
        if (std::isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
        } else {
            escaped << std::uppercase;
            escaped << '%' << std::setw(2) << int((unsigned char) c);
            escaped << std::nouppercase;
        }
    }

    str = escaped.str();
}

// URL-decodes a string.
void urlDecode(std::string* str) {
    std::string out;
    for (int i = 0; i < str->size(); ++i) {
        if ((*str)[i] == '%') {
            int value;
            std::istringstream is(str->substr(i + 1, 2));
            if (is >> std::hex >> value) {
                out += static_cast<char>(value);
                i += 2;
            }
        } else if ((*str)[i] == '+') {
            out += ' ';
        } else {
            out += (*str)[i];
        }
    }
    *str = out;
}

// Applies the ROT13 algorithm to a string.
std::string ROT13(std::string str) {
    for (char &c : str) {
        if ('a' <= c && c <= 'z') {
            c = 'a' + (c - 'a' + 13) % 26;
        } else if ('A' <= c && c <= 'Z') {
            c = 'A' + (c - 'A' + 13) % 26;
        }
    }
    return str;
}
