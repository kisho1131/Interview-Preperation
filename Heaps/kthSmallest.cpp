#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int KthSmallest(int *arr, int n, int k) {
  priority_queue<int> maxHeap;
  for (int i = 0; i < n; i++) {
    maxHeap.push(arr[i]);
    if (maxHeap.size() > k)
      maxHeap.pop();
  }
  return maxHeap.top();
}

void kLargest(int *arr, int n, int k) {
  priority_queue<int, vector<int>, greater<int>> minHeap;
  for (int i = 0; i < n; i++) {
    minHeap.push(arr[i]);
    if (minHeap.size() > k)
      minHeap.pop();
  }
  while (!minHeap.empty()) {
    cout << minHeap.top() << " ";
    minHeap.pop();
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 4, 2, 6, 5, 15, 23, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 3;
  cout << KthSmallest(arr, n, k);
  cout << endl;
  kLargest(arr, n, k);
  cout << endl;
  return 0;
}
