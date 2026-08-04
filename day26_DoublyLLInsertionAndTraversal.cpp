/*
Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.
*/

#include<bits/stdc++.h>
using namespace std;

struct DLLNode{
    int data;
    DLLNode *next;
    DLLNode *prev;
};

DLLNode * createDLLNode(int data){
    DLLNode *newNode = new DLLNode;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

//In Single LL addAtEnd function i returned head even after using pass by reference which is unneccesary so we can use this function without returning the head.
void * insertionAtEnd(DLLNode * &head, DLLNode * &tail, int data){
    DLLNode *newNode = createDLLNode(data);
    if(head==nullptr){
        head = tail = newNode;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void printLL(DLLNode *head){
    DLLNode *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    DLLNode *head = nullptr;
    DLLNode *tail = nullptr;
    int elements;
    cout<<"Number of elements in linked list? ";
    cin>>elements;
    cout<<"Start entering the elements of array"<<endl;
    for(int i = 0; i < elements; i++){
        int data;
        cin>>data;
        insertionAtEnd(head, tail, data);
    }
    printLL(head);
    return 0;
}