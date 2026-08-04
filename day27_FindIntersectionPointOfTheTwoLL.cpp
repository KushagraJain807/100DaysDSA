/*
Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
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

void addAtEnd(Node * &head, Node * &tail, int data){
    Node * newNode = createNode(data);
    if(head==nullptr){
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

Node * findIntersection(Node *head, Node *head2){
    if(head==nullptr) return nullptr;
    if(head2==nullptr) return nullptr;
    Node *t1 = head;
    Node *t2 = head2;
    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;
        if(t1==t2) return t1;
        if(t1==nullptr) t1 = head2;
        if(t2==nullptr) t2 = head;
    }
    return t1;

}

int main(){
    Node * head = nullptr;
    Node * tail = nullptr;
    int elements;
    cout<<"Number of elements in linked list? ";
    cin>>elements;
    cout<<"Start entering the elements of LL 2"<<endl;
    for(int i = 0; i < elements; i++){
        int data;
        cin>>data;
        addAtEnd(head, tail, data);
    }

    Node * head2 = nullptr;
    Node * tail2 = nullptr;
    int elements2;
    cout<<"Number of elements in linked list 2? ";
    cin>>elements2;
    cout<<"Start entering the elements of LL 2"<<endl;
    for(int i = 0; i < elements2; i++){
        int data;
        cin>>data;
        addAtEnd(head2, tail2, data);
    }
    
    Node *intersectionPoint = findIntersection(head, head2);
    if(intersectionPoint){
        cout<<intersectionPoint->data;
    }
    else{
        cout<<"No Intersection";
    }

    return 0;
}