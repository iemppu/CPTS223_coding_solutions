#include "queue.h"
#include "testQueue.h"
#include <limits>
void testSize(void){
    queue main;
    
    if(main.size() == 0){
        cout << "passed size test case\n";
    }
    else{
        cout << "failed size test case\n";
    }
}

void testEmpty(void){
    queue main;
    
    if(main.isEmpty() == true){
        cout << "passed empty test case\n";
    }
    else{
        cout << "failed empty test case\n";
    }
}

void testFULL(void){

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

void testEnqueue(void){

    queue main;
    main.enqueue(0);
    if(main.size() == 1 && main.peek() == 0){
        cout << "Enqueue passed first test case\n";
    }
    else{
        cout << "Enqueue failed first test case\n";
    }
    
    
    
    
    
    
}
void testEnqueueFull(void){

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
void testDequeue(void){

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
void testDequeueEmpty(void){

    queue main;
    main.dequeue();
    if(main.size()==0){
        cout << "Dequeue passed second test case\n";
    }else{
        cout << "Dequeue failed second test case\n";
    }
    
    
}
void testPeek(void){

    queue main;
    main.enqueue(999);
    if(main.peek() == 999){
        cout << "Peek passed first test case\n";
    }
    else{
        cout << "Peek failed first test case\n";
    }
    


    
}
void testPeekEmpty(void){

    queue main;
    if(main.peek() == numeric_limits<int>::min()){
        cout << "Peek passed second test case\n";
    }
    else{
        cout << "Peek failed second test case\n";
    }
    


    
}