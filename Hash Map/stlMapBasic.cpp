#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  map<char, int> mp;
  string str = "sumit";
  for (auto ch : str)
    mp[ch]++;
  cout << mp.size() << endl;
  for (auto i = mp.begin(); i != mp.end(); i++) {
    cout << i->first << " " << i->second << endl;
  }
  char ch = 'z';
  cout << mp[ch];
  cout << endl;
  return 0;
}
