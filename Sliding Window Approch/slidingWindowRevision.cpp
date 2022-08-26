#include <bits/stdc++.h>
using namespace std;
/* ========== YOUR CODE START HERE ========= */

int maxSubarraySum(vector<int> arr, int k) {
  int i = 0;
  int j = 0;
  int maxSum = INT_MIN;
  int currSum = 0;
  while (j < arr.size()) {
    currSum += arr[j];

    // check the window size
    if ((j - i + 1) < k)
      j++;

    // window size is hit we will maintain th e window size
    else if (j - i + 1 == k) {
      maxSum = max(maxSum, currSum);
      currSum -= arr[i];
      i++;
      j++;
    }
  }
  return maxSum;
}

vector<int> maxInWindowSizeK(vector<int> arr, int n) {
  int i = 0;
  int j = 0;
  vector<int> ans;
  return ans;
}

int largestSubarrySumK(vector<int> arr, int k) {
  int j = 0;
  int i = 0;
  int sum = 0;
  int maxlen = INT_MIN;
  while (j < arr.size()) {
    sum += arr[j];
    if (sum < k)
      j++;
    else if (sum == k) {
      maxlen = max(maxlen, j - i + 1);
      j++;
    } else if (sum > k) {
      while (sum > k) {
        sum -= arr[i];
        i++;
      }
      if (sum == k)
        maxlen = max(maxlen, j - i + 1);
      j++;
    }
  }
  return maxlen;
}

/* Longest String with "K" Unique Character */
int LongestStringWithKUnique(string str, int k) {
  int i = 0;
  int j = 0;
  map<char, int> mp;
  int maxlen = 0;
  while (j < str.size()) {
    mp[str[j]]++;
    if (mp.size() == k)
      maxlen = max(maxlen, j - i + 1);
    else if (mp.size() > k) {
      mp[str[i]]--;
      if (mp[str[i]] == 0)
        mp.erase(str[i]);
      i++;
    }
    j++;
  }
  return maxlen;
}

int LongestSubstringWithAllUniqueChar(string str) {
  int i = 0;
  int j = 0;
  map<char, int> mp;
  int maxlen = 0;
  while (j < str.size()) {
    mp[str[j]]++;
    if (mp.size() < j - i + 1) {
      while (mp.size() < j - i + 1) {
        mp[str[i]]--;
        if (mp[str[i]] == 0)
          mp.erase(str[i]);
        i++;
      }
    } else if (mp.size() == j - i + 1) {
      maxlen = max(maxlen, j - i + 1);
      j++;
    }
  }
  return maxlen;
}
/* ========== YOUR CODE END HERE ========= */

/* ========== Main Function ============== */
int main() {
  vector<int> arr = {10, 5, 2, 7, 1, 9};
  // int k = 15;
  string str = "aabbcc";
  int k = 3;
  cout << LongestStringWithKUnique(str, k);
  // cout << largestSubarrySumK(arr, k);
  return 0;
}
