#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 10;
vector<bool> is_prime(N + 1, 1);
vector<int> higest_prime(N);
vector<int> lowest_prime(N);
/* ========== YOUR CODE START HERE ========= */
/*
Seive is used to Find the all the Prime number inside the range [1,n] in
O(N*log log n) time and O(N) Space Complexijty
*/
void PrimeSeive(int n) {
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i < n; i++)
    if (is_prime[i] and (long long) i * i <= n)
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
}

void SeivePrimeFactor(int n) {
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i < n; ++i) {
    if (is_prime[i]) {
      for (int j = 2 * i; j <= n; j += i) {
        is_prime[j] = 0;
        higest_prime[j] = i;
        if (lowest_prime[j] == 0)
          lowest_prime[j] = i;
      }
    }
  }
}
/* ========== YOUR CODE END HERE ========= */

/* ========== Main Function ============== */
int main() {
  int n;
  cin >> n;
  SeivePrimeFactor(n);
  for (int i = 0; i < n; i++) {
    if (is_prime[i])
      cout << i << " ";
  }
  cout << endl;
  return 0;
}
