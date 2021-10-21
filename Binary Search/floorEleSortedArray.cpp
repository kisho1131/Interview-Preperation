#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
// Floor -> Greatest Element Smaller than given Element
int FloorElement(int *arr, int n, int ele) {
  int start = 0;
  int end = n - 1;
  int res = -1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (ele == arr[mid])
      return mid;
    else if (ele < arr[mid]) {
      end = mid - 1;
    } else if (ele > arr[mid]) {
      res = mid;
      start = mid + 1;
    }
  }
  return res;
}

// Ceil -> Smallest Element Greater that given Element
int CeilElement(int *arr, int n, int ele) {
  int st = 0;
  int ed = n - 1;
  int res = -1;
  while (st <= ed) {
    int mid = st + (ed - st) / 2;
    if (arr[mid] == ele)
      return mid;
    else if (ele < arr[mid]) {
      ed = mid - 1;
      res = mid;
    } else if (ele > arr[mid]) {
      st = mid + 1;
    }
  }
  return res;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 3, 4, 8, 10, 10, 12, 14};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << arr[CeilElement(arr, n, 5)];
  cout << endl;
  return 0;
}
