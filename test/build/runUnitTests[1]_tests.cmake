add_test([=[TrieTest.Insert]=]  [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build/runUnitTests]==] [==[--gtest_filter=TrieTest.Insert]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TrieTest.Insert]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TrieTest.Search]=]  [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build/runUnitTests]==] [==[--gtest_filter=TrieTest.Search]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TrieTest.Search]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TrieTest.StartsWith]=]  [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build/runUnitTests]==] [==[--gtest_filter=TrieTest.StartsWith]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TrieTest.StartsWith]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TrieTest.Remove]=]  [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build/runUnitTests]==] [==[--gtest_filter=TrieTest.Remove]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TrieTest.Remove]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TrieTest.ConcurrentInsert]=]  [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build/runUnitTests]==] [==[--gtest_filter=TrieTest.ConcurrentInsert]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TrieTest.ConcurrentInsert]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TrieTest.ConcurrentSearch]=]  [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build/runUnitTests]==] [==[--gtest_filter=TrieTest.ConcurrentSearch]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TrieTest.ConcurrentSearch]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TrieTest.ConcurrentRemove]=]  [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build/runUnitTests]==] [==[--gtest_filter=TrieTest.ConcurrentRemove]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TrieTest.ConcurrentRemove]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TrieTest.ConcurrentStartsWith]=]  [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build/runUnitTests]==] [==[--gtest_filter=TrieTest.ConcurrentStartsWith]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TrieTest.ConcurrentStartsWith]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TrieTest.ConcurrentInsertAndRemove]=]  [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build/runUnitTests]==] [==[--gtest_filter=TrieTest.ConcurrentInsertAndRemove]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TrieTest.ConcurrentInsertAndRemove]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  runUnitTests_TESTS TrieTest.Insert TrieTest.Search TrieTest.StartsWith TrieTest.Remove TrieTest.ConcurrentInsert TrieTest.ConcurrentSearch TrieTest.ConcurrentRemove TrieTest.ConcurrentStartsWith TrieTest.ConcurrentInsertAndRemove)
