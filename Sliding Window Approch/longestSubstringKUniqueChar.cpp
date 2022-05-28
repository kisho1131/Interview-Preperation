#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int longestSubstringKUniqueChar(string str, int k) {
  map<char, int> mp;
  int j = 0;
  int i = 0;
  int maxLen = INT_MIN;
  while (j < str.length()) {
    mp[str[j]]++;
    if (mp.size() == k)
      maxLen = max(maxLen, (j - i + 1));
    else if (mp.size() > k) {
      while (mp.size() > k) {
        mp[str[i]]--;
        if (mp[str[i]] == 0)
          mp.erase(str[i]);
        i++;
      }
    }
    j++;
  }
  return maxLen;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string str = "aabacbebebe";
  int k = 3;
  cout << longestSubstringKUniqueChar(str, k);
  cout << endl;
  return 0;
}
