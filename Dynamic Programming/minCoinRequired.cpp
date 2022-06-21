#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */
int minCoinsRequired(int coins[], int n, int V) {
  int dp[n + 1][V + 1];
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < V + 1; j++) {
      if (i == 0)
        dp[i][j] = INT_MAX - 1;
      if (j == 0)
        dp[i][j] = 0;
    }
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < V + 1; j++) {
      if (coins[i - 1] <= j) {
        dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
      } else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][V];
}

/* =========================== Main() =========================== */
int main() {
  int coins[] = {3, 2, 5};
  int n = sizeof(coins) / sizeof(coins[0]);
  int V = 5;
  cout << minCoinsRequired(coins, n, V);
  cout << endl;
  return 0;
}
