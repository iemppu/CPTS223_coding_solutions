#include "my_queue.h"

// Constructor to initialize queue
MyQueue::MyQueue(int size)
{
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

// Destructor to free memory allocated to the queue
MyQueue::~MyQueue()
{
	delete arr; // you are not required to test this function;
	            // however, are there issues with it?
}

// Utility function to remove front element from the queue
void MyQueue::dequeue()
{
	// check for queue underflow
	if (isEmpty())
	{
		std::cout << "UnderFlow\nProgram Terminated\n";
		return;
	}

	std::cout << "Removing " << arr[front] << '\n';

	front = (front + 1) % capacity;

	count--;
}

// Utility function to add an item to the queue
void MyQueue::enqueue(int item)
{
	// check for queue overflow
	if (isFull())
	{
		std::cout << "OverFlow\nProgram Terminated\n";
		return;
	}

	std::cout << "Inserting " << item << '\n';

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

// Utility function to return front element in the queue
int MyQueue::peek()
{
	if (isEmpty())
	{
		std::cout << "UnderFlow\nProgram Terminated\n";
		return std::numeric_limits<int>::min();
	}
	return arr[front];
}

// Utility function to return the size of the queue
int MyQueue::size()
{
	return count;
}

// Utility function to check if the queue is empty or not
bool MyQueue::isEmpty()
{
	return (size() == 0);
}

// Utility function to check if the queue is full or not
bool MyQueue::isFull()
{
	return (size() == capacity);
}
