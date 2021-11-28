#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
vector<int> MergeArray(vector<int> arr, vector<int> brr) {
  int n = arr.size();
  int m = brr.size();
  vector<int> temp(n + m);
  int k = 0;
  int i = 0;
  int j = 0;
  while (i < n && j < m) {
    if (arr[i] <= brr[j]) {
      temp[k] = arr[i];
      k++;
      i++;
    } else {
      temp[k] = brr[j];
      j++;
      k++;
    }
  }
  while (i < n) {
    temp[k] = arr[i];
    k++;
    i++;
  }
  while (j < m) {
    temp[k] = brr[j];
    k++;
    j++;
  }
  return temp;
}
double Median2SortedArray(vector<int> arr, vector<int> brr) {
  vector<int> mergeArray = MergeArray(arr, brr);
  int n = arr.size();
  int m = brr.size();
  double median = 0.0;
  int mid = (n + m) / 2;
  if (mid * 2 % 2 == 0) {
    median = (double)(mergeArray[mid] + mergeArray[mid + 1]) / 2;
  } else {
    median = mergeArray[mid];
  }
  return median;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {1, 5, 7, 8, 11, 15, 16};
  vector<int> brr = {2, 4, 6, 9, 17};
  double median = Median2SortedArray(arr, brr);
  cout << median;
  return 0;
}
