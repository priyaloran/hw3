#ifndef LLREC_H
#define LLREC_H
#ifndef NULL
#define NULL 0
#endif

/**
 * Node struct for both problems
 */
struct Node
{
    int val;
    Node *next;

    Node(int v, Node* n) : val(v), next(n) {}
};


/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */

// This function is to be used in the llpivot function to make our
// program easier to implement and so we don't have to keep
// track of large chunks of code
void helper(Node* head, Node*& smaller, Node*& larger, Node*& end1, Node*& end2, int pivot);

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot);

/**
 * Given a linked list pointed to by head, removes (filters out) nodes
 * whose value does not meet the criteria given by the predicate
 * function object, pred (i.e. pred should be a function object that implements
 * `bool operator()(int value)` and returns *true* for items that should
 * be *removed/filtered*.  Removed items should be deallocated.
 *
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @param[in] head
 *   Reference to the head pointer to the input list.
 * @param[in] pred
 *   Predicate object implementing: `bool operator()(int value)` that
 *   returns true if a node (based on its value) should be removed.
 * @return a head pointer to the resulting list (since the head pointer
 *   may change [i.e. be filtered])
 *
 */
template <typename Comp>
Node* llfilter(Node* head, Comp pred);

//*****************************************************************************
// Since template implementations should be in a header file, we will
// implement the above function now.
//*****************************************************************************

    //*********************************************
    // Provide your implementation below
    //*********************************************

/* Now lets implement the filter function
Compares types based on a certain criteria provided in the
comparator function
Comparators define the () operator so we will use that in 
our function to compare value of types unknown
Run in O(n)
Return a pointer to a node of the list that Now
contains a list filtered out by the criteria
*/

// Still have to provide the typename template before class definition
template <typename Comp>
Node* llfilter(Node* head, Comp pred) {

  // First is the base case which again checks if the head
  // is NULL to signify the end of the list
  if (head == NULL) {
    return NULL;
  }

  // Now our recursive cases
  Node* temp = head->next;

  // We can use our comparator function here to check the condition
  // Lets first check if the condition is true for our value at the node
  // The comparator struct was passed in as pred and () is defined for this
  if (pred(head->val))  {
    delete head;  // When the condition is true we delete this node. We have it saved
    head = NULL;
    return llfilter(temp, pred);  // now return the rest of the list to recurse on
  }
  else  {
    head->next = llfilter(temp, pred);  // When the condition is false, we keep the node and recurse on the rest
    return head;        // Return the list as is at the head with the valid value
  }
}

#endif
