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
    
    // Step 2: Call queue::isEmpty()
    // Step 3: Verify that the return value by queue::isEmpty() equals 1
    assert(q.isEmpty() == 1);
    cout << "Step 3 Passed: Queue is empty" << endl;

    cout << "Test Passed: Empty queue check - EQC" << endl;
}

void testFull_FQC(void){

    queue main;
    for(int i = 0;i<10;i+=1){
        main.enqueue(i);
    }
    if(main.isFull() == true){
        cout << "passed full test case\n";
    }
    else{
        cout << "failed full test case\n";
    }
}

void testEnqueue_ENC1(void){

    queue main;
    main.enqueue(0);
    if(main.size() == 1 && main.peek() == 0){
        cout << "Enqueue passed first test case\n";
    }
    else{
        cout << "Enqueue failed first test case\n";
    }
    
    
}
void testEnqueueFull_ENC2(void){

    queue main;
    for(int i = 0;i<10;i+=1){
        main.enqueue(i);
    }
    int cursize = main.size();
    main.enqueue(1);
    if(cursize == main.size()){
        cout << "Enqueue passed second test case!";
    }
    else{
        cout << "Enqueue failed second test case!";
    } 
}


void testDequeue_DQC1(void){

    queue main;
    main.enqueue(0);
    main.enqueue(1);
    main.enqueue(2);
    main.dequeue();
    if(main.size() == 2 && main.peek() == 1){
        cout << "Dequeue passed first test case\n";
    }
    else{
        cout << "Dequeue failed first test case\n";
    }     
}


void testDequeueEmpty_DQC2(void){

    queue main;
    main.dequeue();
    if(main.size()==0){
        cout << "Dequeue passed second test case\n";
    }else{
        cout << "Dequeue failed second test case\n";
    }
    
    
}
void testPeek_PQC1(void){

    queue main;
    main.enqueue(999);
    if(main.peek() == 999){
        cout << "Peek passed first test case\n";
    }
    else{
        cout << "Peek failed first test case\n";
    }  
}


void testPeekEmpty_PQC2(void){

    queue main;
    if(main.peek() == numeric_limits<int>::min()){
        cout << "Peek passed second test case\n";
    }
    else{
        cout << "Peek failed second test case\n";
    }    
}
