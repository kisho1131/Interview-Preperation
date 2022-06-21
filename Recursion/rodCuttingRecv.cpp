#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */

int RodCutting(int price[], int maxlen, int dp[]) {
  if (maxlen == 0)
    return 0;
  int maxProfit = INT_MIN;
  if (dp[maxlen] >= 0)
    return dp[maxlen];
  for (int i = 1; i <= maxlen; i++) {
    maxProfit =
        max(maxProfit, price[i - 1] + RodCutting(price, maxlen - i, dp));
    dp[maxlen] = maxProfit;
  }
  return maxProfit;
}

/* =========================== Main() =========================== */
int main() {

  int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  int maxlen = 4;
  int n = sizeof(price) / sizeof(price[0]);
  int dp[maxlen];
  memset(dp, sizeof(dp), -1);
  cout << RodCutting(price, maxlen, dp);
  cout << endl;
  return 0;
}
