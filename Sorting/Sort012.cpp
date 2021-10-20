#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void Sort012(int *arr, int n) {
  int i = 0;
  int j = 0;
  int k = n - 1;
  while (i <= k) {
    if (arr[i] == 1)
      i++;
    else if (arr[i] == 0) {
      swap(arr[i], arr[j]);
      i++;
      j++;
    } else {
      swap(arr[i], arr[k]);
      k--;
    }
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 0, 1, 2, 2, 1, 0, 0, 2, 0, 2, 1, 1, 0, 2, 1, 0, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  Sort012(arr, n);
  for (auto ele : arr) {
    cout << ele << " ";
  }
  cout << endl;
  return 0;
}
