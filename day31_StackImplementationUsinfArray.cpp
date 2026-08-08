/*
Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10
*/

#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int top;
    int cap;
    int *data;
};

Stack * createStack(int size){
    Stack *stack = new Stack;
    stack->cap = size;
    stack->top = -1;
    stack->data = (int *)malloc(size*sizeof(int));
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
        cout<<stack->data[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int n;
    cin >> n;

    Stack *stack = createStack(n);

    for(int i = 0; i < n; i++){
        int operation;
        cin >> operation;

        if(operation == 1){
            int value;
            cin >> value;
            push(stack, value);
        }
        else if(operation == 2){
            int value = pop(stack);

            if(value != -1){
                cout << value << endl;
            }
        }
        else if(operation == 3){
            displayStack(stack);
        }
    }

    return 0;
}