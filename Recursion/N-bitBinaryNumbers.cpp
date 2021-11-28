#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void recusiveSolution(int one, int zero, int n, string op,
                      vector<string> &ans) {
  if (n == 0) {
    ans.push_back(op);
    return;
  }
  if (one < n) {
    string op1 = op;
    op1.push_back('1');
    recusiveSolution(one + 1, zero, n - 1, op1, ans);
  }
  if (zero <= one) {
    string op2 = op;
    op2.push_back('0');
    recusiveSolution(one, zero + 1, n - 1, op2, ans);
  }
  return;
}

void NbitBinaryNumbers(int n) {
  int one = 0;
  int zero = 0;
  string op = "";
  vector<string> ans;
  recusiveSolution(one, zero, n, op, ans);
  for (auto ele : ans) {
    cout << ele << " ";
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  NbitBinaryNumbers(n);
  cout << endl;
  return 0;
}
