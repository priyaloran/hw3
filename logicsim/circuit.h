#ifndef CIRCUIT_H
#define CIRCUIT_H
#include <vector>

#include "../heap.h"
#include "event.h"
#include "gate.h"

class Circuit 
{
	public:
		Circuit();
		~Circuit();
		void test();
		bool advance(std::ostream&);
		void run(std::ostream&);
    bool parse(const char*);
    void startUml(std::ostream&);
    void endUml(std::ostream&);
		
	private:
		uint64_t m_current_time;
    std::vector<Gate*> m_gates;
    std::vector<Wire*> m_wires;
		// we need to add the m_pq data member. It should be a min-heap of Event*;
    
    /* Add the m_pq data member to the Circuit class. 
    This data member must use your Heap class from the previous part of the 
    assignment and it must use the EventLess functor.
    */
    // Heap data structure takes two arguments, type of values used in the heap
    // and a functor
    Heap<Event*, EventLess> m_pq;
        
};

#endif
