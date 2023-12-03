#include <unordered_map>
#include <mutex>
#include <string>
#include "TrieNode.hpp"

TrieNode::TrieNode(){
    isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
        children[i] = nullptr;
    }
}

TrieNode::~TrieNode() {
    for (int i = 0; i < 26; i++) {
        if (children[i] != nullptr) {
            delete children[i];
        }
    }
}

TrieNode* TrieNode::getChild(const std::string& letter) {
    return children[letter[0] - 'a'];
}

TrieNode** TrieNode::getChildren(){
    return children;
}

void TrieNode::addChild(const std::string& letter, TrieNode* child){
    children[letter[0] - 'a'] = child;
}

void TrieNode::removeChild(const std::string& letter){
    children[letter[0] - 'a'] = nullptr;
}
