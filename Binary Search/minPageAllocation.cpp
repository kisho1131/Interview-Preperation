#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

bool isPossible(int *arr, int maxPage, int n, int k) {
  if (k > n) // k ->no of student to which the book is allocated
    return false;
  int student = 1;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (sum > maxPage) {
      student++;
      sum = arr[i]; //  Here we add new student, hence the current sum of pages
                    //  will be equal to arr[i];
    }
    if (student > k)
      return false;
  }
  return true;
}

int minPageAllocation(int *arr, int n, int m) {
  int start = *max_element(arr, arr + n);
  int end = 0;
  for (int i = 0; i < n; i++)
    end += arr[i];
  int res = -1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (isPossible(arr, mid, n, m)) {
      end = mid - 1;
      res = mid;
    } else
      start = mid + 1;
  }
  return res;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {12, 34, 67, 90};
  int n = sizeof(arr) / sizeof(int);
  int m = 2;
  cout << minPageAllocation(arr, n, m);
  cout << endl;
  return 0;
}

/* Similar Questions --> To be Solved
---------------------------------------
Book Allocation Problem (GFG)
Aggressive cow (spoj)
Prata and roti (spoj)
EKO (spoj)
Painter Partition Problem
Google kickstart A Q-3 2020

LeetCode:
---------
1482 Minimum Number of Days to Make m Bouquets
1283 Find the Smallest Divisor Given a Threshold
1231 Divide Chocolate
1011 Capacity To Ship Packages In N Days
875 Koko Eating Bananas Minimize
774 Max Distance to Gas Station
410 Split Array Largest Sum

*/
