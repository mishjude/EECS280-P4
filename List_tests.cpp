#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here


TEST(test_empty_list) {
    List<int> empty_list; 
    ASSERT_EQUAL(empty_list.size(),0); 
}

TEST(test_default_ctor) {
    List<int> list;
    ASSERT_TRUE(list.empty());
}

TEST_MAIN()
