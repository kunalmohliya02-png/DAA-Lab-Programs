// Program 4: Solve the 0/1 Knapsack problem using Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    // dp[i][w] stores the maximum value that can be attained with 
    // weight less than or equal to w using first i items
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50; // Capacity of Knapsack
    int n = profit.size();

    cout << "Item Profits: ";
    for (int p : profit) cout << p << " ";
    cout << "\nItem Weights: ";
    for (int w : weight) cout << w << " ";
    cout << "\nKnapsack Capacity: " << W << "\n";
    cout << "Maximum Profit earned: " << knapSack(W, weight, profit, n) << "\n";

    return 0;
}

/* --- OUTPUT ---
Item Profits: 60 100 120 
Item Weights: 10 20 30 
Knapsack Capacity: 50
Maximum Profit earned: 220
*/
