#include <iostream>
#include <functional>
#include "heap.h"

using namespace std;

int main()  {

  // First create a min heap object
  // Let's fill with doubles
  Heap<double, std::less<double>> test;

  cout << "MIN HEAP Tests" << endl;

  // Let's put elements into the structure with push()
  test.push(7.81);
  test.push(8.0);
  test.push(10.01);
  test.push(3.5);
  test.push(1.1);

  // Now let's ensure size is correct
  cout << "The size is " << test.size() << endl;

  // Now let's get the front element which should be smallest (1.1)
  cout << "The top element is " << test.top() << endl;

  // Now let's remove elements and top() them one by one
  while (!test.empty()) {
    cout << test.top() << " ";
    test.pop();
  }
  cout << endl;

  // Next create a max heap object
  // Let's fill with doubles
  Heap<double, std::greater<double>> test2;

  cout << "MAX HEAP Tests" << endl;

  // Let's put elements into the structure with push()
  test2.push(7.81);
  test2.push(8.0);
  test2.push(10.01);
  test2.push(3.5);
  test2.push(1.1);

  // Now let's ensure size is correct
  cout << "The size is " << test2.size() << endl;

  // Now let's get the front element which should be smallest (1.1)
  cout << "The top element is " << test2.top() << endl;

  // Now let's remove elements and top() them one by one
  while (!test2.empty()) {
    cout << test2.top() << " ";
    test2.pop();
  }
  cout << endl;

  return 0;
}