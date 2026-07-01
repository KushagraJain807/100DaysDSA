/*
Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left
*/

#include<iostream>
using namespace std;
int main(){
    int quantity;
    cout<<"Number of elements in array? ";
    cin>>quantity;
    int array[quantity];
    cout<<"Start entering the elements of array"<<endl;
    for(int i = 0; i < quantity; i++){
        cin>>array[i];
    }
    int index;
    cout<<"1-based Index at which you want to delete the element? ";
    cin>>index;
    for (int i = index - 1; i < quantity - 1; i++) {
        array[i] = array[i + 1];
    }
    cout<<"So your final output array is: ";
    for(int i = 0; i < quantity-1; i++){
        cout<<array[i]<<" ";
    }
    return 0;
}
