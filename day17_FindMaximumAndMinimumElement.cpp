/*
Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements

Example:
Input:
6
3 5 1 9 2 8

Output:
Max: 9
Min: 1
*/
 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int quantity;
    cout<<"Number of elements in array? ";
    cin>>quantity;
    int array[quantity];
    cout<<"Start entering the elements of array"<<endl;;
    for(int i = 0; i < quantity; i++){
        cin>>array[i];
    }
    int min = array[0];
    int max = array[0];
    for(int i = 1; i < quantity; i++){
        if(array[i] < min){
            min = array[i];
        }
        if(array[i] > max){
            max = array[i];
        }
    }
    cout<<"Max: "<<max<<"\n"<<"Min: "<<min;
    return 0;
}