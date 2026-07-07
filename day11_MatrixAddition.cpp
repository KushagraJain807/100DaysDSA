/*
Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding 
corresponding elements of the matrices.

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the first matrix
- Next m lines: n integers each representing the elements of the second matrix

Output:
- Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1

Output:
10 10 10
10 10 10
10 10 10

Explanation:
Each element of the result matrix is the sum of the corresponding elements from the two input matrices.

Test Cases:

Test Case 1:
Input:
2 2
1 2
3 4
5 6
7 8
Output:
6 8
10 12

Test Case 2:
Input:
1 3
10 20 30
1 2 3
Output:
11 22 33

Test Case 3:
Input:
3 1
1
2
3
4
5
6
Output:
5
7
9
*/

#include<iostream>
using namespace std;
int main(){
    cout<<"Enter number of rows and columns for matrices: ";
    int rows, columns;
    cin>>rows;
    cin>>columns;
    int matrix1[rows][columns];
    cout<<"Enter elements of matrix 1:"<<endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cin>>matrix1[i][j];
        }
    }
    int matrix2[rows][columns];
    cout<<"Enter elements of matrix 2:"<<endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cin>>matrix2[i][j];
        }
    }
    int result[rows][columns];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    cout<<"Matrix Addition is:"<<endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}