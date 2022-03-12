#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */

// DP - Tabulation (Bottom - Up) TC: O(n * l) SC: O(n * l)

// int cutRod(int price[], int l) {
//   int[][] dp = new int[price.length + 1][l + 1];
//   for (int i = 1; i <= price.length; i++) {
//     for (int j = 1; j <= l; j++) {
//       if (j >= i)
//         dp[i][j] = Math.max(price[i - 1] + dp[i][j - i], dp[i - 1][j]);
//       else
//         dp[i][j] = dp[i - 1][j];
//     }
//   }
//   return dp[price.length][l];
// }

int RodCuttingProblem(int price[], int n) {
  int dp[n + 1][n + 1];
  for (int i = 0; i < n + 1; i++)
    for (int j = 0; j < n + 1; j++)
      if (i == 0 || j == 0)
        dp[i][j] = 0;

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (i <= j)
        dp[i][j] = max(price[i - 1] + dp[i][j - i], dp[i - 1][j]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][n];
}

/* =========================== Main() =========================== */
int main() {
  int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
  int n = sizeof(price) / sizeof(price[0]);
  cout << RodCuttingProblem(price, n);
  return 0;
}

// len = rod size
