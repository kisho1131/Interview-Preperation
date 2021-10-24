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
      else if (arr[mid + 1] > arr[mid])
        st = mid + 1;
      else
        ed = mid - 1;
    } else if (mid == 0)
      return arr[0] > arr[1] ? 0 : 1;

    else if (mid == n - 1)
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
