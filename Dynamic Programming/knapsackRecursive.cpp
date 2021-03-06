#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int KnapSack(int wt[], int val[], int w, int n) {
  if (n == 0 || w == 0)
    return 0;
  if (wt[n - 1] <= w)
    return max(val[n - 1] + KnapSack(wt, val, w - wt[n - 1], n - 1),
               KnapSack(wt, val, w, n - 1));
  else
    return KnapSack(wt, val, w, n - 1);
}


/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int W = 50;
  int n = sizeof(val) / sizeof(val[0]);
  cout << KnapSack(wt, val, W, n);
  cout << endl;
  return 0;
}
