#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
vector<int> KSortedArray(int *arr, int n, int k) {
  priority_queue<int, vector<int>, greater<int>> minHeap;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    minHeap.push(arr[i]);
    if (minHeap.size() > k) {
      ans.push_back(minHeap.top());
      minHeap.pop();
    }
  }
  while (!minHeap.empty()) {
    ans.push_back(minHeap.top());
    minHeap.pop();
  }
  return ans;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {2, 3, 6, 8, 12, 56};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 3;
  vector<int> ans = KSortedArray(arr, n, k);
  for (auto ele : ans) {
    cout << ele << " ";
  }
  cout << endl;
  return 0;
}
