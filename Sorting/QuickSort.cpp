#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int Partition(int a[], int low, int high) {
  int pivot, index, i;
  index = low;
  pivot = high;

  // Getting index of the pivot.
  for (i = low; i < high; i++) {
    if (a[i] < a[pivot]) {
      swap(&a[i], &a[index]);
      index++;
    }
  }
  // Swapping value at high and at the index obtained.
  swap(&a[pivot], &a[index]);

  return index;
}

void QuickSort(int a[], int low, int high) {
  int pindex;
  if (low < high) {
    pindex = Partition(a, low, high);
    // Recursively implementing QuickSort.
    QuickSort(a, low, pindex - 1);
    QuickSort(a, pindex + 1, high);
  }
  // return 0;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {7, 9, 4, 8, 3, 6, 2, 1, 0, 10, 17, 12, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  QuickSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
