#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <chrono>
#include <cmath>
#include <random>
#include <cassert>
#include <sstream>
#include "BST.h"

void testInOrderTraversal(BST<int>* bst) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    bst->printInOrder();
    std::cout.rdbuf(oldCout);
    std::string expected = "-10 -> -1 -> 1 -> 6 -> 11 -> 100 -> </s>";
    assert(buffer.str() == expected);
}

void testPrintLevels(BST<int>* bst) {
	std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    bst->printLevels();
    std::cout.rdbuf(oldCout);
    std::string expected = "Level 0: 11 \nLevel 1: 1 100 \nLevel 2: -1 6 \nLevel 3: -10 \n";
    assert(buffer.str() == expected);
}

void testContain(BST<int>* bst) {
	assert(bst->contains(100) == 1);
	assert(bst->contains(9) == 0);
}

void testSize(BST<int>* bst) {
	assert(bst->treeSize() == 6);
}

void testHeight(BST<int>* bst) {
	assert(bst->treeHeight() == 3);
}

void testPrintMaxPath(BST<int>* bst) {
	std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    bst->printMaxPath();
    std::cout.rdbuf(oldCout);
    std::string expected = "11 -> 1 -> -1 -> -10 -> </s>";
    assert(buffer.str() == expected);
}

void testDelete(BST<int>* bst) {
	bst->remove(11);
	assert(bst->contains(11) == 0);
}

int main(int argc, char** argv)
{
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(0)));

    // BST initialization: simple 6 inputs
    BST<int> *bst = new BST<int>();
    bst->insert(11);
    bst->insert(1);
    bst->insert(6);
    bst->insert(-1);
    bst->insert(-10);
    bst->insert(100);

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <testName>" << std::endl;
        return 1;
    }

    std::string testName = argv[1];

    try {
        if (testName == "TestInOrderTraversal") {
            testInOrderTraversal(bst);
			std::cout << std::endl;
		}
		else if (testName == "TestPrintLevels") {
			testPrintLevels(bst);
			std::cout << std::endl;
		}
		else if (testName == "TestContain") {
			testContain(bst);
			std::cout << std::endl;
		}
		else if (testName == "TestSize") {
			testSize(bst);
			std::cout << std::endl;
		}
		else if (testName == "TestHeight") {
			testHeight(bst);
			std::cout << std::endl;
		}
		else if (testName == "TestPrintMaxPath") {
			testPrintMaxPath(bst);
			std::cout << std::endl;
		}
		else if (testName == "TestDelete") {
			testDelete(bst);
			std::cout << std::endl;
        } else {
            std::cerr << "Unknown test: " << testName << std::endl;
            return 1;
        }

        std::cout << "Test Passed: " << testName << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test Failed: " << testName << " - " << e.what() << std::endl;
        return 1;
    }

    // Delete this bst
    delete bst;

    return 0;
}
