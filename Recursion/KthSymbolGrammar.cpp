#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

/* LeetCode 779. K-th Symbol in Grammar */

int KthSymbolGrammar(int n, int k) {
  if (n == 1 && k == 1)
    return 0;
  int mid = pow(2, n - 1) / 2;
  if (k <= mid)
    return KthSymbolGrammar(n - 1, k);
  else
    return !KthSymbolGrammar(n - 1, k - mid);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n = 3, k = 1;
  cout << KthSymbolGrammar(n, k);
  cout << endl;
  return 0;
}
