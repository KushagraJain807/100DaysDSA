/*
Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.
*/

#include<bits/stdc++.h>
using namespace std;

struct Queue{
    int cap;
    int front;
    int rear;
    int *data;
};

Queue *createQueue(int cap){
    Queue *myQ = new Queue;
    myQ->cap = cap;
    myQ->front = myQ->rear = -1;
    myQ->data = (int*)malloc(cap * sizeof(int));
    return myQ;
}

void EnQ(Queue *myQ, int value){
    if((myQ->rear+1) % myQ->cap == myQ->front){
        cout<<"Queue Overflow\n";
        return;
    }
    if(myQ->front == -1){
        myQ->front++;
        myQ->rear++;
    }
    else{
        myQ->rear = (myQ->rear + 1) % myQ->cap; 
    } 
    myQ->data[myQ->rear] = value;
}

int DeQ(Queue *myQ){
    if(myQ->front == -1){
        cout<<"Queue Underflow\n";
        return -1;
    }
    int data = myQ->data[myQ->front];
    if(myQ->front == myQ->rear) myQ->front = myQ->rear = -1;
    else myQ->front = (myQ->front + 1) % myQ->cap;
    return data;
}

void displayQ(Queue *myQ){
    if(myQ->front == -1){
        cout<<"Queue is empty\n";
        return;
    }
    int i = myQ->front;
    while(true){
        cout<<myQ->data[i]<<" ";
        if(i == myQ->rear) break;
        i = (i+1) % myQ->cap;
    }
    cout<<endl;
}

int main(){
    int quantity;
    cin>>quantity;
    Queue * myQueue = createQueue(quantity);
    for(int i = 0; i < quantity; i++){
        int data;
        cin>>data;
        EnQ(myQueue, data);
    }
    int numOfDQ;
    cin>> numOfDQ;
    for(int i = 0; i < numOfDQ; i++){
        DeQ(myQueue);
    }
    displayQ(myQueue);
    return 0;
}