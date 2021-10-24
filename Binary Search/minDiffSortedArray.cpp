#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

int MinDiffSortedArray(int *arr, int n, int ele) {
  int start = 0;
  int end = n - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (ele == arr[mid])
      return arr[mid];
    else if (ele < arr[mid])
      end = mid - 1;
    else
      start = mid + 1;
  }
  int temp1 = abs(arr[start] - ele);
  int temp2 = abs(arr[end] - ele);
  return temp1 < temp2 ? arr[start] : arr[end];
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 3, 6, 8, 10, 14, 15};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 7;
  cout << MinDiffSortedArray(arr, n, key);
  cout << endl;
  return 0;
}
