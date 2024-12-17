#include "queue.h"
#include "testQueue.h"
#include <limits>
#include <cassert>

void testSize_CSQ(void) {
    cout << "Running Test: Check size of queue - CSQ" << endl;
    
    // Step 1: Construct an empty queue object
    queue q;

    // Step 2: Verify that queue::size() returns 0.  
    assert(q.size() == 0);
    cout << "Step 2 Passed: Initial queue size is 0" << endl;

    // Step 3: Enqueue one element into the queue. 
    q.enqueue(10);

    // Step 4: Verify that queue::size() returns 1.  
    assert(q.size() == 1);
    cout << "Step 4 Passed: Queue size is 1 after enqueueing one element" << endl;

    // Step 5: Enqueue another element into the queue.  
    q.enqueue(20);

    // Step 6: Verify that queue::size() returns 2.  
    assert(q.size() == 2);
    cout << "Step 6 Passed: Queue size is 2 after enqueueing two elements" << endl;

    // Step 7: Dequeue one element from the queue.  
    q.dequeue();

    // Step 8: Verify that queue::size() returns 1.  
    assert(q.size() == 1);
    cout << "Step 8 Passed: Queue size is 1 after dequeuing one element" << endl;

    cout << "Test Passed: Check size of queue - CSQ" << endl;
}

void testEmpty_EQC(void) {
    cout << "Running Test: Empty queue check - EQC" << endl;

    // Step 1: Construct an empty queue object
    queue q;
    
    // Step 2: Call queue::isEmpty() to verify that queue::isEmpty() returns 1
    assert(q.isEmpty() == 1);
    cout << "Step 2 Passed: Queue is empty" << endl;

    cout << "Test Passed: Empty queue check - EQC" << endl;
}

void testFull_FQC(void){
    cout << "Running Test: Full queue check - FQC" << endl;
    
    // Step 1: Construct an empty queue object
    queue q;
    
    // Step 2: Call queue::enqueue() 10 times (recall its defined capacity SIZE = 10 in queue.h)
    for(int i = 0; i < 10; i++){
        q.enqueue(i);
    }
    
    // Step 3: Call queue::isFull() to verify that queue:isFull() returns 1
    assert(q.isFull() == 1);
    cout << "Step 2 Passed: Queue is full" << endl;

    cout << "Test Passed: Full queue check - FQC" << endl;
}

void testEnqueue_ENC1(void) {
    cout << "Running Test: Enqueue check - ENC1" << endl;

    // Step 1: Construct an empty queue object
    queue q;
    
    // Step 2: Call queue::enqueue(10) to add an item to the queue.  
    q.enqueue(10);
    
    // Step 3: Call queue::size() to verify if queue size equals 1
    assert(q.size() == 1);
    cout << "Step 3 Passed: Queue size is 1" << endl;
    
    // Step 4: Call queue::peek() to verify if it returns the front element (10).  
    assert(q.peek() == 10);
    cout << "Step 4 Passed: Queue front is 10" << endl;
    
    // Step 5: Call queue::enqueue(20) to add another item to the queue. 
    q.enqueue(20);
    
    // Step 6: Call queue::size() to verify if queue size equals 2  
    assert(q.size() == 2);
    cout << "Step 6 Passed: Queue size is 2" << endl;
    
    // Step 7: Call queue::peek() to verify if it returns the front element (10).  
    assert(q.peek() == 10);
    cout << "Step 7 Passed: Queue front is 10" << endl;

    cout << "Test Passed: Enqueue check - ENC1" << endl;
}


void testEnqueueFull_ENC2(void) {
    cout << "Running Test: Enqueue check (full queue) - ENC2" << endl;

    // Step 1: Construct an empty queue object
    queue q;
    
    // Step 2: Call queue::enqueue() 10 times (recall its defined capacity SIZE = 10 in queue.h)
    for(int i = 0; i < 10 ; i++) {
        q.enqueue(i);
    }
    
    // Step 3: Call queue::size() to verify if queue size is 10
    assert(q.size() == 10);
    cout << "Step 3 Passed: Queue size is 10" << endl;
    
    // Step 4: Call queue::enqueue() once
    q.enqueue(1);
    
    // Step 5: Call queue::size() to verify that the return value by queue::size() equals 10 (both step 3 and 5)
    assert(q.size() == 10);
    cout << "Step 5 Passed: Queue size is 10" << endl;    

    cout << "Test Passed: Enqueue check (full queue) - ENC2" << endl;
}


void testDequeue_DQC1(void){
    cout << "Running Test: Dequeue check - DQC1" << endl;

    // Step 1: Construct an empty queue object
    queue q;
    // Step 2: Call queue::enqueue() 3 times ([0, 1, 2])
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    
    // Step 3: Call queue::dequeue() 
    q.dequeue();
    
    // Step 4: Call queue::size() to verify that queue::size() returns 2
    assert(q.size() == 2);
    cout << "Step 4 Passed: Queue size is 2" << endl;
    
    // Step 5: Call queue::peek() to verify that queue::peek() returns 1
    assert(q.peek() == 1);
    cout << "Step 5 Passed: Queue front is 1" << endl;   

    cout << "Test Passed: Dequeue check - DQC1" << endl;
}


void testDequeueEmpty_DQC2(void){
    cout << "Running Test: Dequeue check (empty queue) - DQC2" << endl;
    
    // Step 1: Construct an empty queue object
    queue q;
    
    // Step 2: Call queue::dequeue()
    q.dequeue();
    
    // Step 3: Call queue::size() to verify that queue::size() returns 0
    assert(q.size() == 0);
    
    cout << "Test Passed: Dequeue check (empty queue) - DQC2" << endl;
}


void testPeek_PQC1(void){
    cout << "Running Test: peek queue check - PQC1" << endl;
    
    // Step 1. Construct an empty queue object
    queue q;
    
    // Step 2. Call queue::enqueue() with the values [0, 1, 2]
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    
    // Step 3. Call queue::peek() to verify that queue::peek() returns 0
    assert(q.peek() == 0);
    cout << "Step 3 Passed: Queue front is 0" << endl;
    
    cout << "Test Passed: peek queue check - PQC1" << endl;
}


void testPeekEmpty_PQC2(void){
    cout << "Running Test: peek queue check (empty queue) - PQC2" << endl;

    // Step 1. Construct an empty queue object
    queue q;
    
    // Step 2. Call queue::peek() to verify that queue::peek() returns numeric_limits<int>::min()
    assert(q.peek() == numeric_limits<int>::min());
    cout << "Step 2 Passed: Queue front is numeric_limits<int>::min()" << endl;
    
    cout << "Test Passed: peek queue check (empty queue) - PQC2" << endl;
}
