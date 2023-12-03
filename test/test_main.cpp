#include "common/test_helpers.hpp"
#include <gtest/gtest.h>

namespace testing{
class TrieTest : public testing::Test {
protected:
    Trie* trie;
    TrieNode* root;
    std::vector<std::string> words;

    TrieTest() {
        trie = new Trie();
    }

    ~TrieTest() override {
        delete trie;
    }

    void SetUp() override {
        ssw = TestHelpers::parseFile("test/test_files/test-words-short-similar.txt");
        slw = TestHelpers::parseFile("test/test_files/test-words-long-similar.txt");
        dlw = TestHelpers::parseFile("test/test_files/test-words-long-different.txt");
        dsw = TestHelpers::parseFile("test/test_files/test-words-short-differet.txt");
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


}
}
int main(int argc, char** argv) {
    // Your code here

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
