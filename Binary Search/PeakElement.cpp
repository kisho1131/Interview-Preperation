#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int PeakElement(int *arr, int n) {
  int st = 0;
  int ed = n - 1;
  while (st <= ed) {
    int mid = st + (ed - st) / 2;
    if (mid > 0 && mid < n - 1) {
      if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        return mid;
      else if (arr[mid + 1] > arr[mid]) // right side is more promisng for ans
                                        // so move to the right half
        st = mid + 1;
      else // else left side is more promising for ans and mode to the left half
        ed = mid - 1;
    } else if (mid == 0) // if mid if pointing to the first element for with
                         // left dosen't exist
      return arr[0] > arr[1] ? 0 : 1;

    else if (mid == n - 1) // if the mid is pointing to the last index for which
                           // right dosen't exist
      return arr[n - 1] > arr[n - 2] ? n - 1 : n - 2;
  }
  return -1;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 3, 6, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << PeakElement(arr, n);
  cout << endl;
  return 0;
}
