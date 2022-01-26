#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */
int KadansAlgorithm(vector<int> nums) {
  int bestSum = INT_MIN;
  int currentSum = 0;
  for (int i = 0; i < nums.size(); i++) {
    // to the current sum check if current element add's up and make the larger
    // sum if so consider else consider the current sum and neglect the element
    currentSum = max(nums[i], currentSum + nums[i]);
    bestSum = max(bestSum, currentSum);
  }
  return bestSum;
}

/* =========================== Main() =========================== */
int main() {
  vector<int> arr = {-1, 2, 4, -3, 5, 2, -5, 2};
  int bestSum = KadansAlgorithm(arr);
  cout << bestSum;
  cout << endl;
  return 0;
}
