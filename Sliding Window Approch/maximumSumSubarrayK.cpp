#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

int maximumSumSubarrayK_BruteForce(vector<int> arr, int k) {
  int maxSum = 0;
  int windowSum = 0;
  for (int i = 0; i <= arr.size() - k; i++) {
    windowSum = 0;
    for (int j = i; j < i + k; j++) {
      windowSum += arr[j];
    }
    maxSum = max(maxSum, windowSum);
  }
  return maxSum;
}

/* Optimized Approch Using Two Pointer Algorithm */
int maximumSumSubarrayK(vector<int> arr, int k) {
  int maxSum = INT_MIN;
  int i = 0;
  int j = 0;
  int currSum = 0;
  while (j < arr.size()) {
    currSum += arr[j];
    if ((j - i + 1) < k) {
      j++;
    } else if ((j - i + 1) == k) {
      maxSum = max(maxSum, currSum);
      currSum -= arr[i];
      i++;
      j++;
    }
  }
  return maxSum;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
  int k = 3;

  int maxSum = maximumSumSubarrayK(arr, k);
  int maxSum_ = maximumSumSubarrayK_BruteForce(arr, k);
  cout << maxSum << endl;
  cout << maxSum_;
  cout << endl;
  return 0;
}
