#include <string>
#include <mutex>
#include <vector>
#include <unordered_map>
#include "Trie.hpp"


Trie::Trie(){
    root = new TrieNode();
}

Trie::~Trie() {
    delete root;
}

void Trie::insert(const std::string& word){
    insertRecursive(root, word, 0);
}

bool Trie::search(const std::string& word){
    return searchRecursive(root, word, 0);
}

void Trie::remove(const std::string& word){
    removeRecursive(root, word, 0);
}

std::vector<std::string> Trie::startsWith(const std::string& prefix){
    return startsWithRecursive(root, prefix);
}

void Trie::insertRecursive(TrieNode* node, const std::string& word, int index){
    node->nodeMutex.lock();
    if(index == word.length()){
        node->setIsEndOfWord(true);
        node->nodeMutex.unlock();
        return;
    }

    std::string letter = word.substr(index, 1);
    TrieNode* child = node->getChild(letter);
    if (child == nullptr) {
        child = new TrieNode();
        node->addChild(letter, child);
    }
    node->nodeMutex.unlock();
    insertRecursive(child, word, index + 1);
}

 bool Trie::searchRecursive(TrieNode* node, const std::string& word, int index){
    node->nodeMutex.lock();
    if(index == word.length()){
        bool isEndOfWord = node->getIsEndOfWord();
        node->nodeMutex.unlock();
        return isEndOfWord;
    }

    std::string letter = word.substr(index, 1);
    TrieNode* child = node->getChild(letter);
    node->nodeMutex.unlock();
    if (child == nullptr) {
        return false;
    }
    return searchRecursive(child, word, index + 1);
}

void Trie::removeRecursive(TrieNode* node, const std::string& word, int index){
    node->nodeMutex.lock();
    if(index == word.length()){
        node->setIsEndOfWord(false);
        node->nodeMutex.unlock();
        return;
    }

    std::string letter = word.substr(index, 1);
    TrieNode* child = node->getChild(letter);
    if (child == nullptr) {
        node->nodeMutex.unlock();
        return;
    }
    node->nodeMutex.unlock();
    removeRecursive(child, word, index + 1);
}

void Trie::dfs(TrieNode* node, std::string currentWord, std::vector<std::string>& words) {
    if (node == nullptr) {
        return;
    }

    // If the current node marks the end of a word, add it to the list
    node->nodeMutex.lock();
    if (node->getIsEndOfWord()) {
        words.push_back(currentWord);
    }
    node->nodeMutex.unlock();

    // Recursively visit all children
    for (char c = 'a'; c <= 'z'; ++c) {
        node->nodeMutex.lock();
        TrieNode* child = node->getChild(std::string(1, c));
        node->nodeMutex.unlock();
        if (child != nullptr) {
            dfs(child, currentWord + c, words);
        }
    }
}

std::vector<std::string> Trie::startsWithRecursive(TrieNode* root, const std::string& prefix) {
    std::vector<std::string> words;
    TrieNode* current = root;

    // Traverse the Trie up to the end of the prefix
    for (char c : prefix) {
        current->nodeMutex.lock();
        TrieNode* child = current->getChild(std::string(1, c));
        current->nodeMutex.unlock();
        current = child;
        if (current == nullptr) {
            // Prefix not found, return empty vector
            return words;
        }
    }

    // Start DFS from the node that matches the last character of the prefix
    dfs(current, prefix, words);

    return words;
}




