#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void PivotSortedRotated(int *arr, int n) {
  for (int i = 1; i < n - 1; i++) {
    if (arr[i] < arr[i - 1] and arr[i] < arr[i + 1]) {
      cout << "Index = " << i;
      break;
    }
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {50, 40, 10, 20, 30};
  int n = sizeof(arr) / sizeof(arr[0]);
  PivotSortedRotated(arr, n);
  cout << endl;
  return 0;
}
