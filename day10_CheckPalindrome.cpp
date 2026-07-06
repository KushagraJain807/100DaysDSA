/*
Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards
*/

#include<iostream>
using namespace std;
bool checkPal(string s){
    int i = 0, j = s.size()-1;
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main(){
    string s;
    cout<<"Enter your string: ";
    cin>>s;
    if(checkPal(s)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}