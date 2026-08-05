/*
Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *createNode(int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void addAtEndInCircularLL(Node * &head, Node * &tail, int data){
    Node *newNode = createNode(data);
    if(head==nullptr){
        head=tail=newNode;
        tail->next = head;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    tail->next = head;
}

void rotateLLByKPlaces(Node * &head, Node* &tail, int size, int places){
    places = places % size;
    if(places == 0){
        tail->next = nullptr;
        return;
    }
    Node *temp = head;
    for(int i = 0; i < (size-places-1); i++){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = nullptr;
}

void printLL(Node *head){
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
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
    cout<<"Enter places by which you want to shift the linked list: ";
    int places;
    cin>>places;
    rotateLLByKPlaces(head, tail, elements, places);
    printLL(head);
    return 0;
}