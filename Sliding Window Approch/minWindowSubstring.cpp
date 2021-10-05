#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

/* Leetcode [76]: Given two strings s and t of lengths m and n respectively,
 * return the minimum window substring of s such that every character in t
 * (including duplicates) is included in the window. If there is no such
 * substring, return the empty string "". */

string MinWindowSubstring(string str, string k) {
  map<char, int> mp;
  int j = 0;
  int i = 0;
  int minLen = INT_MAX;
  for (auto ch : k)
    mp[ch]++;
  int count = mp.size();
  while (j < str.length()) {
    if (mp.find(str[j]) != mp.end()) {
      mp[str[j]]--;
      if (mp[str[j]] == 0)
        count--;
      j++;
    } else
      j++;
    if (count == 0) {
      while (count == 0) {
        // cout << minLen << endl;
        minLen = min(minLen, (j - i));
        // cout << j - i + 1 << " ";
        if (mp.find(str[i]) == mp.end())
          i++;
        else if (mp.find(str[i]) != mp.end()) {
          mp[str[i]]++;
          if (mp[str[i]] > 0)
            count++;
          i++;
        }
      }
    }
  }
  string ans = str.substr(i - 1, j);
  /* j is not included in substr method & i is included */
  return ans;
}

string MinWindowSubstring_(string str, string k) {
  map<char, int> mp;
  for (auto ch : k)
    mp[ch]++;
  int start = 0, end = 0, count = k.size(), minLen = INT_MAX, minStart = 0;
  while (end < str.length()) {
    if (mp[str[end]] > 0) // if the current char is present in the map
      count--;
    mp[str[end]]--; //  Reduce the count if char is present in the hashmap, if
                    //  not present the count of that character become negative
    end++;

    while (count == 0) {
      if (end - start < minLen) {
        minStart = start;
        minLen = end - start;
      }
      mp[str[start]]++;
      if (mp[str[start]] > 0)
        count++;
      start++;
    }
  }
  if (minLen != INT_MAX)
    return str.substr(minStart, minLen);
  return "";
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string str = "ADOBECODEBANC";
  string k = "ABC";
  cout << str.length() << endl;
  cout << MinWindowSubstring_(str, k);
  cout << endl;
  return 0;
}
