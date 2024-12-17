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

#include <iostream>
#include <string>
#include "testQueue.h"

// main function
int main(int argc, char** argv)
{

	if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <test_name>" << std::endl;
        return 1;
    }

    std::string test_name = argv[1];

    try {
        if (test_name == "CSQ") {
            testSize_CSQ();
		}
		elsif (test_name == "EQC") {
			testEmpty_EQC();
        } else {
            std::cerr << "Unknown test: " << test_name << std::endl;
            return 1;
        }

        std::cout << "Test Passed: " << test_name << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test Failed: " << test_name << " - " << e.what() << std::endl;
        return 1;
    }

    return 0;
	
	// // call your test functions here!
	// testSize();
	// testEmpty();
	// testFULL();
	// testEnqueue();
	// testEnqueueFull();
	// testDequeue();
	// testDequeueEmpty();
	// testPeek();
	// testPeekEmpty();
	// return 0;
}

