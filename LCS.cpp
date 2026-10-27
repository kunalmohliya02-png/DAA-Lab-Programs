// Program 3: Find the Longest Common Subsequence (LCS) using Dynamic Programming

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void findLCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    // Create a DP table to store lengths of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the dp table in bottom-up fashion
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS string from the DP table
    int i = m, j = n;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "String 1: " << X << "\n";
    cout << "String 2: " << Y << "\n";
    cout << "Length of LCS: " << dp[m][n] << "\n";
    cout << "Longest Common Subsequence: " << lcs << "\n";
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    findLCS(X, Y);

    return 0;
}

/* --- OUTPUT ---
String 1: AGGTAB
String 2: GXTXAYB
Length of LCS: 4
Longest Common Subsequence: GTAB
*/
