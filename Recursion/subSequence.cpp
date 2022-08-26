#include <bits/stdc++.h>
using namespace std;
/* ========== YOUR CODE START HERE ========= */

/* Print Subsequence */
void PrintSubSeq(int idx, vector<int> ds, int arr[], int n) {
  if (idx == n) {
    for (auto ele : ds) {
      cout << ele;
    }
    cout << endl;
    return;
  }
  // Condition to Not pick the element from the Array
  PrintSubSeq(idx + 1, ds, arr, n);

  // Condition to pick the element from Array
  ds.push_back(arr[idx]);
  PrintSubSeq(idx + 1, ds, arr, n);
  ds.pop_back();
}

/* Print All Subsequence with the Given Sum */
void PrintAllSubSequenceSum(int idx, vector<int> ds, int currSum, int sum,
                            int arr[], int n) {
  if (idx == n) {
    if (currSum == sum) {
      for (auto ele : ds) {
        cout << ele;
      }
      cout << endl;
    }
    return;
  }
  // Condition to not pick the element
  PrintAllSubSequenceSum(idx + 1, ds, currSum, sum, arr, n);

  // Condition to Pick the element
  ds.push_back(arr[idx]);
  currSum += arr[idx];
  PrintAllSubSequenceSum(idx + 1, ds, currSum, sum, arr, n);

  // BackTracking the Solution
  ds.pop_back();
  currSum -= arr[idx];
}

/* Count the No of Sbsequence with the given Sum */
int CountSubSeqWithSum(int idx, int currSum, int sum, int arr[], int n) {
  if (idx == n) {
    if (currSum == sum) {
      return 1;
    }
    return 0;
  }

  int left = CountSubSeqWithSum(idx + 1, currSum, sum, arr, n);

  currSum += arr[idx];
  int right = CountSubSeqWithSum(idx + 1, currSum, sum, arr, n);
  currSum -= arr[idx];
  return left + right;
}
/* ========== YOUR CODE END HERE ========= */

/* ========== Main Function ============== */
int main() {
  int arr[] = {1, 3, 4, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  // vector<int> ds;
  int idx = 0;
  int sum = 5;
  cout << CountSubSeqWithSum(idx, 0, sum, arr, n);
  cout << endl;
  return 0;
}
