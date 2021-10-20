#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int SearchNearlySortedArray(int *arr, int n, int x) {
  int start = 0;
  int end = n - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == x)
      return mid;
    if (mid - 1 >= start && arr[mid - 1] == x)
      return mid - 1;
    if (mid + 1 <= end && arr[mid + 1] == x)
      return mid + 1;
    else if (x < arr[mid])
      end = mid - 2;
    else
      start = mid + 2;
  }
  return -1;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {10, 3, 40, 20, 50, 80, 70};
  int key = 90;
  int n = sizeof(arr) / sizeof(int);
  cout << SearchNearlySortedArray(arr, n, key);
  cout << endl;
  return 0;
}
