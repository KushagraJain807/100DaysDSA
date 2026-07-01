/*
Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right
*/

#include<iostream>
using namespace std;
int main(){
    int quantity;
    cout<<"Number of elements in array? ";
    cin>>quantity;
    int array[quantity+1];
    cout<<"Start entering the elements of array"<<endl;;
    for(int i = 0; i < quantity; i++){
        cin>>array[i];
    }
    int index;
    cout<<"1-based Index at which you want to add the element? ";
    cin>>index;
    int element;
    cout<<"Element you want to add in the array? ";
    cin>>element;
    for(int i = quantity; i > index-1; i--){
        array[i] = array[i-1];
    }
    array[index-1] = element;
    cout<<"So your final output array is: ";
    for(int i = 0; i < quantity+1; i++){
        cout<<array[i]<<" ";
    }
    return 0;
}

