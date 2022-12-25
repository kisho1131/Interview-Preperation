#include <bits/stdc++.h>
using namespace std;

string str;
/* ========== YOUR CODE START HERE ========= */
void reverseArray(int arr[], int st, int ed) {
  if (st >= ed) {
    return;
  }
  // cout << st << "->" << ed << endl;
  swap(arr[st], arr[ed]);
  reverseArray(arr, ++st, --ed);
}

bool palindrome(string str, int st, int ed) {
  if (st >= ed) {
    return true;
  }
  return str[st] == str[ed] and palindrome(str, ++st, --ed);
}

// void printSubsequence(string str, int n) {}
void GenerateParenthesis(string &str, int open, int close) {
  if (open == 0 && close == 0) {
    cout << str;
  }

  if (open > 0) {
    str.push_back('(');
    GenerateParenthesis(str, open - 1, close);
    str.pop_back();
  }

  if (close > 0) {
    if (open < close) {
      str.push_back(')');
      GenerateParenthesis(str, open, close - 1);
      str.pop_back();
    }
  }
}

void PrintAllSubsetString(string str, string op, int itr, int n) {
  if (itr == n) {
    cout << op << " ";
    return;
  }
  string op1 = op;
  string op2 = op;
  op1.push_back(str[itr]);
  PrintAllSubsetString(str, op1, itr + 1, n);
  PrintAllSubsetString(str, op2, itr + 1, n);
}

void Permutation(string str, int left, int right, set<string> &ans) {
  if (left >= right) {
    ans.insert(str);
    return;
  }

  for (int i = 0; i <= right; i++) {
    // Do the changes
    swap(str[left], str[i]);
    // Recursion
    Permutation(str, left + 1, right, ans);
    // BackTrack or Undo
    swap(str[left], str[i]);
  }
}

/* Generate all the Sequence for the given N \
Eg: N = 2 ; O/P -> '12', '21'
*/
void solve(int n, int idx, vector<int> &arr) {
  if (idx == n) {
    for (auto ele : arr) {
      cout << ele << "";
    }
    cout << endl;
    return;
  }

  for (int i = idx; i < n; i++) {
    swap(arr[i], arr[idx]);
    solve(n, idx + 1, arr);
    swap(arr[i], arr[idx]);
  }
}
void AllPermutation(int n) {
  // vector<int>ds;
  //  vetor<vector<int>>ans;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  // for (auto ele : arr)
  //   cout << ele << " ";
  // cout << endl;
  solve(n, 0, arr);
}

bool isPalindrome(string s, int st, int ed) {
  while (st <= ed) {
    if (s[st++] != s[ed--])
      return false;
  }
  return true;
}
void solvePartation(int idx, string str, vector<string> &path) {
  if (idx == str.size()) {
    for (auto ch : path) {
      cout << ch << ",";
    }
    cout << endl;
    return;
  }

  for (int i = idx; i < str.length(); i++) {
    if (isPalindrome(str, idx, i)) {
      path.push_back(str.substr(idx, i - idx + 1));
      solvePartation(i + 1, str, path);
      path.pop_back();
    }
  }
}
void palindromePartation(string str) {
  vector<string> path;
  int idx = 0;
  solvePartation(0, str, path);
}

bool PalindromeFunction(string str, int st, int ed) {
  if (st > ed)
    return true;
  return str[st] == str[ed] and PalindromeFunction(str, st + 1, ed - 1);
}

void PowerSet(vector<int> arr, vector<int> &ds, int idx) {
  if (idx == arr.size()) {
    for (auto ele : ds) {
      cout << ele << ",";
    }
    cout << endl;
    return;
  }

  // pick
  ds.push_back(arr[idx]);
  PowerSet(arr, ds, idx + 1);
  ds.pop_back();

  // not pick
  PowerSet(arr, ds, idx + 1);
}

/* ========== YOUR CODE END HERE ========= */

/* ========== Main Function ============== */
int main() {
  vector<int> arr = {1, 2, 3, 4};
  vector<int> ds;
  PowerSet(arr, ds, 0);
  return 0;
}
