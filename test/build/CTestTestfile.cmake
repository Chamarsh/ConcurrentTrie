# CMake generated Testfile for 
# Source directory: /Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test
# Build directory: /Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
include("/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build/runUnitTests[1]_include.cmake")
add_test(AllTestsInTrie "/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/build/runUnitTests")
set_tests_properties(AllTestsInTrie PROPERTIES  _BACKTRACE_TRIPLES "/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/CMakeLists.txt;27;add_test;/Users/chasemarshall/Documents/Projects/C++/ConcurrentTrie/test/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
