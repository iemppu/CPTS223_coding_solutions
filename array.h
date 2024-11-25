

#include <iostream>

using namespace std;

template <typename T1, typename T2>
class ArrayNode {
public:
    T1 key;
    T2 value;

    ArrayNode() : key(T1()), value(T2()) {}

    ArrayNode(T1 d1, T2 d2) : key(d1), value(d2) {}
};


template <typename T1, typename T2>
class Array {
    ArrayNode<T1, T2>* data;
    size_t size_;   // number of elements that are occupied
    size_t capacity;  // total size of the array

public:
    // constructor
    Array(size_t cap = 10) : size_(0), capacity(cap) {
        data = new ArrayNode<T1, T2>[capacity];
    }

    // destructor
    ~Array() {
        delete[] data;
    }

    // get the number of elements
    size_t size() const {
        return size_;
    }

    // insert at end of the array
    void insertAtEnd(T1 d1, T2 d2) {
        if (size_ == capacity) // the array is full: need to resize
        {
            resize();
        }
        data[size_++] = ArrayNode<T1, T2>(d1, d2);
    }

    // insert at the beginning
    void insertAtBeginning(T1 d1, T2 d2) {
        if (size_ == capacity) {
            resize();
        }
        for (size_t i = size_; i > 0; --i) {
            data[i] = data[i - 1];
        }
        data[0] = ArrayNode<T1, T2>(d1, d2);
        ++size_;
    }

    // insert at a position
    void insertAtPosition(T1 d1, T2 d2, size_t position) {
        if (position < 1 || position > size_ + 1) {
            cout << "Position out of range." << endl;
            return;
        }

        if (size_ == capacity) {
            resize();
        }

        for (size_t i = size_; i >= position; --i) {
            data[i] = data[i - 1];
        }
        data[position - 1] = ArrayNode<T1, T2>(d1, d2);
        ++size_;
    }

    // delete the first element
    void deleteFromBeginning() {
        if (size_ == 0) {
            cout << "Array is empty." << endl;
            return;
        }

        for (size_t i = 1; i < size_; ++i) {
            data[i - 1] = data[i];
        }
        --size_;
    }

    // delete the last element
    void deleteFromEnd() {
        if (size_ == 0) {
            cout << "Array is empty." << endl;
            return;
        }
        --size_;
    }

    // delete the element at the position
    void deleteFromPosition(size_t position) {
        if (position < 1 || position > size_) {
            cout << "Position out of range." << endl;
            return;
        }

        for (size_t i = position; i < size_; ++i) {
            data[i - 1] = data[i];
        }
        --size_;
    }

    // print the array
    void printArray() {
        if (size_ == 0) {
            cout << "Array is empty." << endl;
            return;
        }

        for (size_t i = 0; i < size_; ++i) {
            cout << "(" << data[i].key << ", " << data[i].value << ") ";
        }
        cout << endl;
    }

    // find a node according to key
    ArrayNode<T1, T2>* findNode(string keyToSearch)
    {
        size_t positionToSearch = size_;
        for (size_t i = 0; i < size_; ++i) {
            if (data[i].key == keyToSearch)
            {
                positionToSearch = i;
                return &data[positionToSearch];
            }
        }
        if (positionToSearch == size_)
        {
            return NULL;
        }
        else
        {
            return &data[positionToSearch];
        }
    }

    void saveToFile(string filePath) {
        fstream myfile;
        myfile.open(filePath, ios::out);

        if (!myfile) {
            cout << "Failed to open file." << endl;
            return;
        }

        // scan all elements
        for (size_t i = 0; i < size_; ++i) {
            myfile << data[i].key << "," << data[i].value << "\n";
        }

        myfile.close();
        cout << "Data saved to file successfully." << endl;
    }

private:
    // resize the capacity of the array
    void resize() {
        capacity *= 2;
        ArrayNode<T1, T2>* newData = new ArrayNode<T1, T2>[capacity];
        for (size_t i = 0; i < size_; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
};

