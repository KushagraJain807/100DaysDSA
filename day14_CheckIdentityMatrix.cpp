/*
Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and 
all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix
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
    int ans = 1;
    if(rows != columns){
        ans = 0;
    }
    else{
        for(int i = 0; i < rows && ans; i++){
            for(int j = 0; j < columns; j++){
                if((i == j) &&(matrix[i][j] != 1)){
                    ans = 0;
                    break;
                }
                else if((i != j) && (matrix[i][j] != 0)){
                    ans = 0; 
                    break;
                }
            }
        }
    }
    if(ans==1){
        cout<<"Identity Matrix";
    }
    else{
        cout<<"Not an Identity Matrix";
    }
    return 0;
}