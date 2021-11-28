#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int dp[100][100];
int KnapSack(int wt[], int val[], int w, int n) {
  if (n == 0 || w == 0)
    return 0;
  if (dp[n][w] != -1)
    return dp[n][w];
  if (wt[n - 1] <= w)
    dp[n][w] = max(val[n - 1] + KnapSack(wt, val, w - wt[n - 1], n - 1),
                   KnapSack(wt, val, w, n - 1));
  else
    dp[n][w] = KnapSack(wt, val, w, n - 1);
  return dp[n][w];
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  memset(dp, -1, sizeof(dp));
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int W = 50;
  int n = sizeof(val) / sizeof(val[0]);
  cout << KnapSack(wt, val, W, n);
  return 0;
}
