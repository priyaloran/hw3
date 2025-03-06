#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------





int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // llpivot() test:
    Node* smaller = NULL;
    Node* larger = NULL;

    // Make a value the function checks for
    int val = 3;
    cout << "Pivot value: 3" << endl;
    llpivot(head, smaller, larger, val);

    // Now check the lists
    cout << "Smaller list: ";
    print(smaller);
    cout << "Larger list: ";
    print(larger);

    // llfilter() test
    // We have to create a comparator for the second function
    struct neg  {
      bool operator() (int val) {
        if (val < 0)  {
          return true;
        }
        return false;
      }
    };

    // Test the function with the comparator struct
    neg negative;
    Node* test = llfilter(smaller, negative);

    // Now check the list
    print(test);

    // Use deallocation functions
    dealloc(test);
    dealloc(larger);
    
    return 0;
}