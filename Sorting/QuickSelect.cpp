#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
/* Function Return the Kth Smallest Element from that Array */
int Partation(int *arr, int st, int ed) {
  int j = st;
  int i = st;
  int pivot = arr[ed];
  while (i < ed) {
    if (arr[i] > pivot)
      i++;
    else {
      swap(arr[i], arr[j]);
      i++;
      j++;
    }
  }
  swap(arr[j], arr[ed]);
  return j;
}

int QuickSelect(int *arr, int st, int ed, int k) {
  int pivotIndex = Partation(arr, st, ed);
  if (pivotIndex < k)
    return QuickSelect(arr, pivotIndex + 1, ed, k);
  else if (pivotIndex > k)
    return QuickSelect(arr, st, pivotIndex - 1, k);
  else
    return arr[pivotIndex];
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 4, 2, 3, 5, 7, 6, 9, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 4;
  cout << QuickSelect(arr, 0, n - 1, k - 1);
  cout << endl;
  return 0;
}
