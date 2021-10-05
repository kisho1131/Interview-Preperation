#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void InsertionSort(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (arr[j + 1] < arr[j])
        swap(arr[j + 1], arr[j]);
    }
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);
  InsertionSort(arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
