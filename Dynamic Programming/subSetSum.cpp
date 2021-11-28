#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
bool SubsetSum(int arr[], int n, int sum) {
  bool dp[n + 1][sum + 1];
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < sum + 1; j++) {
      if (i == 0)
        dp[i][j] = false;
      if (j == 0)
        dp[i][j] = true;
    }
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < sum + 1; j++) {
      if (arr[i - 1] <= j)
        dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][sum];
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {3, 34, 4, 12, 5, 2};
  int n = sizeof(arr) / sizeof(int);
  int sum = 9;
  cout << SubsetSum(arr, n, sum);
  cout << endl;
  return 0;
}
