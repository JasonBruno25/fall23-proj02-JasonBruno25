# fall23-proj02-JasonBruno25

# String Processing Library – ECE 2514 Computational Engineering

**Project 2** – Advanced string manipulation and analysis

This project implements a collection of string processing functions that perform URL canonicalization, text summarization, word transformations, query parameter extraction, sensitive information redaction, and statistical text analysis. All functions rely on a provided `StringManipulationLibrary` (header and implementation given).

---

## Table of Contents

- [Overview](#overview)
- [File Structure](#file-structure)
- [Compilation](#compilation)
- [Testing](#testing)
- [Function Descriptions](#function-descriptions)
  - [1. canonicalizeURL](#1-canonicalizeurl)
  - [2. summarizeString](#2-summarizestring)
  - [3. reverseAndUniqueEachWord](#3-reverseanduniqueeachword)
  - [4. extractAndConcatQueryParams](#4-extractandconcatqueryparams)
  - [5. redactSensitiveInfo](#5-redactsensitiveinfo)
  - [6. findMostRepeatedWord](#6-findmostrepeatedword)
  - [7. summarizeText](#7-summarizetext)
- [Dependencies](#dependencies)
- [Example Usage](#example-usage)
- [Acknowledgments](#acknowledgments)

---

## Overview

This project provides a set of reusable string utilities that perform common text transformation and analysis tasks. The functions are implemented in `code.cpp` using helper functions from the `StringManipulationLibrary` (e.g., `trim`, `toLowerCase`, `urlEncode`, `tokenize`, `removeDuplicates`, `levenshteinDistance`, etc.). The toolkit can be integrated into larger applications or used as a standalone library.

---

## File Structure

  ```text
  ├── code.hpp # Function declarations and Summary struct
  ├── code.cpp # Implementation of the 7 required tasks
  ├── StringManipulationLibrary.hpp # Provided helper functions API
  ├── StringManipulationLibrary.cpp # Implementations of helpers
  ├── tests.cpp # Catch2 test cases (7 test sections)
  ├── README.md # This file
  └── (optional) CMakeLists.txt or Makefile
  ```

---

## Compilation

You can compile using `g++` with C++17 or C++11 (the code uses only standard features).

```bash
g++ -std=c++17 -o string_toolkit code.cpp StringManipulationLibrary.cpp
```

To run the tests (requires Catch2), compile with tests.cpp instead:
  ```bash
  g++ -std=c++17 -o tests tests.cpp code.cpp StringManipulationLibrary.cpp
  ./tests
  ```
> Note: The provided `StringManipulationLibrary` implements all helper functions; no external libraries besides the standard library and Catch2 are required

---

## Testing
The test suite ( `tests.cpp` ) uses Catch2 and covers every function with example test cases:

| Test | Section | Points | Description |
|------|---------|--------|-------------|
| `canonicalizeURL` | 3 | URL trimming, lowercasing, URL‑encoding |
| `summarizeString` | 3 | Returns struct with length, startsWithHttp flag, Levenshtein distance to "example" |
| `reverseAndUniqueEachWord` | 3 | Reverses each word, removes duplicate characters per word |
| `extractAndConcatQueryParams` | 4 | Extracts query parameter values from URL and concatenates them |
| `redactSensitiveInfo` | 4 | Replaces sensitive words with "REDACTED", returns count |
| `findMostRepeatedWord` | 4 | Finds the word that appears most often in a paragraph |
| `summarizeText` | 4 | Picks first, most‑vowel‑rich, and last sentence to form a summary |

Run `./tests` to see all test results. Expected output: all tests pass.

---

## Function Descriptions

### 1. `canonicalizeURL`
  ```cpp
  std::string canonicalizeURL(std::string& str);
  ```
- What it does:
  - Removes leading/trailing whitespace (`trim`)
  - Converts the entire string to lowercase (`toLowerCase`)
  - URL‑encodes the result (`urlEncode`)
- Example:
  - `" HTTP://www.Example.com "` → `"http%3A%2F%2Fwww.example.com"`
- **Note:** The URL encoding converts special characters like `:` and `/` into `%3A`, `%2F`, etc

### 2. `summarizeString`
  ```cpp
  Summary summarizeString(const std::string& str);
  ```
- Returns a `Summary` struct containing:
  - `int length` – length of the string
  - `bool startsWithHttp` – true if string starts with `"http"` (case‑sensitive)
  - `int levenshteinDist` – Levenshtein edit distance to the string `"example"`
- Example:
  - `summarizeString("httpExample")` → length=11, startsWithHttp=true, distance=5

### 3. `reverseAndUniqueEachWord`
  ```cpp
  std::string reverseAndUniqueEachWord(const std::string& sentence);
  ```
- Process:
  1. Tokenize the sentence into words (delimited by spaces)
  2. For each word, remove duplicate characters (keeping the first occurrence of each character)
  3. Reverse the filtered word
  4. Join the words back with spaces
- Example:
  - `"hello world"` → `"oleh dlrow"`
  - `"apple juice"` → `"elpa eciuj"`

### 4. `extractAndConcatQueryParams`
  ```cpp
  std::string extractAndConcatQueryParams(const std::string& url);
  ```
- What it does:
  - Finds the `?` in the URL, takes the substring after it (the query string)
  - Splits the query string by `&` to get individual parameters
  - For each parameter of the form `key=value`, extracts the `value` part
  - Concatenates all values in the order they appear
- Example:
  - `"http://example.com?name=John&age=30"` → `"John30"`
  - `"http://test.com?id=5&code=A123"` → `"5A123"`
- If no `?` exists or no valid parameters, returns an empty string.

### 5. `redactSensitiveInfo`
  ```cpp
  int redactSensitiveInfo(std::string& paragraph, const std::vector<std::string>& sensitiveWords);
  ```

- Process:
  - For each sensitive word, find all occurrences in the paragraph (case‑sensitive)
  - Replace each occurrence with the string `"REDACTED"`
  - Count the total number of replacements made
- Returns: The total number of redacted words
- Example:
  - Paragraph: `"Sensitive information about John and password."`
  - Sensitive words: `{"John", "password"}`
  - Result: `"Sensitive information about REDACTED and REDACTED."` (returns 2)

### 6. `findMostRepeatedWord`
  ```cpp
  std::string findMostRepeatedWord(std::string& paragraph);
  ```
- What it does:
  - Tokenizes the paragraph by spaces
  - Counts frequency of each word (case‑sensitive)
  - Returns the word with the highest frequency (if tie, the first one encountered)
- Example:
  - `"apple orange apple banana apple"` → `"apple"`

### 7. `summarizeText`
  ```cpp
  std::string summarizeText(const std::string& paragraph);
  ```
- Process:
  - Split the paragraph into sentences using `'.'` as the delimiter
  - Identify the sentence with the most vowels (using `countVowels`)
  - Create a summary by concatenating:
    1. The first sentence
    2. The sentence with the most vowels
    3. The last sentence
    4. Each sentence is followed by a period (`.`)
- Example:
  - Input: `"This is the first sentence. Here is one with lots of vowels. Another one. One more. And this is the last."`
  - Output: `"This is the first sentence. Here is one with lots of vowels. And this is the last."`

---

## Dependencies
- **C++ Standard Library** (iostream, string, vector, algorithm, sstream, etc.)
- **StringManipulationLibrary** (provided header and implementation)
- **Catch2** (only for running tests; not required for the library itself)

---

## Example Usage
Here is a small example of using the functions in a custom `main.cpp`:
  ```cpp
  #include "code.hpp"
  #include <iostream>
  
  int main() {
      std::string url = "  HTTP://www.Example.com ";
      std::cout << "Canonical: " << canonicalizeURL(url) << std::endl;
  
      Summary s = summarizeString("httpExample");
      std::cout << "Length: " << s.length << ", starts with http? " << s.startsWithHttp << std::endl;
  
      std::string sentence = "hello world";
      std::cout << "Reverse & unique: " << reverseAndUniqueEachWord(sentence) << std::endl;
  
      std::string queryURL = "http://test.com?id=5&code=A123";
      std::cout << "Concat values: " << extractAndConcatQueryParams(queryURL) << std::endl;
  
      std::string para = "apple orange apple banana apple";
      std::cout << "Most repeated: " << findMostRepeatedWord(para) << std::endl;
  
      return 0;
  }
  ```
Compile and run:
```bash
g++ -std=c++17 main.cpp code.cpp StringManipulationLibrary.cpp -o demo
./demo
```

---

## Acknowledgments
- **StringManipulationLibrary** provided by the course instructors
- The seven tasks reflect real‑world text processing needs: URL cleaning, redaction, summarization, and statistical word analysis
- Implemented as part of **ECE 2514 – Computational Engineering** at Virginia Tech.

Author: Jason Bruno Terceros  
Course: ECE 2514 (Fall 2023)
