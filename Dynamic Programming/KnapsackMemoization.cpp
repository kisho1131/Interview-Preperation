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

/* Top down Approch
int KnapSack(int wt[], int val[], int w, int n){
  int dp[n+1][w+1];
  for(int i=0;i<n+1;i++)
    for(int j=0;j<w+1;j++)
       if(i==0 || j ==0) dp[i][j] = 0;
  for(int i =1;i<n+1;i++){
    for(int j = 1;j<w+1;j++){
      if(wt[i-1] <= j){
        dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
      }
      else
       dp[i][j] = dp[i-1][j];
    }
  }
  return dp[n][w];
}
*/
