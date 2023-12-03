#include "common/test_helpers.hpp"
#include "../src/Trie.hpp"
#include "../src/TrieNode.hpp"
#include <string>
#include <mutex>
#include <vector>
#include <unordered_map>
#include <gtest/gtest.h>

class TrieTest : public testing::Test {
protected:
    Trie* trie;
    TrieNode* root;
    std::vector<std::string> words;

    TrieTest() {
        trie = new Trie();
    }

    void SetUp() override {
        ssw = TestHelpers::parseFile("test-words-short-similar.txt");
        slw = TestHelpers::parseFile("test-words-long-similar.txt");
        dlw = TestHelpers::parseFile("test-words-long-different.txt");
        dsw = TestHelpers::parseFile("test-words-short-different.txt");
        root = trie->getRoot();
    }

    void TearDown() override {
        delete trie;
    }

    std::vector<std::string> ssw;
    std::vector<std::string> slw;
    std::vector<std::string> dlw;
    std::vector<std::string> dsw;
};

TEST_F(TrieTest, Insert) {
    for (std::string word : ssw) {
        trie->insert(word);
    }

    for (std::string word : slw) {
        trie->insert(word);
    }

    for (std::string word : dlw) {
        trie->insert(word);
    }

    for (std::string word : dsw) {
        trie->insert(word);
    }
}

TEST_F(TrieTest, Search) {
    for (std::string word : ssw) {
        trie->insert(word);
    }

    for (std::string word : slw) {
        trie->insert(word);
    }

    for (std::string word : dlw) {
        trie->insert(word);
    }

    for (std::string word : dsw) {
        trie->insert(word);
    }

    for (std::string word : ssw) {
        ASSERT_TRUE(trie->search(word));
    }

    for (std::string word : slw) {
        ASSERT_TRUE(trie->search(word));
    }

    for (std::string word : dlw) {
        ASSERT_TRUE(trie->search(word));
    }

    for (std::string word : dsw) {
        ASSERT_TRUE(trie->search(word));
    }
}

TEST_F(TrieTest, StartsWith) {
    for (std::string word : ssw) {
        trie->insert(word);
    }

    std::vector<std::string> sswPrefixes = trie->startsWith("appli");
    ASSERT_EQ(sswPrefixes.size(), 6);

    sswPrefixes = trie->startsWith("app");
    ASSERT_EQ(sswPrefixes.size(), 33);

    sswPrefixes = trie->startsWith("apple");
    ASSERT_EQ(sswPrefixes.size(), 5);

    sswPrefixes = trie->startsWith("appro");
    ASSERT_EQ(sswPrefixes.size(), 4);

    sswPrefixes = trie->startsWith("x");
    ASSERT_EQ(sswPrefixes.size(), 0);

}

TEST_F(TrieTest, Remove) {
    for (std::string word : ssw) {
        trie->insert(word);
    }

    for (std::string word : slw) {
        trie->insert(word);
    }

    for (std::string word : dlw) {
        trie->insert(word);
    }

    for (std::string word : dsw) {
        trie->insert(word);
    }

    for (std::string word : ssw) {
        trie->remove(word);
    }

    for (std::string word : slw) {
        trie->remove(word);
    }

    for (std::string word : dlw) {
        trie->remove(word);
    }

    for (std::string word : dsw) {
        trie->remove(word);
    }
}

int main(int argc, char** argv) {
    // Your code here

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
