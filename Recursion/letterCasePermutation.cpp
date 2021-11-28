#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void LetterCasePermutation(string ip, string op) {
  if (ip.length() == 0) {
    cout << op << " ";
    return;
  }
  if (isalpha(ip[0])) {
    string op1 = op;
    string op2 = op;
    op1.push_back(tolower(ip[0]));
    op2.push_back(toupper(ip[0]));
    ip.erase(ip.begin() + 0);
    LetterCasePermutation(ip, op1);
    LetterCasePermutation(ip, op2);
  } else {
    string op1 = op;
    op1.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    LetterCasePermutation(ip, op1);
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string ip = "a1b2";
  string op = "";
  LetterCasePermutation(ip, op);
  cout << endl;
  return 0;
}
