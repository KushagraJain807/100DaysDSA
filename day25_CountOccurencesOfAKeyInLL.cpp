/*
Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.
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

int countOccurenceOfKey(Node *head, int key){
    int counter = 0;
    Node *temp = head;
    while(temp){
        if(temp->data == key){
            counter++;
        }
        temp = temp->next;
    }
    return counter;
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
    cout<<"Enter key you want to check the occurence of: ";
    cin>>key;
    int count = countOccurenceOfKey(head, key);
    cout<<count;
    return 0;
}