#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void recusiveSolution(int open, int close, string op, vector<string> &ans) {
  if (open == 0 && close == 0) {
    ans.push_back(op);
    return;
  }
  if (open > 0) {
    string op1 = op;
    op1.push_back('(');
    recusiveSolution(open - 1, close, op1, ans);
  }
  if (close > open) {
    string op2 = op;
    op2.push_back(')');
    recusiveSolution(open, close - 1, op2, ans);
  }
}
void BalanceParentheses(int n) {
  vector<string> ans;
  int open = n;
  int close = n;
  string op = "";
  recusiveSolution(open, close, op, ans);
  for (auto ele : ans) {
    cout << ele << " " << endl;
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  BalanceParentheses(n);
  cout << endl;
  return 0;
}
