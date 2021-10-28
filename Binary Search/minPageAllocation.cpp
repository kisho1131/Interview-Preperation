#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

bool isPossible(int *arr, int maxPage, int n, int k) {
  if (k > n)
    return false;
  int student = 1;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (sum > maxPage) {
      student++;
      sum = arr[i];
    }
    if (student > k)
      return false;
  }
  return true;
}

int minPageAllocation(int *arr, int n, int m) {
  int start = *max_element(arr, arr + n);
  int end = 0;
  for (int i = 0; i < n; i++)
    end += arr[i];
  int res = -1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (isPossible(arr, mid, n, m)) {
      end = mid - 1;
      res = mid;
    } else
      start = mid + 1;
  }
  return res;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {12, 34, 67, 90};
  int n = sizeof(arr) / sizeof(int);
  int m = 2;
  cout << minPageAllocation(arr, n, m);
  cout << endl;
  return 0;
}
