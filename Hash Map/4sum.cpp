#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */

// Approch : 1
// Time : O(N^4)LogN
// Space : O(N)
set<vector<int>> Function(vector<int> nums, int n, int target) {
  set<vector<int>> s;
  int sum = 0;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n - 3; i++) {
    if (i > 0 and nums[i] == nums[i - 1])
      continue; // Skip the same value for index i to avoid duplicates
    for (int j = i + 1; j < n - 2; j++) {
      if (j > i and nums[j] == nums[j - 1])
        continue; // Skip the same value for the index j to avoid duplicates
      for (int k = j + 1; k < n - 1; k++) {
        if (k > j and nums[k] == nums[k - 1])
          continue; // Skip the same value for index k to avoid duplicates
        for (int l = k + 1; l < n; l++) {
          sum = nums[i] + nums[j] + nums[k] + nums[l];
          if (sum > target)
            break;
          if (sum == target) {
            vector<int> temp;
            temp.push_back(nums[i]);
            temp.push_back(nums[j]);
            temp.push_back(nums[k]);
            temp.push_back(nums[l]);
            s.insert(temp);
          }
        }
      }
    }
  }
  return s;
}

/* =========================== Main() =========================== */
int main() {
  vector<int> nums = {-2, -1, 0, 0, 1, 2, 3, 0};
  int n = nums.size();
  int target = 3;
  set<vector<int>> s = Function(nums, n, target);
  for (auto itr : s) {
    for (auto ele : itr) {
      cout << ele << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
