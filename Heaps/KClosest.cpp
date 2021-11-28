#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void Kclosest(int *arr, int n, int k, int x) {
  priority_queue<pair<int, int>> maxHeap;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    maxHeap.push({abs(arr[i] - x), arr[i]});
    if (maxHeap.size() > k) {
      maxHeap.pop();
    }
  }
  while (!maxHeap.empty()) {
    ans.push_back(maxHeap.top().second);
    maxHeap.pop();
  }
  for (auto ele : ans)
    cout << ele << " ";
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {5, 6, 7, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 3;
  int x = 7;
  Kclosest(arr, n, k, x);
  cout << endl;
  return 0;
}
