// C++ Program for Implementation of linked list
// Reference: https://www.geeksforgeeks.org/cpp-linked-list/
// Modified by Yan Yan

#include <iostream>
#include <random>
#include <tuple>
using namespace std;


// Template class: the node in the linked list
template <typename T1, typename T2>
class Node {
public:
    T1 key;             // the first field, denoted by key
    T2 value;           // the second field, denoted by value
    Node<T1, T2>* next; // the pointer to the next node (will be used in the singly linked list)

    // Constructor to initialize the node with two data inputs
    Node(T1 d1, T2 d2) : key(d1), value(d2), next(NULL) {} // either next(NULL), next(0) or next(nullptr) is OK for initialization

    // Function to display the data in the node
    void display() const {
        cout << "Field1: " << key << ", Field2: " << value << endl;
    }
};

// Define the linked list class
template <typename T1, typename T2>
class LinkedList {
private:
     // Pointer to the first (head) node in the list
    Node<T1, T2>* head;

public:
    // Constructor initializes head to 0/NULL/nullptr
    LinkedList() : head(NULL) {}

    // insert a new node at the beginning of the list (the new node will be the first element)
    void insertAtBeginning(T1 d1, T2 d2) {
        Node<T1, T2>* newNode = new Node<T1, T2>(d1, d2);
        newNode->next = head;      
        head = newNode;            
    }

