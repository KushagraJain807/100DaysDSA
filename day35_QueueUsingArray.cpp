/*
Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Queue{
    Node *front;
    Node *rear;
    int cap;
    int currentCount;
};

Queue * createQueue(int cap){
    Queue *myQueue = new Queue;
    myQueue->cap = cap;
    myQueue->currentCount = 0;
    myQueue->front = nullptr;
    myQueue->rear = nullptr;
    return myQueue;
}

void ENQ(Queue *myQueue, int value){
    if(myQueue->currentCount == myQueue->cap){
        return;
    }
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if(myQueue->front == nullptr){
        myQueue->front = myQueue->rear = newNode;
    }
    else{
        myQueue->rear->next = newNode;
        myQueue->rear = newNode;
    }
    myQueue->currentCount++;
}

void displayQueue(Queue *myQueue){
    Node *temp = myQueue->front;
    if(!temp) return;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    int quantity;
    cin>>quantity;
    Queue * myQueue = createQueue(quantity);
    for(int i = 0; i < quantity; i++){
        int data;
        cin>>data;
        ENQ(myQueue, data);
    }
    displayQueue(myQueue);

    return 0;
}



