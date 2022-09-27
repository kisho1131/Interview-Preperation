#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
/* ========== YOUR CODE START HERE ========= */
long long binaryExpoRecursive(int a, int b) {
  if (b == 0)
    return 1;
  int res = binaryExpoRecursive(a, b / 2);
  if (b & 1)
    return a * res * res;
  else
    return res * res;
}

long long binaryExpoIterative(int a, int b) {
  if (b == 0)
    return 1;
  int ans = 1;
  while (b) {
    if (b & 1)
      ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

// Binary Exponenation using Binary Multiplication
long long binaryMultiplication(int a, int b) {
  int ans = 0;
  while (b) {
    /* code */
    if (b & 1)
      ans = (ans + a) % M;
    a = (a + a) % M;
    b >>= 1;
  }
  return ans;
}

long long binaryExp(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1)
      ans = binaryMultiplication(ans, a);
    a = binaryMultiplication(a, a);
    b >>= 1;
  }
  return ans;
}

/* ========== YOUR CODE END HERE ========= */

/* ========== Main Function ============== */
int main() {
  int a, b;
  cin >> a >> b;
  cout << binaryExp(a, b);
  cout << endl;
  return 0;
}
