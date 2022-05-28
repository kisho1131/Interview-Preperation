#include <bits/stdc++.h>
using namespace std;
int minWindowSubstring(string str, string p) {
  if (p.length() > str.length())
    return -1;
  unordered_map<char, int> mp;
  for (auto ch : p)
    mp[ch]++;
  int ans = INT_MAX;
  int i = 0;
  int j = 0;
  int count = mp.size();

  while (j < str.length()) {
    if (mp.find(str[j]) != mp.end()) {
      mp[str[j]]--;
      if (mp[str[j]] == 0)
        count--;
    }

    if (count > 0)
      j++;

    else if (count == 0) {
      ans = min(ans, j - i + 1);
      while (count == 0) {
        if (mp.find(str[i]) == mp.end()) {
          i++;
          ans = min(ans, j - i + 1);
        } else {
          mp[str[i]]++;
          if (mp[str[i]] > 0) {
            i++;
            count++;
          } else {
            i++;
            ans = min(ans, j - i + 1);
          }
        }
      }
      j++;
    }
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  string str = "ADOBECODEBANC";
  string p = "ABC";
  int ans = minWindowSubstring(str, p);
  cout << ans;
  return 0;
}
