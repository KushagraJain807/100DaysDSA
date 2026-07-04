/*
Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number

Example:
Input:
6

Output:
8

Explanation: Sequence: 0,1,1,2,3,5,8 at positions 0,1,2,3,4,5,6
*/

#include<iostream>
using namespace std;
int fibo(int n){
    if(n < 0){
        return -1;
    }
    else if(n == 0 || n == 1){
        return n;
    }
    else{
        return (fibo(n-1) + fibo(n-2));
    }
}
int main(){
    int pos;
    cout<<"Enter the position: ";
    cin>>pos;
    int fib = fibo(pos);
    cout<<"Fibonacci Number at position "<<pos<<" is "<<fib;
    return 0;
}