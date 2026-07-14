/*
Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3
*/

//BruteForce Approach Solution:
/*
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
    int value;
    cout<<"Enter the value by which you want to right shift the arrray: ";
    cin>>value;
    value = value % quantity;
    for(int i = 0; i < value; i++){
        int temp = array[quantity-1];
        for(int j = quantity-1; j > 0; j--){
            array[j] = array[j-1];
        }
        array[0] = temp;
    }
    cout<<"So your final rotated array is: ";
    for(int i = 0; i < quantity; i++){
        cout<<array[i]<<" ";
    }
    return 0;
}
*/

//Optimal Approach Solution
#include<bits/stdc++.h>
using namespace std;
void reversePart(int start, int end, int array[]){
    while(start<end){
        int a = array[start];
        array[start] = array[end];
        array[end] = a;
        start++;
        end--;
    }
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
    int value;
    cout<<"Enter the value by which you want to right shift the arrray: ";
    cin>>value;
    value = value % quantity;
    reversePart(0, quantity-value-1, array);
    reversePart(quantity-value, quantity-1, array);
    reversePart(0, quantity-1, array);
    cout<<"So your final rotated array is: ";
    for(int i = 0; i < quantity; i++){
        cout<<array[i]<<" ";
    }
    return 0;
}