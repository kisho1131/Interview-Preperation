#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

void Insert(vector<int> &arr, int lastEle) {
  if (arr.size() == 0 || arr[arr.size() - 1] <= lastEle) {
    arr.push_back(lastEle);
    return;
  }
  int val = arr[arr.size() - 1];
  arr.pop_back();
  Insert(arr, lastEle);
  arr.push_back(val);
  return;
}

void Sort(vector<int> &arr) {
  if (arr.size() == 1)
    return;
  int lastEle = arr[arr.size() - 1];
  arr.pop_back();
  Sort(arr);
  Insert(arr, lastEle);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {1, 4, 2, 6, 5, 8, 3};
  Sort(arr);
  for (auto ele : arr)
    cout << ele << " ";
  cout << endl;
  return 0;
}
