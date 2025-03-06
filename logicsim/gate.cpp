#include <vector>
#include <random>
#include <iostream>

#include "gate.h"
#include "wire.h"

Gate::Gate(int num_inputs, Wire* output) 
	: m_output(output), m_inputs(num_inputs), m_delay(0), m_current_state('X')
{
    
}

Gate::~Gate(){}

void Gate::wireInput(unsigned int id, Wire* in)
{
    if(id < m_inputs.size())
    {
        m_inputs[id] = in;
    }
}

And2Gate::And2Gate(Wire* a, Wire* b, Wire* o) : Gate(2,o)
{
    wireInput(0,a);
    wireInput(1,b);
}

Event* And2Gate::update(uint64_t current_time)
{
    
  char state = '1';
  Event* e = nullptr;
	for(auto w : m_inputs)
	{
		char in = w->getState();
		if(in == '0')
		{
			state = '0';
			break;
		}
		else if(in == 'X')
		{
			state = 'X';
		}
	}
    if(state != m_current_state)
	{
    m_current_state = state;
    uint64_t next = current_time + m_delay;
		e = new Event {next,m_output,state};
         
	}
    return e;
}

Or2Gate::Or2Gate(Wire* a, Wire* b, Wire* o) : Gate(2,o)
{
    wireInput(0,a);
    wireInput(1,b);
}

Event* Or2Gate::update(uint64_t current_time)
{
    
  char state = '0';
  Event* e = nullptr;
	for(auto w : m_inputs)
	{
		char in = w->getState();
		if(in == '1')
		{
			state = '1';
			break;
		}
		else if(in == 'X')
		{
			state = 'X';
		}
	}
  if(state != m_current_state)
	{
    m_current_state = state;
		uint64_t next = current_time + m_delay;
		e = new Event {next,m_output,state};
         
	}
  return e;
}

/* In gate.h and gate.cpp add an implementation of a single input NOT gate called NotGate that derives from Gate. 
It should implement the following truth table:
NOT('X') -> 'X', NOT('0') -> '1', NOT('1') -> '0'. 
Model the state change behavior to be the same as the And2Gate and Or2Gate.
*/

  // not gates have only one input, so use 1 and an output wire
  // also connect an input wire (a - first argument) which is at index 0
NotGate::NotGate(Wire* a, Wire* o) : Gate(1,o)  {
  wireInput(0, a);
}

// Now implement the update function
  // Use the same behavior idea as the And and Or gate
Event* NotGate::update(uint64_t current_time) {
  // First start with the state as 'X' in case the input is undefined
  // and we will need to output it back 
  char state = 'X';
  Event* e = nullptr;

  // Since NOT gate only takes one input, we just check
  // the input wires current state at index 0
  char in = m_inputs[0]->getState();
  // If value is true, switches to false
  if  (in == '1') {
    state = '0';
  }
  // If value is false, switches to true
  else if (in == '0') {
    state = '1';
  }
  else if (in == 'X') {
    state = 'X';
  }

  // This part of the function stays the same
  // if the NOT gate changes, we change the state
  if(state != m_current_state)
	{
    m_current_state = state;
		uint64_t next = current_time + m_delay;
		e = new Event {next, m_output, state};
         
	}

  return e;

}
