#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <mutex>
#include <unordered_map>
#include "TrieNode.hpp"

class Trie {
public:
    Trie();
    ~Trie();

    TrieNode* getRoot() const { return root; }

    void insert(const std::string& word);
    bool search(const std::string& word);
    void remove(const std::string& word);
    std::vector<std::string> startsWith(const std::string& prefix);

private:
    TrieNode* root;

    void insertRecursive(TrieNode* node, const std::string& word, int index);
    bool searchRecursive(TrieNode* node, const std::string& word, int index);
    void removeRecursive(TrieNode* node, const std::string& word, int index);
    void dfs(TrieNode* node, std::string currentWord, std::vector<std::string>& words);
    std::vector<std::string> startsWithRecursive(TrieNode* node, const std::string& prefix);
};

#endif // TRIE_H
