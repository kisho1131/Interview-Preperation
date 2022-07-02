#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int countOccuranceAnagram(string word, string pattern) {
  unordered_map<char, int> mp;
  for (auto ch : pattern) {
    mp[ch]++;
  }

  int k = pattern.size();
  int count = mp.size();
  int i = 0;
  int j = 0;
  int ans = 0;
  while (j < word.length()) {
    if (mp.find(word[j]) != mp.end()) {
      mp[word[j]]--;
      if (mp[word[j]] == 0)
        count--;
    }
    if ((j - i + 1) < k)
      j++;
    else if ((j - 1 + 1) == k) {
      if (count == 0)
        ans++;
      if (mp.find(word[i]) != mp.end()) {
        mp[word[i]]++;
        if (mp[word[i]] == 1)
          count++;
      }
      i++;
      j++;
    }
  }
  return ans;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string s = "ababababababc";
  string ana = "ab";
  cout << countOccuranceAnagram(s, ana);
  return 0;
}
