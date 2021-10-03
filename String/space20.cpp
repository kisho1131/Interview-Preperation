/* Given a String Replace all the spaces with the %20 */
#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void ReplaceSapce(char *str) {
  int spaces = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ')
      spaces++;
  }
  int index = strlen(str) + 2 * spaces;
  str[index] = '\0';
  for (int i = strlen(str) - 1; i >= 0; i--) {
    if (str[i] == ' ') {
      str[index - 1] = '0';
      str[index - 2] = '2';
      str[index - 3] = '%';
      index -= 3;
    } else {
      str[index - 1] = str[i];
      index--;
    }
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  char input[10000];
  cin.getline(input, 10000);
  ReplaceSapce(input);
  cout << input;

  cout << endl;
  return 0;
}
