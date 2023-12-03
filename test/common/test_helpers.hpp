#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include <string>
#include <vector>
#include <iostream>
#include "../src/Trie.hpp"
#include "../src/TrieNode.hpp"

class TestHelpers {
public:
    std::vector<std::string> words;
    static std::vector<std::string> parseFile(std::string filename);
    static void printTrie(TrieNode* node, std::string currentWord);
    static void printTrie(Trie* trie);
    static void printWords(std::vector<std::string> words);
    static bool compareWords(std::vector<std::string> v1, std::vector<std::string> v2);
};

#endif // TEST_HELPERS_H