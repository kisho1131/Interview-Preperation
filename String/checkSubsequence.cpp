#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
bool CheckSubsequence(string s1, string s2) {
  int i = s1.length() - 1;
  int j = s2.length() - 1;
  while (i >= 0 and j >= 0) {
    if (s1[i] == s2[j]) {
      i--;
      j--;
    } else {
      i--;
    }
  }
  if (j == -1)
    return true;
  return false;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string s1 = "condingminutes";
  string s2 = "zdgmtes";
  if (CheckSubsequence(s1, s2))
    cout << "Subsequence";
  else
    cout << "Not Subsequence";
  cout << endl;
  return 0;
}
