// Program 2: Solve Matrix Chain Multiplication using Dynamic Programming

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainOrder(vector<int>& p, int n) {
    // dp[i][j] stores the minimum number of scalar multiplications 
    // needed to compute the matrix A[i]...A[j]
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // L is the chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                // Cost = cost of splitting + cost of multiplying the two resulting matrices
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    // Matrices dimensions: A1(10x20), A2(20x30), A3(30x40), A4(40x30)
    vector<int> arr = {10, 20, 30, 40, 30};
    int n = arr.size();

    cout << "Matrix Dimensions Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nMinimum number of multiplications is: " 
         << matrixChainOrder(arr, n) << "\n";

    return 0;
}

/* --- OUTPUT ---
Matrix Dimensions Array: 10 20 30 40 30 
Minimum number of multiplications is: 30000
*/
