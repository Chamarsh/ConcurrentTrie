#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "../src/Trie.hpp"
#include "../src/TrieNode.hpp"
#include "test_helpers.hpp"

std::vector<std::string> TestHelpers::parseFile(std::string filename){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return;
    }

    std::vector<std::string> words;
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }

}

void TestHelpers::printTrie(TrieNode* node, std::string currentWord) {
    if (node->getIsEndOfWord()) {
        std::cout << currentWord << std::endl;
    }

    TrieNode** children = node->getChildren();
    for (int i = 0; i < 26; i++) {
        if (children[i] != nullptr) {
            printTrie(children[i], currentWord + (char) (i + 'a'));
        }
    }
}

void TestHelpers::printTrie(Trie* trie) {
    printTrie(trie->getRoot(), "");
}

void TestHelpers::printWords(std::vector<std::string> words) {
    for (std::string word : words) {
        std::cout << word << std::endl;
    }
}

bool TestHelpers::compareWords(std::vector<std::string> v1, std::vector<std::string> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }

    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }

    return true;
}
