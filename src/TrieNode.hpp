#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#include <unordered_map>
#include <mutex>
#include <string>

class TrieNode {
public:
    TrieNode();
    ~TrieNode();

    std::mutex nodeMutex;

    bool getIsEndOfWord() const { return isEndOfWord; }

    void setIsEndOfWord(bool isEndOfWord) { this->isEndOfWord = isEndOfWord; }

    TrieNode* getChild(const std::string& letter);

    TrieNode** getChildren();

    void addChild(const std::string& letter, TrieNode* child);

    void removeChild(const std::string& letter);

private:
    bool isEndOfWord;
    TrieNode* children[26];
};   



#endif // TRIE_NODE_H