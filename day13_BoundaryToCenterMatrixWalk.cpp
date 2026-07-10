/*
Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

Test Cases:

Test Case 1:
Input:
2 3
1 2 3
4 5 6
Output:
1 2 3 6 5 4

Test Case 2:
Input:
3 1
7
8
9
Output:
7 8 9
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
    int top = 0; 
    int bottom = rows-1;
    int left = 0; 
    int right = columns-1;
    while(top<=bottom && left<=right){
        for(int i = left; i <= right; i++){
            cout<<matrix[top][i]<<" ";
        }
        top++;
        for(int j = top; j <= bottom; j++){
            cout<<matrix[j][right]<<" ";
        }
        right--;
        if(top<=bottom){
            for(int k = right; k >= left; k--){
                cout<<matrix[bottom][k]<<" ";
            }
            bottom--;   
        }
        if(left<=right){
            for(int l = bottom; l >= top; l--){
                cout<<matrix[l][left]<<" ";
            }
            left++;
        }
    }

    return 0;
}