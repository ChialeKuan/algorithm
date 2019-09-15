#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, const char* argv[]) {
  string input;
  while (cin >> input) {
    stack<string::size_type> s;
    string output(input.size(), ' ');
    for (auto i = 0; i != input.size(); ++i) {
      if (input[i] == '(') {
        s.push(i);
      } else if (input[i] == ')') {
        if (s.empty()) {
          output[i] = '?';
        } else {
          s.pop();
        }
      }
    }
    while (!s.empty()) {
      output[s.top()] = '$';
      s.pop();
    }
    cout << input << endl << output << endl;
  }
  return 0;
}