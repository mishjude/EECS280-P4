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

TEST(test_size_0) {
    List<int> list;
    ASSERT_EQUAL(list.size(), 0);
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

    List<int> list2;
    list2.push_front(-4);
    list2.push_front(27);
    list2.push_back(32);
    ASSERT_EQUAL(list2.front(), 27);
}

TEST(test_push_back) {
    List<int> list;
    list.push_back(1);
    list.push_back(7);
    list.push_back(3);
    ASSERT_EQUAL(list.back(), 3);

    List<int> list2;
    list2.push_front(-4);
    list2.push_front(27);
    list2.push_back(32);
    ASSERT_EQUAL(list2.back(), 32);
}

TEST(test_pop_front) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    list.push_front(-2);
    list.push_front(34);
    list.push_front(-937);
    list.pop_front();
    ASSERT_EQUAL(list.front(), 34);

    list.pop_front();
    ASSERT_EQUAL(list.front(), -2);

    list.pop_front();
    ASSERT_EQUAL(list.front(), 3);

    list.pop_front();
    ASSERT_EQUAL(list.front(), 7);

    list.pop_front();
    ASSERT_EQUAL(list.front(), 1);

    list.pop_front();
    ASSERT_TRUE(list.empty());

}

TEST(test_pop_back) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    list.push_front(-2);
    list.push_front(34);
    list.push_front(-937);
    list.pop_back();
    ASSERT_EQUAL(list.back(), 7);

    list.pop_back();
    ASSERT_EQUAL(list.back(), 3);

    list.pop_back();
    ASSERT_EQUAL(list.back(), -2);

    list.pop_back();
    ASSERT_EQUAL(list.back(), 34);

    list.pop_back();
    ASSERT_EQUAL(list.back(), -937);

    list.pop_back();
    ASSERT_TRUE(list.empty());
}

TEST(test_clear) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    list.push_front(-2);
    list.push_front(34);
    list.push_front(-937);

    list.clear();

    ASSERT_TRUE(list.empty());
    
}


TEST(test_iterator_ctor) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    List<int>::Iterator iter = list.begin();
    ASSERT_EQUAL(*iter, 3);
}



TEST(test_iterator_forward) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    List<int>::Iterator iter = list.begin();
    ++iter;
    ASSERT_EQUAL(*iter, 7);
    ++iter;
    ASSERT_EQUAL(*iter, 1);

}



TEST(test_iterator_backward) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    List<int>::Iterator iter = list.begin();
    ++iter;
    --iter;
    ASSERT_EQUAL(*iter, 3);
    
}



TEST(test_iterator_equal) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    List<int>::Iterator iter = list.end();
    List<int>::Iterator iter2 = list.end();
    ASSERT_EQUAL(iter, iter2);

    List<int> list2;
    list2.push_front(1);
    list2.push_front(7);
    list2.push_front(3);
    List<int>::Iterator iter3 = list.begin();
    List<int>::Iterator iter4 = list.begin();
    ++iter3;
    ASSERT_NOT_EQUAL(*iter3, *iter4);

}



TEST(test_iterator_not_equal) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    List<int>::Iterator iter = list.begin();
    List<int>::Iterator iter2 = list.begin();
    ++iter;
    ASSERT_TRUE(*iter != *iter2);

}


TEST(test_iterator_deref) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    List<int>::Iterator iter = list.begin();
    ASSERT_EQUAL(*iter, 3);
    ASSERT_EQUAL(*++iter, 7);
    ASSERT_EQUAL(*--iter, 3);
}



TEST(test_iterator_begin_and_end_single) {
    List<int> list;
    list.push_front(1);
    List<int>::Iterator iter = list.begin();
    List<int>::Iterator iter2 = list.end();
    ++iter;
    ASSERT_EQUAL(iter, iter2);


}


TEST(test_iterator_begin) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    List<int>::Iterator iter = list.begin(); //i'm adding some tests below

    ASSERT_EQUAL(*iter, 3);
    list.pop_front();
    iter = list.begin();
    ASSERT_EQUAL(*iter, 7);
    list.pop_front();
    iter = list.begin();
    ASSERT_EQUAL(*iter, 1);

}


TEST(test_iterator_end) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    List<int>::Iterator iter = list.begin();
    List<int>::Iterator iter2 = list.end();
    ++iter;
    ++iter;
    ++iter;
    ASSERT_EQUAL(iter, iter2);
   
}


TEST(test_iterator_erase) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    List<int>::Iterator iter = list.begin();
    list.erase(iter);
    iter = list.begin();
    ASSERT_EQUAL(*iter, 7);

    list.erase(iter);
    iter = list.begin();
    ASSERT_EQUAL(*iter, 1);

    List<int> list2;
    list2.push_front(2);
    list2.push_front(3);
    List<int>::Iterator iter2 = list2.begin();
    ++iter2;
    list2.erase(iter2);
    ASSERT_EQUAL(list2.size(), 1);

}

TEST(test_iterator_erase_single) {
    List<int> list;
    list.push_front(1);
    List<int>::Iterator iter = list.begin();
    list.erase(iter);
    ASSERT_TRUE(list.empty());
}

TEST(test_iterator_insert) {
    List<int> list;
    list.push_front(1);
    list.push_front(7);
    list.push_front(3);
    List<int>::Iterator iter = list.begin();
    list.insert(iter, 4);
    iter = list.begin();
    ASSERT_EQUAL(*iter, 4);

    ++iter;
    list.insert(iter, 9);
    iter = list.begin();
    ++iter;
    ASSERT_EQUAL(*iter, 9);

}

TEST(test_string_iter) {
    List<string> str_list;
    str_list.push_front("hello");
    str_list.push_back("world");
    List<string>::Iterator i = str_list.begin();
    ASSERT_EQUAL(*i, "hello");
    ++i;
    ASSERT_EQUAL(*i, "world");
}

TEST(test_iter_addresses) {
    List<int> list;
    list.push_back(1);
    List<int>::Iterator i = list.begin();
    List<int>::Iterator j = list.begin();
    ASSERT_TRUE(i == j);
    ASSERT_EQUAL(*i, *j);
}

TEST(test_iter_loop) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(10);
    List<int>::Iterator iter = list.begin();
    while(*iter != 10) {
        ++iter;
    }
    ASSERT_EQUAL(*iter, list.back());

}


TEST_MAIN()
