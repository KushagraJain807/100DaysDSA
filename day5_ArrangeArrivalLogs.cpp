/*
Problem: A system receives two separate logs of user arrival times from two different servers. 
Each log is already sorted in ascending order. 
Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until 
all entries are processed
*/

#include<iostream>
using namespace std;
int main(){
    int size1, size2;
    cout<<"Enter number of entries in server log 1? ";
    cin>>size1;
    int arr1[size1];
    cout<<"Enter log entries of server 1:"<<endl;
    for(int i = 0; i < size1; i++){
        cin>>arr1[i];
    }
    cout<<"Enter number of entries in server log 2? ";
    cin>>size2;
    int arr2[size2];
    cout<<"Enter log entries of server 2:"<<endl;
    for(int i = 0; i < size2; i++){
        cin>>arr2[i];
    }
    int size3 = size1+size2;
    int arr[size3];
    int i = 0, j = 0, k = 0;
    while((i < size1) && (j < size2)){
        if(arr1[i] < arr2[j]){
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else{
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    if(i != size1){
        while(i < size1){
            arr[k] = arr1[i];
            i++;
            k++;
        }
    }
    if(j != size2){
        while(j < size2){
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    cout<<"So your final chronologicl log entries array is: ";
    for(int b = 0; b < size3; b++){
        cout<<arr[b]<<" ";
    }

    return 0;
}