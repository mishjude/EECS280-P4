#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(test_stub) {
    // Add test code here
    ASSERT_TRUE(true);
}

TEST(test_def_ctor) {
    List<int> list;
    ASSERT_TRUE(list.empty());

}

TEST(test_empty) {
    List<int> list;
    list.push_front(1);
    ASSERT_FALSE(list.empty());
}

TEST(test_single_element_size) {
    List<int> list;
    list.push_front(1);
    ASSERT_EQUAL(list.size(), 1);
}

TEST(test_repeated_element_size) {
    List<int> list;
    list.push_front(1);
    list.push_front(1);
    list.push_front(1);
    list.push_front(1);
    ASSERT_EQUAL(list.size(), 4);
}

TEST(test_big_list_size) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    list.push_front(-2);
    list.push_front(34);
    list.push_front(-937);
    ASSERT_EQUAL(list.size(), 6);
}

TEST(test_push_front) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    ASSERT_EQUAL(list.front(), 3);
}
TEST_MAIN()
