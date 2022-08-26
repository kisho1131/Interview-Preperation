#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
// window size is given by (j-i+1);
int MaxSum(int *arr, int n, int k) {
  int i = 0;
  int j = 0;
  int maxSum = INT_MIN;
  int currSum = 0;
  while (j < n) {
    // Calculations
    currSum += arr[j];
    if (j - i + 1 < k)
      j++;
    else if (j - i + 1 == k) {
      maxSum = max(maxSum, currSum);
      // Remove the Previous Calculation
      currSum -= arr[i];
      i++;
      j++;
    }
  }
  return maxSum;
}

int countOccuranceAnagram(string str, string ana) {
  map<string, int> mp;
  for (auto ch : ana)
    mp[ch]++;
  int k = ana.length();
  int n = str.length();
  int i = 0;
  int j = 0;
  int ans = 0;
  int count = mp.size();
  ;
  while (j < n) {
    if (mp.find(str[j]) != mp.end())
      mp[str[j]]--;
    if (mp[str[j]] == 0)
      count--;
    if (j - i + 1 < k)
      j++;
    else if (j - i + 1 == k) {
      if (count == 0)
        ans++;
      if (mp.find(str[i]) != mp.end()) {
        mp[str[i]]++;
        if (mp[str[i]] == 1)
          count++;
      }
    }
  }
  return ans;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(arr) / sizeof(int);
  int k = 3;
  cout << MaxSum(arr, n, k);
  cout << endl;
  return 0;
}
