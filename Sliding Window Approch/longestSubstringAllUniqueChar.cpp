#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

/* Given the String Str find the length of the longest Substring Without any
 * Repeating Character => (i.e) Find the Substring with all Unique Char */

int longestSubstringKUniqueChar(string str) {
  map<char, int> mp;
  int j = 0;
  int i = 0;
  int maxLen = 0;
  while (j < str.length()) {
    mp[str[j]]++;
    if (mp.size() < (j - i + 1)) {
      while (mp.size() < j - i + 1) {
        mp[str[i]]--;
        if (mp[str[i]] == 0)
          mp.erase(str[i]);
        i++;
      }
    } else if (mp.size() == (j - i + 1)) {
      maxLen = max(maxLen, (j - i + 1));
    }
    j++;
  }
  return maxLen;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string str = "abaabcdef";
  cout << longestSubstringKUniqueChar(str);
  cout << endl;
  return 0;
}
