#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here =============*/

int convertToInt(string s) {
  int pow = 1;
  int ans = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    ans += (s[i] - '0') * pow;
    pow = pow * 10;
  }
  return ans;
}


bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
  string key1 = s1.first;
  string key2 = s2.first;

  return convertToInt(key1) < convertToInt(key2);
}

bool lexocioCompare(pair<string, string> s1, pair<string, string> s2) {
  string key1 = s1.first;
  string key2 = s2.first;

  return (key1) < (key2);
}

string ExtractString(string str, int key) {
  char *s = strtok((char *)str.c_str(), " ");
  /* string.c_str() give the underlying character array for the string
   * Represention */

while (key > 1) {
    s = strtok(NULL, " ");
    key--;
  }
  return s;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {

  int n;
  cin >> n;
  cin.get();
  string temp;
  vector<string> v;
  for (int i = 0; i < n; i++) {
    getline(cin, temp);
    v.push_back(temp);
  }
  int key;
  string reversal, ordering;
  cin >> key >> reversal >> ordering;

  vector<pair<string, string>> vp;
  for (int i = 0; i < n; i++) {
    vp.push_back({v[i], ExtractString(v[i], key)});
  }

  if (ordering == "numeric")
    sort(vp.begin(), vp.end(), numericCompare);
  else
    sort(vp.begin(), vp.end(), lexocioCompare);

  if (reversal == "true")
    reverse(vp.begin(), vp.end());

  for (int i = 0; i < n; i++) {
    cout << vp[i].first << " ";
    cout << endl;
  }

  cout << endl;
  return 0;
}
