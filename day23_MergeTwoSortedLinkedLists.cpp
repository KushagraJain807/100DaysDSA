/*
Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
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

Node * mergeLL(Node *head, Node *head2){
    Node *temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = head2;
    return head;
}

int main(){
    Node * head = nullptr;
    Node * tail = nullptr;
    Node * head2 = nullptr;
    Node * tail2 = nullptr;
    int elements;
    int elements2;
    cout<<"Number of elements in linked list? ";
    cin>>elements;
    cout<<"Start entering the elements of array"<<endl;
    for(int i = 0; i < elements; i++){
        int data;
        cin>>data;
        head = addAtEnd(head, tail, data);
    }
    cout<<"Number of elements in linked list? ";
    cin>>elements2;
    cout<<"Start entering the elements of array"<<endl;
    for(int i = 0; i < elements2; i++){
        int data;
        cin>>data;
        head2 = addAtEnd(head2, tail2, data);
    }
    head = mergeLL(head, head2);
    printLL(head);
    return 0;
}