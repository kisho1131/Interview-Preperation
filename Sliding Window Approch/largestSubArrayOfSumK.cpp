#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

/*
Problem Description:
---------------------
Given an array containing N positive integers and an integer K. Your task is to
find the length of the longest Sub-Array with sum of the elements equal to the
given value K.
*/

int LargestSubarrayOfSumK(vector<int> arr, int k) {
  int j = 0;
  int i = 0;
  int maxSize = 0;
  int sum = 0;
  while (j < arr.size()) {
    sum += arr[j];
    if (sum < k)
      j++;
    else if (sum == k) {
      maxSize = max(maxSize, (j - i + 1));
    } else if (sum > k) {
      while (sum > k) {
        sum -= arr[i];
        i++;
      }
    }
    j++;
  }
  return maxSize;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {-5, 8, -14, 2, 4, 12}; // Work for +ve elements Only
  int k = -5;
  int maxSize = LargestSubarrayOfSumK(arr, k);
  cout << maxSize;
  cout << endl;
  return 0;
}
