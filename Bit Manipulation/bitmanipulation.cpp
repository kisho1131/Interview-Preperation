#include <bits/stdc++.h>
using namespace std;
/* ========== YOUR CODE START HERE ========= */
void solution() {
  int n;
  cin >> n;
  if (n & 1)
    cout << "odd";
  else
    cout << "Even";
  cout << endl;
  // check the set bit
  int i = 1;
  if (n & (1 << i) != 0)
    cout << "Set";
  else
    cout << "Not Set";
}
/* ========== YOUR CODE END HERE ========= */

/* ========== Main Function ============== */
int main() {
  solution();
  cout << endl;
  return 0;
}