    // insert a new node at the end of the list (the new node will be the last element)
    void insertAtEnd(T1 d1, T2 d2) {
        Node<T1, T2>* newNode = new Node<T1, T2>(d1, d2); 
        newNode->next = NULL;

        // If the list is empty, update the head to the new node
        if (head == NULL) {
            head = newNode;
            return;
        }
        else {
            // Traverse to the last node
            Node<T1, T2>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }

            // Update the last node's next to the new node
            temp->next = newNode;
        }
    }

    // insert a new node at a specific position in the list (the new node will be at that position); position=1 means the first one
    void insertAtPosition(T1 d1, T2 d2, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(d1, d2);
            return;
        }

        Node<T1, T2>* newNode = new Node<T1, T2>(d1, d2); 

        // Traverse to the node before the desired position
        Node<T1, T2>* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        // If the position is out of range, print an error message
        if (!temp) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }

        // Insert the new node at the desired position
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to Delete the first node of the list
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node<T1, T2>* temp = head; 
        head = head->next; 
        delete temp;      
    }

    // Function to Delete the last node of the list
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        if (!head->next) {
            delete head;   
            head = NULL;   
            return;
        }

        // Traverse to the second-to-last node
        Node<T1,T2>* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        
        //  Delete the last node
        delete temp->next; 
        // Set the second-to-last node's next to NULL
        temp->next = NULL; 
    }

    // Function to Delete a node at a specific position in the list
    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node<T1, T2>* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range." << endl;
            return;
        }
        // Save the node to be deleted
        Node<T1, T2>* nodeToDelete = temp->next; 
        // Update the next pointer
        temp->next = temp->next->next;   
         // Delete the node
        delete nodeToDelete;            
    }

    // find and return the node according to a query key (a NULL if not found)
    Node<T1, T2>* findNode(T1 keyToFind) {
        Node<T1, T2>* temp = head;
        while(temp != NULL)
        {
            if (temp->key == keyToFind)
            {
                return temp;
            }
            else 
            {
                temp = temp->next;
            }
        }
        
        if (temp == NULL)
        {
            return temp;
        }
        else{
            throw domain_error("temp pointer is neither a valid pointer to the target node, nor a NULL\n");
            return NULL;
        }
    }

    // delete a node with a given key (Field 1) from the list
    void deleteNode(T1 keyToDelete) {
        Node<T1, T2>* current = head;
        Node<T1, T2>* previous = NULL;
        while(current != NULL)
        {
            if (current->key == keyToDelete)
            {
                break;
            }
            else 
            {
                previous = current;
                current = current->next;
            }
        }

        if (current == NULL) // current traverses to the final element, but does not find
        {
            cout << "No such name can be found! Skipping..." << endl;
            return;
            // break;
        } 

        if (previous == NULL) // this implies that current == head, the first element
        {
            T1 nameToDelete = current->key;
            deleteFromBeginning();
            cout << nameToDelete << ": this node has been successfully deleted." << endl;
            return;
        }
        else // this implies that current != head, not the first element (equivalently, previous != NULL)
        {
            previous->next = previous->next->next;   // equivalent to "previous->next = current->next"
            T1 nameToDelete = current->key;
            delete current;
            cout << nameToDelete << ": this node has been successfully deleted." << endl;
            return;
        }    
    }

    // Function to print the nodes of the linked list
    void printList() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node<T1, T2>* temp = head;
        while (temp) {
            // cout << temp->data << " -> "; 
            temp->display();
            temp = temp->next;
        }
    }

    // Count how many nodes in the linked list
    int getLength() {
        if (!head) {
            cout << "List is empty." << endl;
            return 0;
        }

        Node<T1, T2>* temp = head;
        int length = 0;
        while (temp) {
            temp = temp->next;
            length++;
        }
        return length;
    }

    Node<T1, T2>* getRandom() 
    { 
        // If list is empty 
        if (head == NULL) 
        return head; 
    
        // Use a different seed value so that we don't get same result each time we run this program 
        int length = getLength();
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, length);
        int randomIndex = dis(gen); 
    
        // Iterate from the (k+1)th element to nth element 
        Node<T1, T2>* current = head; 
        for (int i = 0; i < randomIndex; i++) 
        {    
            // Move to next node 
            current = current->next; 
        } 
    
        return current;
    } 


    Node<T1, T2>* getRandomExclude(string excludedKey) 
    { 
        // If list is empty 
        if (head == NULL) 
        return head; 
    
        // Use a different seed value so that we don't get same result each time we run this program 
        int length = getLength();
        int randomIndex;

        while (true)
        {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(1, length);
            randomIndex = dis(gen); 
        
            // Iterate from the (k+1)th element to nth element 
            Node<T1, T2>* current = head; 
            for (int i = 0; i < randomIndex; i++) 
            {    
                // Move to next node 
                current = current->next; 
            } 

            if (current->key != excludedKey)
                return current;
        }
    } 


    tuple<Node<T1, T2>*, Node<T1, T2>*, Node<T1, T2>*> getRandom3() 
    { 
        int length = getLength();
        if (length < 3)
        {
            cout << "Capacity is insufficient: the length of the linked list is less than 3" << endl;
            return make_tuple(head, head, head);
        }
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, length-1);
        
        int randomIndex1 = dis(gen); 
        int randomIndex2;
        int randomIndex3;
        while (true)
        {
            randomIndex2 = dis(gen); 
            if (randomIndex2 != randomIndex1)
            {
                break;
            }
        }
        while (true)
        {
            randomIndex3 = dis(gen); 
            if (randomIndex3 != randomIndex1 && randomIndex3 != randomIndex2)
            {
                break;
            }
        }
        int maxIndex = max(randomIndex1, max(randomIndex2, randomIndex3));
    
        // Iterate from the (k+1)th element to nth element 
        Node<T1, T2>* current = head; 
        Node<T1, T2>* randomNode1 = head; 
        Node<T1, T2>* randomNode2 = head; 
        Node<T1, T2>* randomNode3 = head; 
        for (int i = 0; i < maxIndex; i++) 
        {    
            // set the random node if matched
            if (i == randomIndex1)
            {
                randomNode1 = current;
            }
            if (i == randomIndex2)
            {
                randomNode2 = current;
            }
            if (i == randomIndex3)
            {
                randomNode3 = current;
            }
            // Move to next node 
            current = current->next; 
        } 
    
        return make_tuple(randomNode1, randomNode2, randomNode3);
    } 


    void saveToFile(string filePath)
    {
        fstream myfile;
        myfile.open(filePath, ios::out);
        if (!myfile) {
            cout << "Failed to open file." << endl;
            return;
        }
        Node<T1, T2>* current = this->head;
        while (current != nullptr)
        {
            myfile << current->key << "," << current->value << "\n";
            current = current->next;
        }
        myfile.close(); 
    }


};

