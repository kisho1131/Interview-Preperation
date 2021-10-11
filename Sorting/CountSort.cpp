#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void CountSort(int *arr, int n) {
  int maxEle = *max_element(arr, arr + n);
  int minEle = *min_element(arr, arr + n);
  int range = maxEle - minEle + 1;
  int freq[range];
  memset(freq, 0, sizeof(freq));
  for (int i = 0; i < n; i++) {
    int idx = arr[i] - minEle;
    freq[idx]++;
  }

  for (int i = 1; i < range; i++) {
    freq[i] = freq[i] + freq[i - 1];
  }

  int ans[n];
  // memset(ans, 0, sizeof(ans));
  for (int i = n - 1; i >= 0; i--) {
    int val = arr[i];
    // cout << val << " ";
    int pos = freq[val - minEle];
    int idx = pos - 1;
    ans[idx] = val;
    freq[val - minEle]--;
  }
  for (int i = 0; i < n; i++)
    arr[i] = ans[i];
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {9, 6, 3, 5, 3, 4, 3, 9, 6, 4, 6, 5, 8, 9, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  CountSort(arr, n);
  for (auto ele : arr) {
    cout << ele << " ";
  }
  cout << endl;
  return 0;
}
