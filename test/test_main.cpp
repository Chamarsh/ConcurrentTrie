#include "common/test_helpers.hpp"
#include "../src/Trie.hpp"
#include "../src/TrieNode.hpp"
#include <string>
#include <mutex>
#include <thread>
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
public:
    void ConcurrentInsert(int which) {
        switch (which){
            case 1:
                for (std::string word : ssw) {
                    trie->insert(word);
                }
                break;
            case 2:
                for (std::string word : slw) {
                    trie->insert(word);
                }
                break;

            case 3:
                for (std::string word : dlw) {
                    trie->insert(word);
                }
                break;
            case 4:
                for (std::string word : dsw) {
                    trie->insert(word);
                }
                break;
        }
    }

    void ConcurrentSearch(int which) {
        switch (which){
            case 1:
                for (std::string word : ssw) {
                    ASSERT_TRUE(trie->search(word));
                }
                break;
            case 2:
                for (std::string word : slw) {
                    ASSERT_TRUE(trie->search(word));
                }
                break;

            case 3:
                for (std::string word : dlw) {
                    ASSERT_TRUE(trie->search(word));
                }
                break;
            case 4:
                for (std::string word : dsw) {
                    ASSERT_TRUE(trie->search(word));
                }
                break;
        }
    }

    void ConcurrentRemove(int which) {
        switch (which){
            case 1:
                for (std::string word : ssw) {
                    trie->remove(word);
                }
                break;
            case 2:
                for (std::string word : slw) {
                    trie->remove(word);
                }
                break;

            case 3:
                for (std::string word : dlw) {
                    trie->remove(word);
                }
                break;
            case 4:
                for (std::string word : dsw) {
                    trie->remove(word);
                }
                break;
        }
    }

    void ConcurrentStartsWith(int which) {
        switch (which){
            case 1:
                for (std::string word : ssw) {
                    trie->startsWith(word);
                }
                break;
            case 2:
                for (std::string word : slw) {
                    trie->startsWith(word);
                }
                break;

            case 3:
                for (std::string word : dlw) {
                    trie->startsWith(word);
                }
                break;
            case 4:
                for (std::string word : dsw) {
                    trie->startsWith(word);
                }
                break;
        }
    }
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

TEST_F(TrieTest, ConcurrentInsert) {
    std::thread t1(&TrieTest::ConcurrentInsert, this, 1);
    std::thread t2(&TrieTest::ConcurrentInsert, this, 2);
    std::thread t3(&TrieTest::ConcurrentInsert, this, 3);
    std::thread t4(&TrieTest::ConcurrentInsert, this, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

TEST_F(TrieTest, ConcurrentSearch) {
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

    std::thread t1(&TrieTest::ConcurrentSearch, this, 1);
    std::thread t2(&TrieTest::ConcurrentSearch, this, 2);
    std::thread t3(&TrieTest::ConcurrentSearch, this, 3);
    std::thread t4(&TrieTest::ConcurrentSearch, this, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

TEST_F(TrieTest, ConcurrentRemove) {
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

    std::thread t1(&TrieTest::ConcurrentRemove, this, 1);
    std::thread t2(&TrieTest::ConcurrentRemove, this, 2);
    std::thread t3(&TrieTest::ConcurrentRemove, this, 3);
    std::thread t4(&TrieTest::ConcurrentRemove, this, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

TEST_F(TrieTest, ConcurrentStartsWith) {
    for (std::string word : ssw) {
        trie->insert(word);
    }

    std::thread t1(&TrieTest::ConcurrentStartsWith, this, 1);
    std::thread t2(&TrieTest::ConcurrentStartsWith, this, 2);
    std::thread t3(&TrieTest::ConcurrentStartsWith, this, 3);
    std::thread t4(&TrieTest::ConcurrentStartsWith, this, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

TEST_F(TrieTest, ConcurrentInsertAndRemove){
    std::thread t1(&TrieTest::ConcurrentInsert, this, 1);
    std::thread t5(&TrieTest::ConcurrentRemove, this, 1);
    std::thread t2(&TrieTest::ConcurrentInsert, this, 2);
    std::thread t6(&TrieTest::ConcurrentRemove, this, 2);
    std::thread t3(&TrieTest::ConcurrentInsert, this, 3);
    std::thread t7(&TrieTest::ConcurrentRemove, this, 3);
    std::thread t4(&TrieTest::ConcurrentInsert, this, 4);
    std::thread t8(&TrieTest::ConcurrentRemove, this, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
}

int main(int argc, char** argv) {
    // Your code here

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
