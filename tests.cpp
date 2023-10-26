#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "code.hpp"

TEST_CASE("canonicalizeURL Test", "[3 points]") {
    std::string url1 = "  HTTP://www.Example.com ";
    REQUIRE(canonicalizeURL(url1) == "http%3A%2F%2Fwww.example.com");

    std::string url2 = "https://GoOgle.com";
    REQUIRE(canonicalizeURL(url2) == "https%3A%2F%2Fgoogle.com");
}

TEST_CASE("summarizeString Test", "[3 points]") {
    Summary summary1 = summarizeString("httpExample");
    REQUIRE(summary1.length == 11);
    REQUIRE(summary1.startsWithHttp == true);
    REQUIRE(summary1.levenshteinDist == 5);
}

TEST_CASE("reverseAndUniqueEachWord Test", "[3 points]") {
    REQUIRE(reverseAndUniqueEachWord("hello world") == "oleh dlrow");
    REQUIRE(reverseAndUniqueEachWord("apple juice") == "elpa eciuj");
}

TEST_CASE("extractAndConcatQueryParams Test", "[4 points]") {
    REQUIRE(extractAndConcatQueryParams("http://example.com?name=John&age=30") == "John30");
    REQUIRE(extractAndConcatQueryParams("http://test.com?id=5&code=A123") == "5A123");
}

TEST_CASE("redactSensitiveInfo Test", "[4 points]") {
    std::string paragraph = "Sensitive information about John and password.";
    std::vector<std::string> words = { "John", "password" };
    REQUIRE(redactSensitiveInfo(paragraph, words) == 2);
    REQUIRE(paragraph == "Sensitive information about REDACTED and REDACTED.");
}

TEST_CASE("findMostRepeatedWord Test", "[4 points]") {
    std::string paragraph = "apple orange apple banana apple";
    REQUIRE(findMostRepeatedWord(paragraph) == "apple");
}

TEST_CASE("summarizeText Test", "[4 points]") {
    std::string paragraph = "This is the first sentence. Here is one with lots of vowels. Another one. One more. And this is the last.";
    REQUIRE(summarizeText(paragraph) == "This is the first sentence. Here is one with lots of vowels. And this is the last.");
}
