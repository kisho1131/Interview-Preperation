#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int FindRotation(int *arr, int n) {
  int start = 0;
  int end = n - 1;
  // Minimum Element always lie in the unsorted part of the Array
  while (start <= end) {
    if (arr[start] <= arr[end]) // Return the Start if the Array is Sorted
      return start;
    int mid = start + (end - start) / 2;
    int nextIdx = (mid + 1) % n;     // Find the Next Index
    int prevIdx = (mid + n - 1) % n; // Find the Previous Index
    if (arr[mid] <= arr[nextIdx] &&
        arr[mid] <= arr[prevIdx]) // If mid is the Minimum Element
      return mid;
    if (arr[start] <= arr[mid])
      start = mid + 1;
    else if (arr[mid] <= arr[end])
      end = mid - 1;
  }
  return -1;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {3, 4, 5, 1, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << FindRotation(arr, n);
  cout << endl;
  return 0;
}
