#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void PrintSubset(string str, string op) {

  if (str.length() == 0) {
    cout << op << "  ";
    return;
  }
  string op1 = op;
  string op2 = op;
  op2.push_back(str[0]);
  str.erase(str.begin() + 0);
  PrintSubset(str, op2);
  PrintSubset(str, op1);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string str = "aab";
  string op = "_";
  PrintSubset(str, op);
  cout << endl;
  return 0;
}
