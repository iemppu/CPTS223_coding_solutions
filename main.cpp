// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn


/*
Poor Design Choices for Queue
1.Destructor doesnt properly delete entire array, just deletes the first element
2.Poor choice of data structure for queue, linked list should be used instead of array so that we dont need a queue of fixed size
3.Using circular array also massively overcomplicates the code, making it more prone to errors
4.Code should use header files and put function definitions in another source file than main
5.No useful comments to help other coders understand the array code


*/
//cmake .
//cmake --build . --config Release

//most trusted way
//mkdir build
//cd build
//cmake ..
//make

#include "testQueue.h"

// main function
int main()
{
	// call your test functions here!
	testSize();
	testEmpty();
	testFULL();
	testEnqueue();
	testEnqueueFull();
	testDequeue();
	testDequeueEmpty();
	testPeek();
	testPeekEmpty();
	return 0;
}

