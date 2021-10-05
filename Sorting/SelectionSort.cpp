#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void SelectionSort(int *arr, int n) {
  for (int i = 0; i < n - 2; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min])
        min = j;
    }
    swap(arr[i], arr[min]);
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);
  SelectionSort(arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
