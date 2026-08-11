/*
Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10
*/

#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int *data;
    int cap;
    int top;
};

Stack *createStack(int size){
    Stack *stack = new Stack;
    stack->top = -1;
    stack->cap = size;
    stack->data = (int *)malloc(size*(sizeof(int)));
    return stack;
}

void push(Stack *stack, int value){
    if(stack->top == stack->cap - 1){
        cout<<"Stack Overflow";
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

int pop(Stack *stack){
    if(stack->top == -1){
        cout<<"Stack Underflow";
        return -1;
    }
    int popValue = stack->data[stack->top];
    stack->top--;
    return popValue;
}

void displayStack(Stack *stack){
    if(stack->top == -1){
        cout<<"Stack is empty";
        return;
    }
    for(int i = stack->top; i >= 0; i--){
        cout<<stack->data[i]<<" ";;
    }
    cout<<"\n";
}

int main(){
    int N;
    cin>>N;
    Stack *stack = createStack(N);
    for(int i = 0; i < N; i++){
        int d;
        cin>>d;
        push(stack, d);
    }
    int numOfPops;
    cin>>numOfPops;
    for(int i = 0; i < numOfPops; i ++){
        int popValue = pop(stack);
    }
    displayStack(stack);
    return 0;
}