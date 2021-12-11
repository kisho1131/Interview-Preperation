#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
/* Search in Row wise And Column wise Sorted Array */

pair<int, int> SearchSortedMatrix(int arr[4][4], int n, int m, int key) {
  int i = 0;
  int j = m - 1;
  while (i >= 0 && j >= 0 && i <= n && j <= m) {
    if (arr[i][j] == key)
      return make_pair(i, j);
    else if (arr[i][j] > key)
      j--;
    else if (arr[i][j] < key)
      i++;
  }
  return make_pair(-1, -1);
}
// Time complecity => O(N+M)
// N-: no of rows, M-: no of column
/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[4][4] = {
      {10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};
  pair<int, int> pr = SearchSortedMatrix(arr, 4, 4, 10);
  cout << pr.first << " " << pr.second;
  cout << endl;
  return 0;
}
