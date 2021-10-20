#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
/* Sort the array with 0 & 1 in O(N) time complexity */
void Sort01(int *arr, int n) {
  int i = 0;
  int j = 0;
  while (i < n) {
    if (arr[i] == 1)
      i++;
    else {
      swap(arr[i], arr[j]);
      i++;
      j++;
    }
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  Sort01(arr, n);
  for (auto ele : arr)
    cout << ele << " ";
  cout << endl;
  return 0;
}
