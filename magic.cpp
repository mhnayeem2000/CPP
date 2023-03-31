#include <bits/stdc++.h>
using namespace std;

int colSum, row, col, sumDiag1=0, sumDiag2=0, matrix[50][50], n, m;

int isMagicSquare(int matrix[50][50], int n, int m){
    // Check diagonal sums
    for (row = 0; row < n; row++)
        sumDiag1 += matrix[row][row];

    for (row = 0; row < n; row++)
        sumDiag2 += matrix[row][n - 1 - row];

    if(sumDiag1 != sumDiag2)
        return 0;

    // Check row sums
    for (row = 0; row < n; row++){
        int rowSum = 0;

        for (col = 0; col < m; col++)
            rowSum += matrix[row][col];

        if (rowSum != sumDiag1)
            return 0;
    }

    // Check column sums
    for (col = 0; col < n; col++){
        colSum = 0;

        for (row = 0; row < n; row++)
            colSum += matrix[row][col];

        if (colSum != sumDiag1)
            return 0;
    }

    return 1;
}

int main(){
    cout<<"Enter the number of rows of the matrix: ";
    cin >> m;
    cout<<"Enter the number of columns of the matrix: ";
    cin >> n;

    if(n != m){
        cout<<"The matrix must be a square matrix.";
        exit(0);
    }

    cout << "\nEnter the elements of the matrix: \n";
    for(row = 0; row < n; row++)
        for(col = 0; col < m; col++)
            cin >> matrix[row][col];

    if (isMagicSquare(matrix, n, m))
        cout << "\nThe matrix follows the Lo Shu magic square.";
    else
        cout << "\nThe matrix does not follow the Lo Shu magic square.";
}
