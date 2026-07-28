/*
Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: 
[1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. 
Since there are 6 such subarrays, the output is 6.
*/

#include<bits/stdc++.h>
using namespace std;
int CountSubarraysWithSumK(vector<int>& v, long long k){
    int count = 0;
    long long sum = 0;
    unordered_map<long long, int> mp;
    mp[0] = 1;
    for(int i : v){
        sum += i;
        count += mp[sum-k];
        mp[sum]++;
    }
    return count;
}
int main(){
    int quantity;
    cout<<"Number of elements in array? ";
    cin>>quantity;
    vector<int> v(quantity);
    cout<<"Start entering the elements of array"<<endl;
    for(int i = 0; i < quantity; i++){
        cin>>v[i];
    }
    int counter = CountSubarraysWithSumK(v, 0);
    cout<<"Count of subarray with sum 0 is: "<<counter;
    return 0;
}