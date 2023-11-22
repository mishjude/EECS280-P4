#ifndef LIST_HPP
#define LIST_HPP
/* List.hpp
 *
 * doubly-linked, double-ended list with Iterator interface
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:
  //default constructor 
  List() : first(nullptr), last(nullptr) {}

  //destructor 
  ~List(){
    clear();
  }

  //copy constructor 
  List(const List &copy) : first(nullptr), last(nullptr) {
    copy_all(copy);
  }

  //overloaded assignment operator
  List &operator=(const List &second_list) {
    if (this == &second_list) {
      return *this;
    } else {
      clear();
      copy_all(second_list);
      return *this;
    } 
  }

  //EFFECTS:  returns true if the list is empty
  bool empty() const{
    return first == nullptr;
  }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
  int size() const {
    int list_size = 0;
    for (Node *node_ptr = first; node_ptr; node_ptr = node_ptr->next) {
      list_size +=1;
    }
    return list_size;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front() {
    assert(!empty());
    return first->datum;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back(){
    assert(!empty());
    return last->datum;
  }

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum){
    Node *new_first = new Node{};
    new_first->datum = datum;
    new_first->prev = nullptr;
    new_first->next = first;
    

    if (first == nullptr) {
      first = new_first;
      last = new_first;
    } else {
      first->prev = new_first;
      first = new_first;
      
    }
  } 


  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum){
    
    Node *new_last = new Node{};
    new_last->datum = datum;
    new_last->prev = last;
    new_last->next = nullptr;
    
    
    if (first == nullptr) {
      first = new_last;
      last = new_last;

    } else {
      last->next = new_last;
      last = new_last;
    }
    
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front(){
    assert(!empty());
    if (first == last) {
      //Node *new_node = new Node;
      //new_node = first;
      delete first;
      first = nullptr;
      last = nullptr;
      //delete new_node;
    } else {
      Node *new_node = first;
      //new_node = first;
      first = first->next;
      first->prev = nullptr;
      delete new_node;
      new_node = nullptr;
    }
    
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back(){
    assert(!empty());
    if (first == last) {
      //Node *new_node = new Node{};
      //new_node = first;
      delete first;
      first = nullptr;
      last = nullptr;
      //delete new_node;
    } else {
      Node *new_node = last;
      //new_node = last;
      last = last->prev;
      last->next = nullptr;
      delete new_node;
      new_node = nullptr;
    }
    
  }

  

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the lists
  void clear() {
    while (!empty()) {
      pop_back();
    }
  }

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other){
    Node *new_node = new Node{};
    for (new_node = other.first; new_node != nullptr; new_node++) {
      push_back(new_node->datum);
    }
    
    delete new_node;
  }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

  public:
    //default constructor 
    

    //overloaded assignment operators
    //operator ++
    Iterator &operator++() {
      assert(node_ptr);
      node_ptr = node_ptr->next;
      return *this;
    }

    //operator ==
    bool operator==(Iterator right) const {
      return node_ptr == right.node_ptr;
    }

    //operator !=
    bool operator!=(Iterator right) const {
      return node_ptr != right.node_ptr;
    }

    //operator *
    T &operator*() const {
      assert(node_ptr != nullptr);
      return node_ptr->datum;
    }

    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator &operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }

  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
    friend class List;

    // construct an Iterator at a specific position
    Iterator(Node *p) : node_ptr(p) {} //changed this but i'm not sure if that was okay?? 
    //wasn't compiling when i put this up higher in the public section
    Iterator()  : node_ptr(nullptr){} // ctors should be private right???
    

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const {
    return Iterator(nullptr); 
  }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  void erase(Iterator i) {
    
    if (i.node_ptr == nullptr) {
      return;
    }
    
    if (i.node_ptr == first) {
      first = i.node_ptr->next;
    }

    if (i.node_ptr == last) {
      last = i.node_ptr->prev;
    }

    if (i.node_ptr->next != nullptr) {
      i.node_ptr->next->prev = i.node_ptr->prev;
    }

    if (i.node_ptr->prev != nullptr) {
      i.node_ptr->prev->next = i.node_ptr->next;
    }

    delete i.node_ptr;

  }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum){
    if (i.node_ptr != nullptr) {
      Node *new_node = new Node;
      new_node->datum = datum;
      new_node->prev = i.node_ptr->prev;
      new_node->next = i.node_ptr;
      if (i.node_ptr->prev != nullptr) {
        i.node_ptr->prev->next = new_node;
      } else {
        first = new_node;
      }
      i.node_ptr->prev = new_node;
    }
  }
};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.


#endif // Do not remove this. Write all your code above this line.