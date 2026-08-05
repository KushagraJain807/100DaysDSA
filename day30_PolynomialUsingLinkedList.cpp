/*
Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.
*/

#include<bits/stdc++.h>
using namespace std;

struct Poly{
    float coeff;
    int power;
    Poly *next;
};

Poly * createTerm(float coeff, int pow){
    Poly * newTerm = new Poly;
    newTerm->coeff = coeff;
    newTerm->power = pow;
    newTerm->next = nullptr;
    return newTerm;
}

void addTerm(Poly * &head, Poly * &tail, float coeff, int pow){
    Poly * newTerm = createTerm(coeff, pow);
    if(head==nullptr){
        head = tail = newTerm;
        return;
    }
    tail->next = newTerm;
    tail = newTerm;
}

void printPoly(Poly *head){
    Poly *temp = head;
    while(temp){
        cout << temp->coeff;
        if(temp->power > 1){
            cout << "x^" << temp->power;
        }
        else if(temp->power == 1){
            cout << "x";
        }
        if(temp->next){
            cout << " + ";
        }
        temp = temp->next;
    }
}

int main(){
    Poly *head = nullptr;
    Poly *tail = nullptr;
    cout<<"Enter number of terms you want to add in your polynomial: ";
    int terms;
    cin>>terms;
    for(int i = 0; i < terms; i++){
        float coeff;
        int pow;
        cin>>coeff;
        cin>>pow;
        addTerm(head, tail, coeff, pow);
    }
    printPoly(head);
    return 0;
}