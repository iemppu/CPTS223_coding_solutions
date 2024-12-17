#include "my_queue.h"
#include "test_queue.h"
#include <limits>
#include <cassert>

void testSize_QSC(void) {
    std::cout << "Running Test: Check size of queue - QSC" << std::endl;
    
    // Step 1: Construct an empty queue object
    Queue q;

    // Step 2: Verify that Queue::size() returns 0.  
    assert(q.size() == 0);
    std::cout << "Step 2 Passed: Initial queue size is 0" << std::endl;

    // Step 3: Enqueue one element into the queue. 
    q.enqueue(10);

    // Step 4: Verify that Queue::size() returns 1.  
    assert(q.size() == 1);
    std::cout << "Step 4 Passed: Queue size is 1 after enqueueing one element" << std::endl;

    // Step 5: Enqueue another element into the queue.  
    q.enqueue(20);

    // Step 6: Verify that Queue::size() returns 2.  
    assert(q.size() == 2);
    std::cout << "Step 6 Passed: Queue size is 2 after enqueueing two elements" << std::endl;

    // Step 7: Dequeue one element from the queue.  
    q.dequeue();

    // Step 8: Verify that Queue::size() returns 1.  
    assert(q.size() == 1);
    std::cout << "Step 8 Passed: Queue size is 1 after dequeuing one element" << std::endl;

    std::cout << "Test Passed: Check size of queue - QSC" << std::endl;
}

void testEmpty_EQC(void) {
    std::cout << "Running Test: Empty queue check - EQC" << std::endl;

    // Step 1: Construct an empty queue object
    Queue q;
    
    // Step 2: Call Queue::isEmpty() to verify that Queue::isEmpty() returns 1
    assert(q.isEmpty() == 1);
    std::cout << "Step 2 Passed: Queue is empty" << std::endl;

    std::cout << "Test Passed: Empty queue check - EQC" << std::endl;
}

void testFull_FQC(void){
    std::cout << "Running Test: Full queue check - FQC" << estd::ndl;
    
    // Step 1: Construct an empty queue object
    Queue q;
    
    // Step 2: Call Queue::enqueue() 10 times (recall its defined capacity SIZE = 10 in queue.h)
    for(int i = 0; i < 10; i++){
        q.enqueue(i);
    }
    
    // Step 3: Call Queue::isFull() to verify that queue:isFull() returns 1
    assert(q.isFull() == 1);
    std::cout << "Step 2 Passed: Queue is full" << std::endl;

    std::cout << "Test Passed: Full queue check - FQC" << std::endl;
}

void testEnqueue_ENC1(void) {
    std::cout << "Running Test: Enqueue check - ENC1" << std::endl;

    // Step 1: Construct an empty queue object
    Queue q;
    
    // Step 2: Call Queue::enqueue(10) to add an item to the queue.  
    q.enqueue(10);
    
    // Step 3: Call Queue::size() to verify if queue size equals 1
    assert(q.size() == 1);
    std::cout << "Step 3 Passed: Queue size is 1" << std::endl;
    
    // Step 4: Call Queue::peek() to verify if it returns the front element (10).  
    assert(q.peek() == 10);
    std::cout << "Step 4 Passed: Queue front is 10" << std::endl;
    
    // Step 5: Call Queue::enqueue(20) to add another item to the queue. 
    q.enqueue(20);
    
    // Step 6: Call Queue::size() to verify if queue size equals 2  
    assert(q.size() == 2);
    std::cout << "Step 6 Passed: Queue size is 2" << std::endl;
    
    // Step 7: Call Queue::peek() to verify if it returns the front element (10).  
    assert(q.peek() == 10);
    std::cout << "Step 7 Passed: Queue front is 10" << std::endl;

    std::cout << "Test Passed: Enqueue check - ENC1" << std::endl;
}


void testEnqueueFull_ENC2(void) {
    std::cout << "Running Test: Enqueue check (full queue) - ENC2" << std::endl;

    // Step 1: Construct an empty queue object
    Queue q;
    
    // Step 2: Call Queue::enqueue() 10 times (recall its defined capacity SIZE = 10 in queue.h)
    for(int i = 0; i < 10 ; i++) {
        q.enqueue(i);
    }
    
    // Step 3: Call Queue::size() to verify if queue size is 10
    assert(q.size() == 10);
    std::cout << "Step 3 Passed: Queue size is 10" << std::endl;
    
    // Step 4: Call Queue::enqueue() once
    q.enqueue(1);
    
    // Step 5: Call Queue::size() to verify that the return value by Queue::size() equals 10 (both step 3 and 5)
    assert(q.size() == 10);
    std::cout << "Step 5 Passed: Queue size is 10" << std::endl;    

    std::cout << "Test Passed: Enqueue check (full queue) - ENC2" << std::endl;
}


void testDequeue_DQC1(void){
    std::cout << "Running Test: Dequeue check - DQC1" << std::endl;

    // Step 1: Construct an empty queue object
    Queue q;
    // Step 2: Call Queue::enqueue() 3 times ([0, 1, 2])
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    
    // Step 3: Call Queue::dequeue() 
    q.dequeue();
    
    // Step 4: Call Queue::size() to verify that Queue::size() returns 2
    assert(q.size() == 2);
    std::cout << "Step 4 Passed: Queue size is 2" << std::endl;
    
    // Step 5: Call Queue::peek() to verify that Queue::peek() returns 1
    assert(q.peek() == 1);
    std::cout << "Step 5 Passed: Queue front is 1" << std::endl;   

    std::cout << "Test Passed: Dequeue check - DQC1" << std::endl;
}


void testDequeueEmpty_DQC2(void){
    std::cout << "Running Test: Dequeue check (empty queue) - DQC2" << std::endl;
    
    // Step 1: Construct an empty queue object
    Queue q;
    
    // Step 2: Call Queue::dequeue()
    q.dequeue();
    
    // Step 3: Call Queue::size() to verify that Queue::size() returns 0
    assert(q.size() == 0);
    
    std::cout << "Test Passed: Dequeue check (empty queue) - DQC2" << std::endl;
}


void testPeek_PQC1(void){
    std::cout << "Running Test: peek queue check - PQC1" << std::endl;
    
    // Step 1. Construct an empty Queue object
    Queue q;
    
    // Step 2. Call Queue::enqueue() with the values [0, 1, 2]
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    
    // Step 3. Call Queue::peek() to verify that Queue::peek() returns 0
    assert(q.peek() == 0);
    std::cout << "Step 3 Passed: Queue front is 0" << std::endl;
    
    std::cout << "Test Passed: peek queue check - PQC1" << std::endl;
}


void testPeekEmpty_PQC2(void){
    std::cout << "Running Test: peek queue check (empty queue) - PQC2" << std::endl;

    // Step 1. Construct an empty queue object
    queue q;
    
    // Step 2. Call Queue::peek() to verify that Queue::peek() returns numeric_limits<int>::min()
    assert(q.peek() == numeric_limits<int>::min());
    std::cout << "Step 2 Passed: Queue front is numeric_limits<int>::min()" << std::endl;
    
    std::cout << "Test Passed: peek queue check (empty queue) - PQC2" << std::endl;
}
