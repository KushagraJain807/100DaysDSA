/*
Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50
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

Node * addAtEnd(Node * &head, Node * &tail, int data){
    Node *newNode = createNode(data);
    if(head==nullptr){
        head = tail = newNode;
        return head;
    }
    tail->next = newNode;
    tail = newNode;
    return head;
}

void printLL(Node *head){
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node *head = nullptr;
    Node *tail = nullptr;
    int elements;
    cout<<"Number of elements in linked list? ";
    cin>>elements;
    cout<<"Start entering the elements of array"<<endl;
    for(int i = 0; i < elements; i++){
        int data;
        cin>>data;
        head = addAtEnd(head, tail, data);
    }
    printLL(head);
    return 0;
}