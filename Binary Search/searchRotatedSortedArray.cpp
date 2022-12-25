#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int searchRotatedArray(int *arr, int n, int target) {
  int start = 0;
  int end = n - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
      return mid;
    /* If the first half is sorted */
    if (arr[start] <= arr[mid]) {
      if (target >= arr[start] &&
          target <= arr[mid]) // check if the "target" lie in the first half
        end = mid - 1;
      else
       start = mid + 1;
   }

    /* If the second half is sorted */
   if (arr[mid] <= arr[end]) {
    if (target >= arr[mid] &&
          target <= arr[end]) // check if the "target" lie in the second half
      start = mid + 1;
    else
      end = mid - 1;
  }
}
return -1;
}

/*============ Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {3, 4, 5, 1, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << searchRotatedArray(arr, n, 4);
  cout << endl;
  return 0;
}
