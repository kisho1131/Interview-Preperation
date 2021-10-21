#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int NextAlphabet(char *arr, int n, char ch) {
  int st = 0;
  int ed = n - 1;
  while (st <= ed) {
    int mid = st + (ed - st) / 2;
    if (arr[mid] == ch)
      return mid;
    else if (ch < arr[mid])
      ed = mid - 1;
    else if (ch > arr[mid])
      st = mid + 1;
  }
  return st;
}

char NextAlphabet_(char *arr, int n, char ch) {
  int st = 0;
  int ed = n - 1;
  char res = '#';
  while (st <= ed) {
    int mid = st + (ed - st) / 2;
    if (arr[mid] == ch)
      st = mid + 1;
    else if (ch < arr[mid]) {
      res = arr[mid];
      ed = mid - 1;
    } else if (ch > arr[mid])
      st = mid + 1;
  }
  return res;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  char arr[] = {'a', 'c', 'f', 'g', 'h'};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << NextAlphabet_(arr, n, 'g');
  cout << endl;
  return 0;
}
