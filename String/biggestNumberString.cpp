#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
bool compare(string s1, string s2) {
  if (s1.length() < s2.length())
    return true;
  return s1 > s2;
}

void BiggestNumberString(vector<int> num) {
  vector<string> v;
  for (int i = 0; i < num.size(); i++) {
    v.push_back(to_string(num[i]));
  }
  sort(v.begin(), v.end(), compare);
  string ans = "";
  for (auto ele : v) {
    ans = ans + ele;
  }
  cout << ans;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> num = {10, 11, 20, 30, 3};
  BiggestNumberString(num);
  cout << endl;
  return 0;
}
