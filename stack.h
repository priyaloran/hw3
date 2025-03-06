#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>    // Should be private so no 3rd party code uses vector operations
{
public:
    Stack();
    // ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

// Let's start with the constructor
// Since we are using vector inheritance, we don't 
// need other data member
template <typename T>
Stack<T>::Stack() {}

// 1. size()
// Since vector already has this class definition, just use with scoping
template <typename T>
size_t Stack<T>::size() const {

  size_t size = std::vector<T>::size();
  return size;

}

// 2. empty()
// Since vector already has this class definition, just use with scoping
template <typename T>
bool Stack<T>::empty() const {

  bool empty = std::vector<T>::empty();
  return empty;

}  

// 3. push()
// We are basically using the vector's push back function but
// stack only supports this at the top of the list
template <typename T>
void Stack<T>::push(const T& item)  {

  std::vector<T>::push_back(item);

}

// 4. pop()
template <typename T>
void Stack<T>::pop()  {

  // First check if the stack is empty to throw an exception
  if (empty())  {
    throw std::underflow_error("Stack is empty");
  }
  // And if it is not, then retrieve the top item
  std::vector<T>::pop_back();

}

// 5. top()
template <typename T>
T const& Stack<T>::top() const  {

  // First check if the stack is empty to throw an exception
  if (empty())  {
    throw std::underflow_error("Stack is empty");
  }
  // And if it is not, then return the top item
  return std::vector<T>::back();

}

// Destructor is last
// Stack<T>::~Stack()  {}

#endif