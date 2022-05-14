#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int BinarySearch(int *arr, int n, int x) {
  int start = 0;
  int end = n - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (x < arr[mid])
      end = mid - 1;
    else if (x > arr[mid])
      start = mid + 1;
    else
      return mid;
  }
  return -1;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13};
  int n = sizeof(arr) / sizeof(int);
  int index = BinarySearch(arr, n, 9);
  cout << "Index: " << index;
  cout << endl;
  return 0;
}
