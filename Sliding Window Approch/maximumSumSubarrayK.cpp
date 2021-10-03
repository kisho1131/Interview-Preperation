#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
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
  vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
  int k = 4;

  int maxSum = maximumSumSubarrayK(arr, k);
  cout << maxSum;
  cout << endl;
  return 0;
}
