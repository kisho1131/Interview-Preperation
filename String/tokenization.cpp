#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

vector<string> Tokenization(string input) {
  stringstream ss(input);
  string token;
  vector<string> tokens;
  while (getline(ss, token, 'm')) {
    tokens.push_back(token);
  }
  return tokens;
}

/* Own Implemention of strtok function */
char *MyStrtok(char *str, char delim) {
  static char *input = NULL;
  if (str != NULL)
    input = str;
  if (input == NULL)
    return NULL;
  static char *token = new char[strlen(input) + 1];
  int i = 0;
  for (; input[i] != '\0'; i++) {
    if (input[i] != delim)
      token[i] = input[i];
    else {
      token[i] = '\0';
      input = input + i + 1;
      return token;
    }
  }
  token[i] = '\0';
  input = NULL;
  return token;
}

void Tokenization_Mystrtok(char input[]) {
  char *token = MyStrtok(input, ' ');
  while (token != NULL) {
    cout << token << ",";
    token = MyStrtok(NULL, ' '); /* strtok() maintain the state of the fn() call
                                  using static varibale */
  }
}

/* strtok() (String Tokinize for to) */
void Tokenization_Strtok(char input[]) {
  char *token = strtok(input, " ");
  while (token != NULL) {
    cout << token << ",";
    token = strtok(NULL, " "); /* strtok() maintain the state of the fn() call
                                  using static varibale */
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string input;
  getline(cin, input);
  vector<string> tokens = Tokenization(input);
  for (auto token : tokens)
    cout << token << ",";
  cout << endl;
  char input1[10000];
  cin.getline(input1, 10000);
  Tokenization_Mystrtok(input1);
  return 0;
}
