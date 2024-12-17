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

	std::cout << "PrintInOrder test passed!" << endl;
}

void testPrintLevels(BST<int>* bst) {
	std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    bst->printLevels();
    std::cout.rdbuf(oldCout);
    
    std::string expected = " Level 0: 11 \n Level 1: 1 100 \n Level 2: -1 6 \n Level 3: -10 \n";
    assert(buffer.str() == expected);

	std::cout << "PrintLevels test passed!" << endl;
}


// cout << "(1.2) Print BST in level order: " << endl;
// bst->printLevels();

// cout << "(1.3) Is 100 in BST? true (1) or false (0): " << bst->contains(100) << endl;

// cout << "(1.4) Is 9 in BST? true (1) or false (0): " << bst->contains(9) << endl;

// cout << "(1.5) BST size: " << bst->treeSize() << endl;

// cout << "(1.6) Height of BST: " << bst->treeHeight() << endl;

// cout << "(1.7) Print max path: " << endl << " ";
// bst->printMaxPath();
// cout << endl;

// bst->remove(11);
// cout << "(1.8) Removing 11, print BST (in-order traversal): " << endl << " ";
// bst->printInOrder();
// cout << endl;

// cout << "(1.9) Print BST in level order: " << endl;
// bst->printLevels();

// cout << "(1.10) BST size: " << bst->treeSize() << endl;



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
        if (testName == "InOrderTraversal") {
            testInOrderTraversal(bst);
		}
		else if (testName == "PrintLevels") {
			testPrintLevels(bst);
		// }
		// else if (testName == "TestContain") {
		// 	testContain(bst);
		// }
		// else if (testName == "TestSize") {
		// 	testSize(bst);
		// }
		// else if (testName == "TestHeight") {
		// 	testHeigth(bst);
		// }
		// else if (testName == "PrintMaxPath") {
		// 	testPrintMaxPath(bst);
		// }
		// else if (testName == "TestDelete") {
		// 	testDelete(bst);
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
