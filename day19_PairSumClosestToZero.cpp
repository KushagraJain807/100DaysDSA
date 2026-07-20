/*
Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.
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
    for(int i = 0; i < quantity; i++){
        for(int j = 0; j < quantity; j++){
            
        }
    }
    // Brute Force
    /*
    int minDif = INT_MAX;
    int best1, best2;
    for(int i = 0; i < quantity-1; i++){
        for(int j = i+1; j < quantity; j++){
            int sum = array[i] + array[j];
            if(abs(sum) < minDif){
                best1 = array[i];
                best2 = array[j];
                minDif = abs(sum);
            }
        }
    }
    cout<<best1<<" "<<best2;
    return 0;
    */
    
    //Opimal Approach
    int minDif = INT_MAX;
    int best1, best2;
    int left = 0, right = quantity-1;
    sort(array, array+quantity);
    while(left<right){
        int sum = array[left] + array[right];
        if(abs(sum) < minDif){
            best1 = array[left];
            best2 = array[right];
            minDif = abs(sum);
        }
        if(sum < 0){
            left++;
        }
        else if(sum == 0){
            break;
        }
        else{
            right--;
        }
    }
    cout<<best1<<" "<<best2;
    return 0;
}