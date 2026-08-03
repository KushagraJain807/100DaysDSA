/*
Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.
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
    Node * newNode = createNode(data);
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

Node * deleteFirstOccurenceOfKey(Node * &head, int key){
    if(head==nullptr){
        return head;
    }
    Node *prev = head;
    Node *curr = head;
    while(curr && curr->data != key){
        prev = curr;
        curr = curr->next;
    }
    if(curr==nullptr){
        return head;
    }
    if(curr==head){
        head = head->next;
        delete(curr);
        return head;
    }
    prev->next = curr->next;
    delete(curr);
    return head;
}

int main(){
    Node * head = nullptr;
    Node * tail = nullptr;
    int elements;
    cout<<"Number of elements in linked list? ";
    cin>>elements;
    cout<<"Start entering the elements of array"<<endl;
    for(int i = 0; i < elements; i++){
        int data;
        cin>>data;
        head = addAtEnd(head, tail, data);
    }
    int key;
    cout<<"Enter key you want to delete: ";
    cin>>key;
    head = deleteFirstOccurenceOfKey(head, key);
    cout<<"Linked List after deletion of your key is\n";
    printLL(head);
    return 0;
}