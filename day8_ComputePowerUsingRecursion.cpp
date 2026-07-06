/*
Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32
*/

#include<iostream>
using namespace std;
float power(float base, int pow){
    if(pow == 0){
        return 1;
    }
    return base*power(base, pow-1);
}
int main(){
    float base;
    int pow;
    float ans;
    cout<<"Enter base and power: ";
    cin>>base;
    cin>>pow;
    ans = power(base, pow);
    cout<<base<<" race to power "<<pow<<" is "<<ans;
    return 0;
}