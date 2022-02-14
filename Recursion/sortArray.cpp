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

/*

void Insert(vector<int>&arr, int lastval){
  if(arr.size() == 0 || arr[arr.size()-1] <= lastval){
    arr.push_back(lastval);
    reurn;
  }
  int ele = arr[arr.size()-1];
  arr.pop_back();
  Insert(arr, lastval);
  arr.push_back(ele);
}

void sort(vector<int>arr){
  if(arr.size() == 0) return;
  int lastval = arr[arr.size()-1];
  arr.pop_back();
  sort(arr);
  Insert(arr, lastval);
}

*/
