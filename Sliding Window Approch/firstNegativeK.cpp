#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
vector<int> FirstNegativeK(vector<int> arr, int k) {
  vector<int> ans;
  list<int> l;
  int i = 0;
  int j = 0;
  while (j < arr.size()) {
    if (arr[j] < 0)
      l.push_back(arr[j]);
    if ((j - i + 1) < k)
      j++;
    else if (j - i + 1 == k) {
      if (l.empty())
        ans.push_back(0);
      else
        ans.push_back(l.front());

      if (arr[i] == l.front())
        // If we have processed this element then remove the
        // element form the list as we move thr windows size
        l.pop_front();
      i++;
      j++;
    }
  }
  return ans;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {1, -1, 3, 6, -3, 8, -4, 5, 7, 8};
  int k = 3;
  vector<int> ans = FirstNegativeK(arr, k);
  for (auto ele : ans) {
    cout << ele << " ";
  }
  cout << endl;
  return 0;
}
