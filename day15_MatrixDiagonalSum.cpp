/*
Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15

Explanation:
1 + 5 + 9 = 15
*/

#include<iostream>
using namespace std;
int main(){
    cout<<"Enter number of rows and columns for matrix: ";
    int rows, columns;
    cin>>rows;
    cin>>columns;
    int matrix[rows][columns];
    cout<<"Enter elements of matrix:"<<endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cin>>matrix[i][j];
        }
    }
    int sum = 0;
    int limit = min(rows, columns);
    for(int i = 0; i < limit; i++){
        sum += matrix[i][i];
    } 
    cout<<"The sum of its primary diagonal elements is "<<sum;
    return 0;
}