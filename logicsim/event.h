#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

/* In event.h write the operator() implementation for EventLess to create a functor for your heap implementation. 
The operator() will take two Event*'s as it’s input and needs to sort them using the Event::time data member 
in such a way that your heap will be a min-heap. i.e. Event's are sorted by time.
*/

// A functor that compares Events by time
typedef struct EventLess {

    // () operator can be written in struct as a way to compare two "time" data members
    // when used outside the function, use a const Event variable so it compares actual 
    // Event objects and call with paranthesis
    // Returns a boolean variable since it is a functor
    // We don't want to change any data members so make a const function
    bool operator()(const Event* first, const Event* second) const {
      // Since most recent times get processed first, we write/check it as less than
      bool output = (first->time) < (second->time);
      return output;
    }

} EventLess;
	
#endif
