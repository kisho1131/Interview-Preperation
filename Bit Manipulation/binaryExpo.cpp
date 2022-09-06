#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
/* ========== YOUR CODE START HERE ========= */
long long binaryExpo(long long a, long long b) {
  int ans = 1;
  int itr = 1;
  while (b) {
    cout << endl;
    cout << itr << " iteration" << endl;
    cout << "-------------" << endl;
    cout << "Before Value = " << a << endl;
    if (b & 1)
      ans = (ans * a);
    cout << "ans = " << ans << endl;
    a = (a * a);
    cout << "After value 'a' = " << a << endl;
    b = b >> 1;
    ++itr;
  }
  return ans;
}

long long binaryExpoRecursive(long long a, long long b) {
  if (b == 0)
    return 1;
  long long res = binaryExpoRecursive(a, b / 2);
  if (b & 1)
    return (a * (res * 1LL * res) % M) % M;
  else
    return (res * 1LL * res) % M;
}
/* ========== YOUR CODE END HERE ========= */

/* ========== Main Function ============== */
int main() {
  long long a = 3;
  long long b = 13;
  cout << binaryExpo(a, b) << endl;
  //  cout << binaryExpoRecursive(a, b);
  cout << endl;
  return 0;
}
