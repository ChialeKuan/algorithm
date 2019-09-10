/*
 * @Description: delete a small string from a long string
 * case insensitive
 * by using the stl string
 * @Author: Chiale
 * @Date: 2019-09-08 16:45:29
 * @LastEditTime: 2019-09-08 19:00:41
 */

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[]) {
  string text;
  string temp;
  string pattern;

  // getline 会读入换行符，所以第一个不能为 cin>>（不删除换行符）
  getline(cin, pattern);
  while (getline(cin, text)) {
    temp = text;
    for (int i = 0; i != temp.size(); ++i) {
      temp[i] = tolower(temp[i]);
    }
    auto loc = temp.find(pattern, 0);
    while (loc != string::npos) {
      temp.erase(loc, pattern.size());
      text.erase(loc, pattern.size());
      loc = temp.find(pattern, loc);
    }

    loc = temp.find(' ', 0);
    while (loc != string::npos) {
      text.erase(loc, 1);
      loc = text.find(' ', loc);
    }
    cout << text << endl;
  }
  return 0;
}
