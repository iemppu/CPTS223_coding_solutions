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
#include "test_queue.h"

int main(int argc, char** argv)
{

	if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <testName>" << std::endl;
        return 1;
    }

    std::string testName = argv[1];
	std::cout << "Test starts: " << testName << std:endl;
    try {
        if (testName == "QSC") {
            testSize_QSC();
		}
		else if (testName == "EQC") {
			testEmpty_EQC();
		}
		else if (testName == "FQC") {
			testFull_FQC();
		}
		else if (testName == "ENC1") {
			testEnqueue_ENC1();
		}
		else if (testName == "ENC2") {
			testEnqueueFull_ENC2();
		}
		else if (testName == "DQC1") {
			testDequeue_DQC1();
		}
		else if (testName == "DQC2") {
			testDequeueEmpty_DQC2();
		}
		else if (testName == "PQC1") {
			testPeek_PQC1();
		}
		else if (testName == "PQC2") {
			testPeekEmpty_PQC2();
        } else {
            std::cerr << "Unknown test: " << testName << std::endl;
            return 1;
        }

        std::cout << "Test Passed: " << testName << std::endl << std:endl;
    } catch (const std::exception& e) {
        std::cerr << "Test Failed: " << testName << " - " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

