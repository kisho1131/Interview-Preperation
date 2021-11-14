#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void TOH(char S, char D, char H, int n) {
  if (n == 1) {
    cout << "Moving " << n << " From " << S << " to " << D << endl;
    return;
  }
  TOH(S, H, D, n - 1);
  cout << "Moving " << n << " From " << S << " to " << D << endl;
  TOH(H, D, S, n - 1);
  cout << "Moving " << n << " From " << S << " to " << D << endl;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  TOH('S', 'D', 'H', n);
  cout << endl;
  return 0;
}
