#include <iostream>
#include "stack.h"

using namespace std;

int main()  {

  // First create a stack object
  // Let's fill with doubles
  Stack<double> test;

  // Let's put elements into the structure with push()
  test.push(7.81);
  test.push(8.0);
  test.push(10.01);
  test.push(3.5);
  test.push(1.1);

  // Now let's ensure size is correct
  cout << "The size is " << test.size() << endl;

  // Now let's get the front element
  cout << "The top element is " << test.top() << endl;

  // Now let's remove two elements
  // So the top element should be 10.01
  test.pop();
  test.pop();

  cout << "The new top element after popping is " << test.top() << endl;

  // Now ensure empty works
  test.pop();
  test.pop();
  test.pop();

  if (test.empty()) {
    cout << "empty() worked" << endl;
  }
  else  {
    cout << "empty() didn't work" << endl;
  }

  return 0;
}