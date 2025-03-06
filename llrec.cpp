#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

/* Recursive function to split single LL into two lists (original is gone)
One is less than or equal to given number
Other is greater than the given number
Takes in pointer references and a copy to the value we split the list on
Move nodes out of the input list and into the two other lists (so head list is empty)
*/

void helper(Node* head, Node*& smaller, Node*& larger, Node*& end1, Node*& end2, int pivot) {

  // Recursive functions start with a base case, here we have to check
  // if the list (original list which is head) is NULL
  if (head == NULL) {
    return;
  }

  // Now our recursive cases
  // This will be used to recurse when we call helper again
  // We want to "detach" it from the original list
  Node* temp = head->next;
  head->next = NULL;

  // Now we must build the lists. Let's start with larger
  // If the value of the current node is greater than the pivot 
  // value, add it to the large list
  // Make sure it is not in reverse order!
  // To do this we save the tail of the list and 
  // connect it to the new element or back to the front
  // (so it is at the end)
  if (head->val > pivot)  {
    if (larger == NULL)  {
      larger = head;
      end2 = head;
    }
    else  {
      end2->next = head;
      end2 = head;
    }
  }
  else  {
    if (smaller == NULL)  {
      smaller = head;
      end1 = head;
    }
    else  {
      end1->next = head;
      end1 = head;
    }
  }

  // Now call the recursive helper again but on a smaller list
  // and it will go until the list ends (NULL)
  helper(temp, smaller, larger, end1, end2, pivot);

}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  
  // Original lists 
  smaller = NULL;
  larger = NULL;
  Node* end1 = NULL;
  Node* end2 = NULL;

  // Helper function
  helper(head, smaller, larger, end1, end2, pivot);

  // Ensure the head is empty by pointing it to NULL
  head = NULL;

}

