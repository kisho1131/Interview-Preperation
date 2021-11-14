#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void Insert(stack<int> &s, int temp) {
  if (s.size() == 0) {
    s.push(temp);
    return;
  }
  int val = s.top();
  s.pop();
  Insert(s, temp);
  s.push(val);
}
void ReverseStack(stack<int> &s) {
  if (s.size() == 1)
    return;
  int temp = s.top();
  s.pop();
  ReverseStack(s);
  Insert(s, temp);
  return;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
  stack<int> s;
  for (auto ele : arr)
    s.push(ele);
  ReverseStack(s);
  while (s.size() != 0) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  return 0;
}
