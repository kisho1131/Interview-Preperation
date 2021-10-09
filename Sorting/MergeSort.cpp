#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

void Merge(int *arr, int low, int mid, int high) {
  int temp[high - low + 1];
  int i = low;
  int j = mid + 1;
  int k = 0;

  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }
  while (i <= mid)
    temp[k++] = arr[i++];

  while (j <= high)
    temp[k++] = arr[j++];

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
}

void MergeSort(int *arr, int low, int high) {
  if (low >= high)
    return;
  int mid = low + (high - low) / 2;
  MergeSort(arr, low, mid);
  MergeSort(arr, mid + 1, high);
  Merge(arr, low, mid, high);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);
  MergeSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
