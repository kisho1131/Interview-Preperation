#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void PermutatonCaseChnage(string ip, string op) {
  if (ip.length() == 0) {
    cout << op << " ";
    return;
  }
  string op1 = op;
  string op2 = op;
  op1.push_back(ip[0]);
  op2.push_back(toupper(ip[0]));
  ip.erase(ip.begin() + 0);
  PermutatonCaseChnage(ip, op1);
  PermutatonCaseChnage(ip, op2);
  return;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string ip = "ab";
  string op = "";
  PermutatonCaseChnage(ip, op);
  cout << endl;
  return 0;
}
