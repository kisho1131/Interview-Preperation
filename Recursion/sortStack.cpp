#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

void Insert(stack<int> &s, int temp) {
  if (s.size() == 0 || s.top() <= temp) {
    s.push(temp);
    return;
  }
  int val = s.top();
  s.pop();
  Insert(s, temp);
  s.push(val);
  return;
}

void SortStack(stack<int> &s) {
  if (s.size() == 1)
    return;
  int temp = s.top();
  s.pop();
  SortStack(s);
  Insert(s, temp);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {5, 7, 1, 3, 4, 7, 9};
  stack<int> s;
  for (auto ele : arr)
    s.push(ele);
  SortStack(s);
  while (s.size() != 0) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  return 0;
}
