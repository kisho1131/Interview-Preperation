#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
string convert_to_digital_time(int minutes) {
  // complete this function
  if (minutes > 24 * 60)
    return "Invalid Date Format";
  int hr = minutes / 60;
  int minu = minutes - (hr * 60);
  string hrs = to_string(hr);
  string minus = to_string(minu);
  if (minus.length() == 1)
    minus = "0" + minus;
  string ans = hrs + ":" + minus;
  return ans;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int minutes;
  cin >> minutes;
  cout << convert_to_digital_time(minutes);
  cout << endl;
  return 0;
}
