#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

/* Return the First Occurance of the Array */
int FirstOccurance(int *arr, int n, int x) {
  int start = 0;
  int end = n - 1;
  int res = -1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (x == arr[mid]) {
      res = mid;
      end = mid - 1;
    } else if (x < arr[mid])
      end = mid - 1;
    else
      start = mid + 1;
  }
  return res;
}

/* Return the Last Occurance of the Array */
int LastOccurance(int *arr, int n, int x) {
  int start = 0;
  int end = n - 1;
  int res = -1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (x == arr[mid]) {
      res = mid;
      start = mid + 1;
    } else if (x < arr[mid])
      end = mid - 1;
    else
      start = mid + 1;
  }
  return res;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {5, 6, 10, 10, 10, 10, 12};
  int n = sizeof(arr) / sizeof(int);
  cout << LastOccurance(arr, n, 10) + 1;
  cout << endl;
  return 0;
}
