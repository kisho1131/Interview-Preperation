#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */

int subsetSumDiff(vector<int> arr, int sum) {
  int n = arr.size();
  long long dp[n + 1][sum + 1];
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < sum + 1; j++) {
      if (i == 0)
        dp[i][j] = 0;
      if (j == 0)
        dp[i][j] = 1;
    }
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < sum + 1; j++) {
      if (arr[i - 1] <= j)
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][sum];
}

int findTargetSumWays(vector<int> &nums, int target) {
  int arrSum = 0;
  if (nums.size() == 0)
    return 0;
  for (int i = 0; i < nums.size(); i++)
    arrSum += nums[i];
  if (arrSum < abs(target) || (target + arrSum) % 2 != 0)
    return 0;
  int sum = (target + arrSum) / 2;
  return subsetSumDiff(nums, sum);
}

/* =========================== Main() =========================== */
int main() {
  vector<int> arr = {1, 1, 1, 1, 1};
  int target = 3;
  cout << findTargetSumWays(arr, target);
  return 0;
}
