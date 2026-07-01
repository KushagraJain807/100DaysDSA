/*
Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays
*/

#include<iostream>
using namespace std;
void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
int main(){
    int quantity;
    cout<<"Number of elements in array? ";
    cin>>quantity;
    int array[quantity];
    cout<<"Start entering the elements of array"<<endl;;
    for(int i = 0; i < quantity; i++){
        cin>>array[i];
    }
    int start = 0; 
    int end = quantity-1;
    while(start < end){
        swap(array[start], array[end]);
        start++;
        end--;
    }
    cout<<"So your final reversed array is: ";
    for(int i = 0; i < quantity; i++){
        cout<<array[i]<<" ";
    }
    return 0;
}
