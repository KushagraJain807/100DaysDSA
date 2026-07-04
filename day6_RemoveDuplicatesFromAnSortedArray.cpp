/*
Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
*/

#include<iostream>
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
    int b = 0;
    for(int i = 1; i < quantity; i++){
        if(array[i] != array[b]){
            b++;
            array[b] = array[i];
        }
    }
    cout<<"So your final array without duplicates is: ";
    for(int i = 0; i < (b+1); i++){
        cout<<array[i]<<" ";
    }
    return 0;
}