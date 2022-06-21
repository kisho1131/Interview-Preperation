#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */

int minCoinsRequired(int coins[], int n, int V) {
  if (V == 0)
    return 0;
  if (n == 0)
    return INT_MAX - 1;

  if (coins[n - 1] <= V) {
    return min(1 + minCoinsRequired(coins, n, V - coins[n - 1]),
               minCoinsRequired(coins, n - 1, V));
  } else
    return minCoinsRequired(coins, n - 1, V);
}

/* =========================== Main() =========================== */
int main() {
  int coins[] = {9, 6, 5, 1};
  int n = sizeof(coins) / sizeof(coins[0]);
  int V = 11;
  cout << minCoinsRequired(coins, n, V);
  return 0;
}
