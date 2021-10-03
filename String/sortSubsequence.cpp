#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void GenerateSubsequence(string s, string o, vector<string> &v) {
  if (s.length() == 0) {
    v.push_back(o);
    return;
  }
  char ch = s[0];
  string reduced_string = s.substr(1);
  GenerateSubsequence(reduced_string, o + ch, v);
  GenerateSubsequence(reduced_string, o, v);
}

bool compare(string s1, string s2) {
  if (s1.length() == s2.length())
    return s1 < s2;
  return s1.length() < s2.length();
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string s = "abcd";
  string o = "";
  vector<string> v;
  GenerateSubsequence(s, o, v);
  sort(v.begin(), v.end(), compare);
  for (auto ch : v) {
    cout << ch << " ";
  }
  cout << endl;
  return 0;
}
