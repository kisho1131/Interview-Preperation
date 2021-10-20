#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int LastOccurance(int *arr, int n, int x) {
  int st = 0;
  int ed = n - 1;
  int res = -1;
  while (st <= ed) {
    int mid = st + (ed - st) / 2;
    if (x == arr[mid]) {
      res = mid;
      st = mid + 1;
    } else if (x < arr[mid])
      ed = mid - 1;
    else
      st = mid + 1;
  }
  return res;
}

int FirstOccurance(int *arr, int n, int x) {
  int st = 0;
  int ed = n - 1;
  int res = -1;
  while (st <= ed) {
    int mid = st + (ed - st) / 2;
    if (x == arr[mid]) {
      res = mid;
      ed = mid - 1;
    } else if (x < arr[mid])
      ed = mid - 1;
    else
      st = mid + 1;
  }
  return res;
}
int CountElementSortedArray(int *arr, int n, int x) {
  int firstOccur = FirstOccurance(arr, n, x);
  int lastOccur = LastOccurance(arr, n, x);
  return lastOccur - firstOccur + 1;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {2, 4, 6, 10, 10, 10, 10, 10, 10, 14, 16, 18, 20};
  int n = sizeof(arr) / sizeof(int);
  cout << CountElementSortedArray(arr, n, 10);
  cout << endl;
  return 0;
}
