#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */

vector<int> subSetSum(int arr[], int n, int sum) {
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
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  vector<int> res;
  for (int col = 0; col < sum / 2; col++) {
    if (dp[n][col] == true)
      res.push_back(col);
  }
  return res;
}
int MinSubSetSumDifference(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];
  vector<int> res = subSetSum(arr, n, sum);
  int minSubsetSum = INT_MAX;
  for (int i = 0; i < res.size(); i++) {
    minSubsetSum = min(minSubsetSum, (sum - 2 * res[i]));
  }
  return minSubsetSum;
}
/* =========================== Main() =========================== */
int main() {
  int arr[] = {1, 2, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << MinSubSetSumDifference(arr, n);
  cout << endl;
  return 0;
}
