#include "code.hpp"
#include <algorithm>



// since we are implementing functions
// i assume we do not need to write anything in main

// task 1 
// given a URL string, remove leading and trailing whitespaces
// Convert it to lowercase
// then URL-encode it
std::string canonicalizeURL(std::string& str)
{
	// for the first condition we can call on trim
	// it removes leading and trailing whitespaces from a string
	trim(str);

	// converts all values to lower case
	str = toLowerCase(str);

	// urlEncode... returns nothing
	urlEncode(str);

	// returning the string after it has been altered
	return str;
}


// task 2
// Given a string, return a summary containing the strings length
//		whether it starts with "http", and its Levenshtein distance to the string "example".
// Return a struct with length
// a boolean variable, and the distance.
// Struct Summary is given in the header file
Summary summarizeString(const std::string& str)
{
	Summary summary; // called on Summary struct

	summary.length = str.length(); // this function is not int StringManipulationLibrary API
	// i hope it counts/ works since it is a common one we do use

	summary.startsWithHttp = startsWith(str, "http");
	// simple checks function

	summary.levenshteinDist = levenshteinDistance(str, "example");

	return summary; // this is the struct it wishes for me to return
}

// task 3
// given a sentence, reverse each word in the sentence and remove any duplicate characters within each word
// split the sentence into words
// for each word, remove duplicate characters
// reverse each word
// join the words back into a sentence
std::string reverseAndUniqueEachWord(const std::string& sentence)
{
	std::vector<std::string> token;
	tokenize(const_cast<std::string&>(sentence), token, " ");

	// now token holds all the words
	// now we should loop
	for (int i{ 0 }; i < token.size(); i++)
	{
		removeDuplicates(&token[i]);

		reverse(&token[i]);
	}

	// now we join the words back into a sentence
	return join(token, " ");
}


// task 4
// given a URL, extract all query parameters and concatenate their values
// split the URL by '?' and take the second part
// tokenize this part by & to get individual queries
// for each query, split by = and take the value part
// concatenate all the values
std::string extractAndConcatQueryParams(const std::string& url)
{

	size_t position = url.find('?');

	if (position != std::string::npos)
	{
		std::string valuePart = url.substr(position + 1);


		std::vector<std::string> queries; // this is where we will put the token values
		tokenize(const_cast<std::string&>(valuePart), queries, "&"); // token

		std::string result;

		for (const std::string& query : queries)
		{
			std::vector<std::string> values;
			tokenize(const_cast<std::string&>(query), values, "="); // token

			if (values.size() == 2)
			{
				if (!result.empty())
				{
					result += values[1]; // Concatenate the value
				}
				else
				{
					result = values[1];
				}
			}
		}

		return result;
	}

	return "";
}


// task 5
// given a paragraph, find and redact any occurrences of a list of sensitive words
// also, return the total number or redacted words.
// toeknize the paragraph into words
// for each word, check if its a sensitive word and replace it with "REDACTED".
// count the total number of redacted words
int redactSensitiveInfo(std::string& paragraph, const std::vector<std::string>& sensitiveWords)
{
	int count = 0; // this is a counter

	for (const std::string& word : sensitiveWords) 
	{
		size_t pos = 0;

		while ((pos = paragraph.find(word, pos)) != std::string::npos) 
		{
			// Replace the sensitive word with the redacted word
			replaceFirst(paragraph, word, "REDACTED");
			count++; // increment
			// Move the position past the redacted word to avoid infinite loops
		}
	}

	return count;
}

// task 6
// given a paragraph, find the most repeated word.
// a nested loop can be helpful here.
// you can loop through each word in the paragraph.
// for each iteration, compare the word with every other word in the paragraph
std::string findMostRepeatedWord(std::string& paragraph)
{
	std::vector<std::string> token;
	tokenize(paragraph, token, " ");

	std::string repeatedWord;
	int maxCount = 0; 

	// for each loop
	for (const std::string& word : token) 
	{

		int count = std::count(token.begin(), token.end(), word);
		if (count > maxCount) 
		{
			maxCount = count;
			repeatedWord = word;
		}
	}

	return repeatedWord;
}


// task 7
// given a long paragraph, generate a summary by picking the first sentence.
// the sentence with the most vowels and the last sentence
// split the text into sentences. Assume sentences end with '.'
// find the sentence with the most vowels
// concatenate the first, most-vowel-rich, and last sentences to form a summary
std::string summarizeText(const std::string& paragraph)
{
	// token gives me the values between .
	std::vector<std::string> token;
	tokenize(const_cast<std::string&>(paragraph), token, ".");

	// instantiate string of vowels, and counter
	std::string vowelPhrase;
	int maxVowels = 0;

	// for each loop
	for (const std::string& sentence : token) 
	{

		int vowels = countVowels(sentence);
		if (vowels > maxVowels) 
		{
			maxVowels = vowels;
			vowelPhrase = sentence;
		}
	}

	// we will concatenate the values together
	// why reinvent the wheel?
	std::string summary;
	if (!token.empty()) {
		summary += token.front() + ".";
	}
	if (!vowelPhrase.empty()) {
		summary += vowelPhrase + ".";
	}
	if (!token.empty()) {
		summary += token.back() + ".";
	}

	return summary;
}