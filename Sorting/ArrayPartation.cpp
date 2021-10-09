#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int ArrayPartation(int *arr, int low, int n) {
  int i = low;
  int j = low;
  int pivot = arr[n];
  while (i < n) {
    if (arr[i] > pivot)
      i++;
    else {
      swap(arr[i], arr[j]);
      i++;
      j++;
    }
  }
  swap(arr[j], arr[n]);
  return j;
}

void QuickSort(int *arr, int low, int high) {
  if (low < high) {
    int pivotIndex = ArrayPartation(arr, low, high);
    QuickSort(arr, low, pivotIndex - 1);
    QuickSort(arr, pivotIndex + 1, high);
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 4, 2, 3, 5, 7, 6, 9, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  QuickSort(arr, 0, n - 1);
  // cout << ArrayPartation(arr, 0, n) << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
