/*
Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int quantity;
    cout<<"Number of elements in array? ";
    cin>>quantity;
    int array[quantity];
    map<int, int> mp;
    cout<<"Start entering the elements of array"<<endl;;
    for(int i = 0; i < quantity; i++){
        cin>>array[i];
        mp[array[i]]++;
    }  
    for(auto it : mp){
        cout<<it.first<<" : "<<it.second<<"\n";
    }
    return 0;
}