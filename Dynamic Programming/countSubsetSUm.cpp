#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

/*  Innitilazation of dp[][]
   dp[0][0] = 1
   for(int i=1;i<=sum;i++)
     dp[0][i] = 0;
   for(int i =1;i<=n;i++)
     dp[i][0] = 1;
*/

int CountSubsetSum(int arr[], int n, int sum) {
  int dp[n + 1][sum + 1];
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < sum + 1; j++) {
      if (i == 0)
        dp[i][j] = 0;
      if (j == 0)
        dp[i][j] = 1;
    }
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < sum + 1; j++) {
      if (arr[i - 1] <= j)
        dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][sum];
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n = 4;
  int arr[] = {3, 3, 3, 3};
  int sum = 6;
  cout << CountSubsetSum(arr, n, sum);
  cout << endl;
  return 0;
}
