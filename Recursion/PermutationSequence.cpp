#include <bits/stdc++.h>
using namespace std;
/* ========== YOUR CODE START HERE ========= */
void helper(string &str, int n, int k, int st) {
  if (st == n + 1) {
    cout << str << " ";
    return;
  }
  char ch = st + '0';
  str.push_back(ch);
  helper(str, n, k, ++st);
  str.pop_back();
}

// string getPermutation(int n, int k) {
//     string str = "";
//     int st = 1;
// }
/* ========== YOUR CODE END HERE ========= */

/* ========== Main Function ============== */
int main() {
  int n = 3;
  int k = 2;
  int st = 1;
  string str = "";
  helper(str, n, k, st);
  cout << endl;
  return 0;
}
