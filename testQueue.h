/* Test ID: Queue size check - QSC
Unit: queue::size()
Description: Verify that queue::size() correctly returns the number of elements in the queue.  
Test Steps:  
  1. Construct an empty queue object.  
  2. Verify that queue::size() returns 0.  
  3. Enqueue one element into the queue.  
  4. Verify that queue::size() returns 1.  
  5. Enqueue another element into the queue.  
  6. Verify that queue::size() returns 2.  
  7. Dequeue one element from the queue.  
  8. Verify that queue::size() returns 1.  
Test Data:  
  - Initial size = 0  
  - After enqueue operations: size = 1, size = 2  
  - After dequeue operation: size = 1  
Precondition: The queue object is empty. 
Postcondition: The queue object contains the correct number of elements as verified at each step. 
Expected Result: queue::size() returns the correct size of the queue at each step: 0 -> 1 -> 2 -> 1. 
Actual Result: queue::size() returns the correct size of the queue at each step: 0 -> 1 -> 2 -> 1.
Status: passed
*/
void testSize_QSC(void);


/* Test ID: Empty queue check - EQC
Unit: queue::isEmpty()
Description: test to determine if 
queue::isEmpty() returns 1 if a queue object is empty
Test steps:
  1. Construct an empty queue object
  2. Call queue::isEmpty()
  3. Verify that the return value by queue::isEmpty() equals 1
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is still empty
Expected result: queue is empty; 1 is returned by queue::isEmpty()
Actual result: queue is empty; 1 is returned by queue::isEmpty()
Status: passed
*/
void testEmpty_EQC(void);


/*Test ID: Full queue check - FQC
Unit: queue::testFull()
Description: test to determine if queue::isFull() returns 1 if a queue object is full
Test steps:
  1. Construct an empty queue object
  2. Call queue::enqueue() 10 times (recall its defined capacity SIZE = 10 in queue.h)
  3. Call queue::isFull()
  4. Verify that the return value of queue::isFull() equals 1
Test data: [0, 1, 2, ..., 9]  
Precondition: queue object is empty (size = 0)
Postcondition: queue object is full (size = SIZE)
Expected result: queue is full; 1 is returned by queue::isFull()
Actual result: queue is full; 1 is returned by queue::isFull()
Status: passed
*/
void testFull_FQC(void);


/*Test ID: Enqueue check - ENC1
Unit: queue::enqueue()
Description: test to determine if queue::enqueue() adds an item to the queue
Test steps:
  1. Construct an empty queue object
  2. Call queue::enqueue(10) to add an item to the queue.  
  3. Call queue::size() to verify if queue size increases by 1 (to 1)
  4. Call queue::peek() to verify if it returns the front element (10).  
  5. Call queue::enqueue(20) to add another item to the queue.  
  6. Call queue::size() to verify if queue size increases by 1 (to 2)  
  7. Call queue::peek() to verify if it returns the front element (10).  
Test data: enqueue values 10 (step 2) and 20 (step 5)
Precondition: queue object is empty
Postcondition: queue object contains the enqueued elements in FIFO order (10, 20)
Expected result: 
  1. queue::enqueue() successfully adds 10 and 20 to the queue.  
  2. queue::size() correctly reflects the number of items in the queue.  
  3. queue::peek() correctly returns the front element.  
Actual result: 
  1. queue::enqueue() adds 10 and 20 into the queue; 
  2. queue::size() returns 0 (initial), 1 (after adding 10) and 2 (after adding 20);
  3. queue:peek() returns 10 (after adding 10) and 10 (after adding 20)
Status: passed
*/
void testEnqueue_ENC1(void);


/*Test ID: Enqueue check (full queue) - ENC2
Unit: queue::enqueue()
Description: test to determine if queue::enqueue() does not add any item to a full queue
Test steps:
  1. Construct an empty queue object
  2. Call queue::enqueue() 10 times (recall its defined capacity SIZE = 10 in queue.h)
  3. Call queue::size() to verify if queue size is 10
  4. Call queue::enqueue() once
  5. Call queue::size()
  6. Verify that the return value by queue::size() equals 10 (both step 3 and 5)
Test data: 
  1. [0, 1, 2, ..., 9] for step 2
  2. 1 for step 4
Precondition: queue object is empty
Postcondition: queue object has 10 objects
Expected result: queue in step 5 has same size as step 3
Actual result: queue in step 5 has same size as step 3
Status: passed
*/
void testEnqueueFull_ENC2(void);


/*Test ID: Dequeue queue check - DQC1
Unit: queue::dequeue()
Description: test to determine if queue::dequeue() removes an item from the queue and updates object variables
Test steps:
  1. Construct an empty queue object
  2. Call queue::enqueue() 3 times ([0, 1, 2])
  3. Call queue::dequeue() 
  4. Call queue::size()
  5. Call queue::peek()
  6. Verify that the return value by queue::size() equals 2 (step 4) and the return value by queue::peek() equals 1 (step 5)
Test data: [0, 1, 2] for step 2
Precondition: queue object is empty
Postcondition: queue object has 2 objects
Expected result: 
  1. queue::size() returns 2 in step 4
  2. queue::peek() returns 1 in step 5
Actual result: 
  1. queue::size() returns 2 in step 4
  2. queue::peek() returns 1 in step 5
Status: passed
*/
void testDequeue_DQC1(void);


/*Test ID: Dequeue queue check (empty queue) - DQC2
Unit: queue::dequeue()
Description: test to determine if queue::dequeue() does not do anything if called on empty queue
Test steps:
  1. Construct an empty queue object
  2. Call queue::dequeue()
  3. Call queue::size()
  4. Verify that the return value by queue::size() equals 0
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is empty
Expected result: queue has size of 0;
Actual result: queue has size of 0;
Status: passed
*/
void testDequeueEmpty_DQC2(void);


/*Test ID: peek queue check - PQC1
Unit: queue::peek()
Description: test to determine if queue::peek() returns the value of the first object in the queue
Test steps:
  1. Construct an empty queue object
  2. Call queue::enqueue() with the values [0, 1, 2]
  3. Call queue::peek()
  4. Verify that the return value by queue::peek() equals 0
Test data: [0, 1, 2]
Precondition: queue object is empty
Postcondition: queue object has 3 objects, with 0 at the front
Expected result: queue::peek() returns 0;
Actual result: queue::peek() returns 0;
Status: passed
*/
void testPeek_PQC1(void);


/*Test ID: peek queue check (empty queue) - PQC2
Unit: queue::peek()
Description: test to determine if queue::peek() returns minimum int on empty queue
Test steps:
  1. Construct an empty queue object
  2. Call queue::peek()
  3. Verify that the return value by queue::peek() equals numeric_limits<int>::min()
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is empty
Expected result: queue::peek() returns numeric_limits<int>::min();
Actual result: queue::peek() returns numeric_limits<int>::min();
Status: passed
*/
void testPeekEmpty_PQC2(void);
