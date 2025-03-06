CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

llrec-test: llrec-test.o llrec.o
		$(CXX) $(CXXFLAGS) -o llrec-test llrec-test.o llrec.o
llrec-test.o: llrec-test.cpp llrec.h
		$(CXX) $(CXXFLAGS) -c llrec-test.cpp
llrec.o: llrec.cpp llrec.h
		$(CXX) $(CXXFLAGS) -c llrec.cpp
stack-test: stack-test.o
		$(CXX) $(CXXFLAGS) -o stack-test stack-test.o
stack-test.o: stack-test.cpp stack.h
		$(CXX) $(CXXFLAGS) -c stack-test.cpp
heap-test: heap-test.o heap.o
		$(CXX) $(CXXFLAGS) -o heap-test heap-test.o heap.o
heap-test.o: heap-test.cpp heap.h
		$(CXX) $(CXXFLAGS) -c heap-test.cpp
heap.o: heap.cpp heap.h
		$(CXX) $(CXXFLAGS) -c heap.cpp

clean:
		rm -f *.o rh llrec-test *~

.PHONY: clean 