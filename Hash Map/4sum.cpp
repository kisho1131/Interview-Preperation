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

// Approch : 2
vector<vector<int>> Function_(vector<int> nums, int target) {
  vector<vector<int>> ans;
  set<vector<int>> s;
  int sum = 0;
  int n = nums.size();
  for (int i = 0; i < n - 3; i++) {
    for (int j = i + 1; j < n - 2; j++) {
      int left = j + 1;
      int right = n - 1;
      while (left < right) {
        sum = nums[i] + nums[j] + nums[left] + nums[right];
        if (sum > target)
          right = right - 1;
        else if (sum == target) {
          vector<int> res;
          res.push_back(nums[i]);
          res.push_back(nums[j]);
          res.push_back(nums[left]);
          res.push_back(nums[right]);
          s.insert(res);
          left = left + 1;
        } else
          left = left + 1;
      }
    }
  }
  for (auto itr : s) {
    ans.push_back(itr);
  }
  return ans;
}

// Approch : 3 (Two Pointer with constant space)
vector<vector<int>> fourSum(vector<int> &nums, int target) {
  vector<vector<int>> res;
  int n = nums.size();
  if (n < 4)
    return res;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < n - 3; i++) {
    if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
      // nums[i] + nums[i+1] + nums[i+2] + nums[i+3] --> can give integer
      // overflow
      if (nums[i] + nums[i + 1] > target - nums[i + 2] - nums[i + 3])
        break;
      if (nums[i] + nums[n - 3] < target - nums[n - 2] - nums[n - 1])
        continue;
      for (int j = i + 1; j < n - 2; j++) {
        if (j == i + 1 || (j > i + 1 && nums[j] != nums[j - 1])) {
          if (nums[i] + nums[j] > target - nums[j + 1] - nums[j + 2])
            break;
          if (nums[i] + nums[j] < target - nums[n - 2] - nums[n - 1])
            continue;
          int l = j + 1, h = n - 1;
          while (l < h) {
            if (nums[l] + nums[h] == target - nums[i] - nums[j]) {
              res.push_back({nums[i], nums[j], nums[l], nums[h]});
              while (l < h &&
                     nums[l] == nums[l + 1]) // Eleminating the duplictes
                                             // (Skiping the duplicate values)
                l++;
              while (l < h && nums[h] == nums[h - 1])
                h--;
              l++;
              h--;
            } else if (nums[l] + nums[h] < target - nums[i] - nums[j])
              l++;
            else
              h--;
          }
        }
      }
    }
  }
  return res;
}
/* =========================== Main() =========================== */
int main() {
  vector<int> nums = {-2, -1, 0, 0, 1, 2, 3, 0};
  int n = nums.size();
  int target = 3;
  vector<vector<int>> ans = Function_(nums, target);
  for (auto it : ans) {
    for (auto ele : it)
      cout << ele << " ";
    cout << endl;
  }
  cout << endl;
  return 0;
}
