#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
double MedianArray(vector<int> A, vector<int> B) {
  if (A.size() > B.size()) {
    vector<int> temp = A;
    A = B;
    B = temp;
  }
  int n = A.size();
  int m = B.size();
  int size = n + m;
  double median = 0.0;
  int start = 0;
  int end = n;
  while (start <= end) {
    int aLeft = start + (end - start) / 2;
    int bLeft = (size + 1) / 2 - aLeft;
    int alm1 = (aLeft == 0) ? INT_MIN : A[aLeft - 1];
    int al = (aLeft == n) ? INT_MAX : A[aLeft];
    int blm1 = (bLeft == 0) ? INT_MIN : B[bLeft - 1];
    int bl = (bLeft == 0) ? INT_MAX : B[bLeft];
    // Valid segration
    if (alm1 <= bl && blm1 <= al) {
      if (size % 2 == 0) {
        int leftMax = max(alm1, blm1);
        int rightMin = max(al, bl);
        median = (leftMax + rightMin) / 2.0;
      } else {
        median = max(alm1, blm1);
      }
      return median;
    }
    // More element of array B is needed
    else if (alm1 > bl) {
      end = aLeft - 1;
    }
    // More element of array A is needed
    else if (blm1 > al) {
      start = aLeft + 1;
    }
  }
  return median;
}

/*
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    int m = B.size();
    if (n > m)
        return findMedianSortedArrays(B, A); // Swapping to make A smaller

    int start = 0;
    int end = n;
    int realmidinmergedarray = (n + m + 1) / 2;

    while (start <= end) {
        int mid = (start + end) / 2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA
            = (leftAsize > 0)
                  ? A[leftAsize - 1]
                  : INT_MIN; // checking overflow of indices
        int leftB
            = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
        int rightA
            = (leftAsize < n) ? A[leftAsize] : INT_MAX;
        int rightB
            = (leftBsize < m) ? B[leftBsize] : INT_MAX;

        // if correct partition is done
        if (leftA <= rightB and leftB <= rightA) {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB)
                        + min(rightA, rightB))
                       / 2.0;
            return max(leftA, leftB);
        }
        else if (leftA > rightB) {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return 0.0;
}

*/


/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {1, 5, 7, 8, 11, 15, 16, 18, 19};
  vector<int> brr = {2, 4, 6, 9, 17};
  double median = MedianArray(arr, brr);
  cout << median;
  cout << endl;
  return 0;
}
