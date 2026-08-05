/*
Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node * createNode(int data){
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void addAtEndInCircularLL(Node * &head, Node * &tail, int data){
    Node * newNode = createNode(data);
    if(head==nullptr){
        head = tail = newNode;
        tail->next = head;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    tail->next = head;
}

void printCircularLL(Node *head){
    if(head==nullptr) return;
    Node *temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
}

int main(){
    Node * head = nullptr;
    Node * tail = nullptr;
    int elements;
    cout<<"Number of elements in linked list? ";
    cin>>elements;
    cout<<"Start entering the elements of LL "<<endl;
    for(int i = 0; i < elements; i++){
        int data;
        cin>>data;
        addAtEndInCircularLL(head, tail, data);
    }
printCircularLL(head);
    return 0;
}