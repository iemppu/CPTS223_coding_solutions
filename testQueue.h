/*Test ID: Check size of queue -EQCUnit: queue::size ()
Description: test to determine if 
queue::size () returns the number of objects in the queue
Test steps:
1.Construct an empty queue object
2.Invoke queue::size()
3.Conditionally evaluate whether the value returned by queue::size() is equal to 0
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object has size of 10
Expected result: queue has 10 objects;1 is returned
Actual result: queue doesnt have 10 objects; 0 is returned
Status: failed*/
void testSize(void);
/*Test ID: Empty queue check -EQCUnit: queue::isEmpty ()
Description: test to determine if 
queue::isEmpty () returns 1 if a queue object is empty
Test steps:
1.Construct an empty queue object
2.Invoke queue::isEmpty ()
3.Conditionally evaluate the valued returned by queue::isEmpty ()
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is still empty
Expected result: queue is empty;1 is returned
Actual result: queue is not empty; 0 is returned
Status: failed*/
void testEmpty(void);
/*Test ID: Full queue check -EQCUnit: queue::testFull ()
Description: test to determine if 
queue::isFULL () returns 1 if a queue object is full
Test steps:
1.Construct an empty queue object
2.Invoke queue::enqueue 10 times
3.Invoke queue::isFull ()
3.Conditionally evaluate the valued returned by queue::isFull ()
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is full
Expected result: queue is full;1 is returned
Actual result: queue is full;1 is returned
Status: passed*/
void testFULL(void);
/*Test ID: Enqueue queue check -EQCUnit: queue::enqueue ()
Description: test to determine if 
queue::enqueue () adds an item to the queue and returns nothing
1.Construct an empty queue object
2.Invoke queue::enqueue 1 times
3.Invoke queue::size()
4.Invoke queue::peek()
5.Conditionally evaluate the valued returned by queue::size() == 1 and whether queue::peek() == value of last item added
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object has one object
Expected result: queue has size of 1 and value of last item added is same;1 is returned
Actual result: queue does not have size of 1 or value of last item is not the same;0 is returned
Status: failed*/
void testEnqueue(void);
/*Test ID: Enqueue queue check -EQCUnit: queue::enqueue ()
Description: test to determine if 
queue::enqueue () doesnt add an item to a full queue
1.Construct an empty queue object
2.Invoke queue::enqueue 10 times
3.Invoke queue::size()
4.Invoke queue::enqueue once
5.Invoke queue::size()
5.Conditionally evaluate the valued returned by queue::size() == queue::size() when called earlier with 10 items
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object has 10 objects
Expected result: queue has same size as before queue::enqueue();1 is returned
Actual result: queue has same size as before queue::enqueue();1 is returned
Status: passed*/
void testEnqueueFull(void);
/*Test ID: Dequeue queue check -EQCUnit: queue::dequeue ()
Description: test to determine if 
queue::dequeue() removes an item from the queue and updates object variables and returns nothing
Test steps:
1.Construct an empty queue object
2.Invoke queue::enqueue 3 times
3.Invoke queue::dequeue 
4.Invoke queue::size ()
5.Invoke queue::peek()
6.Conditionally evaluate the valued returned by queue::size ()== 2 and queue::peek == 1
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object has 3 objects
Expected result: queue has size of 3;1 is returned
Actual result: queue does not have size of 3;0 is returned
Status: failed*/
void testDequeue(void);
/*Test ID: Dequeue queue check -EQCUnit: queue::dequeue ()
Description: test to determine if 
queue::dequeue() doesnt do anything if called on empty queue
Test steps:
1.Construct an empty queue object
2.Invoke queue::dequeue 
3.Invoke queue::size ()
4.Conditionally evaluate the valued returned by queue::size ()== 0
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is empty
Expected result: queue has size of 0;1 is returned
Actual result: queue has size of 0;1 is returned
Status: passed*/
void testDequeueEmpty(void);
/*Test ID: peek queue check -EQCUnit: queue::peek ()
Description: test to determine if 
queue::peek() returns the value of the first object in the queue
Test steps:
1.Construct an empty queue object
2.Invoke queue::enqueue with the value 999
3.Invoke queue::peek()
4.Conditionally evaluate the valued returned by queue::peek ()== 999
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object has 1 object with the value of 999
Expected result: queue::peek() returns 999 ;1 is returned
Actual result: queueu::peek() does nnot return 999;0 is returned
Status: failed*/
void testPeek(void);
/*Test ID: peek queue check -EQCUnit: queue::peek ()
Description: test to determine if 
queue::peek() returns returns minimum int on empty queue
Test steps:
1.Construct an empty queue object
2.Invoke queue::peek()
3.Conditionally evaluate the valued returned by queue::peek ()== numeric_limits<int>::min()
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is empty
Expected result: queue::peek() returns numeric_limits<int>::min() ;1 is returned
Actual result: queueu::peek() does not return numeric_limits<int>::min();0 is returned
Status: failed*/
void testPeekEmpty(void);