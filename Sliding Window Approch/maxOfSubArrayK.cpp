#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

vector<int> maxOfSubArray(vector<int> arr, int k) {
  int j = 0;
  int i = 0;
  vector<int> ans;
  list<int> l;
  while (j < arr.size()) {
    while (l.size() > 0 && l.front() < arr[j]) {
      l.pop_front();
    }
    l.push_back(arr[j]);
    if ((j - i + 1) < k)
      j++;
    else if ((j - i + 1) == k) {
      ans.push_back(l.front());
      if (arr[i] == l.front())
        l.pop_front();
      i++;
      j++;
    }
  }
  return ans;
}

vector<int> maxOfSubArrayBruteForce(vector<int> arr, int k) {
  vector<int> ans;
  for (int i = 0; i < arr.size() - k + 1; i++) {
    int maxele = arr[i];
    for (int j = i + 1; j < i + k; j++) {
      maxele = max(maxele, arr[j]);
    }
    ans.push_back(maxele);
  }
  return ans;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {1, -2, 5, 3, 4, 6, -7, -1, -3};
  int k = 3;
  vector<int> ans = maxOfSubArray(arr, k);
  for (auto ele : ans) {
    cout << ele << " ";
  }
  cout << endl;
  return 0;
}
