#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */
void print1toN(int n) {
  if (n == 1) {
    cout << n << " ";
    return;
  }
  cout << n << " ";
  print1toN(n - 1);
}

/* Sort the Element in the Array using Recursion */

void insertElement(vector<int> &arr, int last_ele) {
  if (arr.size() == 0 || arr[arr.size() - 1] >= last_ele) {
    arr.push_back(last_ele);
    return;
  }
  int lastval = arr[arr.size() - 1];
  arr.pop_back();
  insertElement(arr, last_ele);
  arr.push_back(lastval);
}

void sortArray(vector<int> &arr) {
  if (arr.size() == 1)
    return;
  int last_ele = arr[arr.size() - 1];
  arr.pop_back();
  sortArray(arr);
  insertElement(arr, last_ele);
}

void DeleteMiddleElementFromStack(stack<int> st, int k) {
  if (st.empty())
    return;
  if (k == 1) {
    st.pop();
    return;
  }
  int val = st.top();
  st.pop();
  DeleteMiddleElementFromStack(st, k - 1);
  st.push(val);
}

void insertElementinStack(stack<int> st, int ele) {
  if (st.empty()) {
    st.push(ele);
    return;
  }
  int val = st.top();
  st.pop();
  insertElementinStack(st, ele);
  st.push(val);
}

void ReverseStack(stack<int> st) {
  if (st.empty())
    return;
  int val = st.top();
  st.pop();
  ReverseStack(st);
  insertElementinStack(st, val);
}

void PrintSubset(string ip, string op) {
  if (ip.length() == 0) {
    cout << op << " ";
    return;
  }
  string op1 = op;
  string op2 = op;
  op1.push_back(ip[0]);
  ip.erase(ip.begin() + 0);
  PrintSubset(ip, op1);
  PrintSubset(ip, op2);
  return;
}
/* =========================== Main() =========================== */
int main() {
  // print1toN(10);
  // vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  // sortArray(arr);
  // for (auto ele : arr)
  //   cout << ele << " --> ";
  // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
  // stack<int> s;
  // for (auto ele : arr)
  //   s.push(ele);
  // int k = s.size() / 2 + 1;
  // DeleteMiddleElementFromStack(s, k);
  // while (s.size() != 0) {
  //   cout << s.top() << " ";
  //   s.pop();
  // }
  string ip = "abc";
  string op = "#";
  PrintSubset(ip, op);
  cout << endl;
  return 0;
}
