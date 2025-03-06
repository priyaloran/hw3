#ifndef HEAP_H
#define HEAP_H
#include <functional>   // This is for less and greater built-in functors
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  // ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  // Let's implement the heap as a dynamic array (vector)
  typename std::vector<T> arr;
  // Also need the m-ary factor used in the constructor
  unsigned int factor;
  // And finally the comparator
  PComparator comp;

  // Heaps always have heapify functions that help for adding or removing
  // values and re-structuring the heap tree property

  // This is for adding a value from the tree
  void heapify1(size_t start);
  // This is for removing a value from the tree
  void heapify2(size_t start);

};

// Add implementation of member functions here

// Use initialization lists to assign m and comp
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) :
  factor(m), comp(c)  {
}

// 1. heapify1()
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify1(size_t start) {
  // Use a while loop to check that the child is not better than the parent
  // as long as we are not at the root
  while (start > 0) {
    // Use math formulas to find parent node
    size_t parent = ((start - 1) / factor);

  // Now do the actual condition to see if we need to recurse the tree
  // Use the comparator!
  if (!comp(arr[start], arr[parent])) {
    break;
  }

  // If heap property is not satisfied, then we swap the values and continue
  // to recurse upward
  std::swap(arr[start], arr[parent]);

  // Change the new starter to the old parent 
  start = parent;
  }

}

// 2. heapify2()  
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify2(size_t start) {
  // Keep a temporary index because we will be changing the "parent"
  // when we recurse down the tree
  size_t temp = start;

  // Let's start with the left child
  // We have to use our factor again and math formulas
  size_t child = ((factor * start) + 1);

  // Use a for loop to check the heap property and every child
  for (size_t i = 0; i < factor; i++) {

    // Retreieve the other child
    size_t right = child + i;

    // Use comparator to check how right compares to left child
    if (right < arr.size() && comp(arr[right], arr[temp]))  {
      // May need to "swap"
      temp = right;
    }

  }
    // If we are at the same node, get out of the loop
    if (temp == start)  {
    }
    else {
      // Otherwise swap the nodes and continue recursing downward
      std::swap(arr[start], arr[temp]);
      heapify2(temp);
    }
  
}

// 3. push()
// Now just use scoping for functions from vector class and my helper functions
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)  {

  // Add to the bottom of the tree and recurse upward
  // to restore property
  arr.push_back(item);
  heapify1(arr.size() - 1);

}

// 4. size()
// Just return the size like normal
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {

  size_t temp = arr.size();
  return temp;

}

// 5. empty()
// Just return if empty like normal
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {

  bool temp = arr.empty();
  return temp;

}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T, PComparator>::top() const {
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()) {
    // ================================
    // throw the appropriate exception
    // ================================
  throw std::underflow_error("Heap is empty");
  }

  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  // This is just the "front" of the array or the "root" of the tree
  return arr[0];

}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop() {
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }

  // If we get here we know the heap has 1 value which
  // we need to remove with our helper functions and some
  // re-workings
  arr[0] = arr.back();
  // Add to the back so "best" value now at back and gets popped
  arr.pop_back();

  // Then restore tree by recursing downward
  // First check it is not empty
  if (!empty()) {
    heapify2(0);
  }

}

/*
template <typename T, typename PComparator>
void Heap<T,PComparator>::~Heap() {}
*/

#endif

