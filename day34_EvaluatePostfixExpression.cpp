/*
Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Stack{
    Node *top;
};

Stack * createStack(){
    Stack *stack = new Stack;
    stack->top = nullptr;
    return stack;
}

void push(Stack *stack, int value){
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack){
    if(stack->top == nullptr){
        return -1;
    }
    Node *temp = stack->top;
    int popValue = temp->data;
    stack->top = stack->top->next;
    delete(temp);
    return popValue;
}

int peek(Stack *stack){
    if(stack->top == nullptr){
        return -1;
    }
    return stack->top->data;
}

int evaluatePostFixExpression(Stack *stack, const vector<string>& tokens){
    for(auto it : tokens){
        if(isdigit(it[0]) || (it[0]=='-' && it.length()>1)){
            push(stack, stoi(it));
        }
        else{
            int a = pop(stack);
            int b = pop(stack);
            switch(it[0]){
                case '+':
                    push(stack, b+a);
                    break;
                case '-':
                    push(stack, b-a);
                    break;
                case '*':
                    push(stack, b*a);
                    break;
                case '/':
                    push(stack, b/a);
                    break;
            }
        }
    }
    return peek(stack);
}

int main(){

    vector<string> tokens;
    string token;

    getline(cin, token);

    stringstream ss(token);

    while(ss >> token){
        tokens.push_back(token);
    }

    Stack *stack = createStack();

    cout << evaluatePostFixExpression(stack, tokens);

    return 0;
}