#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void DeleteMiddle(stack<int> &s, int k) {
  if (s.empty())
    return;
  if (k == 1) {
    s.pop();
    return;
  }
  int temp = s.top();
  s.pop();
  DeleteMiddle(s, k - 1);
  s.push(temp);
  return;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
  stack<int> s;
  for (auto ele : arr)
    s.push(ele);
  int k = s.size() / 2 + 1;
  DeleteMiddle(s, k);
  while (s.size() != 0) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  return 0;
}
