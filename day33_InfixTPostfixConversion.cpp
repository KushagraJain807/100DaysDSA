/*
Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity
*/

#include<bits/stdc++.h>
using namespace std;

int precedence(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return -1;
}

string infixToPostfix(string s){
    stack<char> st;
    string ans = "";
    for(int i = 0; i < s.length(); i++){
        if(isalnum(s[i])){
            ans += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precedence(st.top()) > precedence(s[i])){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main(){
    string s = "A+B*C";
    string ans = infixToPostfix(s);
    for(int i = 0; i < ans.length(); i++){
        cout<<ans[i];
    }
    return 0;
}