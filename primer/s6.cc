#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

// o(n)
string convert_1(string s, int numRows) {

    if (numRows == 1) return s;

    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    string ret;
    for (string row : rows) ret += row;
    return ret;
}

// o(n)
// 直接根据数学结果算出来
string convert(string s, int numRows) {

    if (numRows == 1) return s;

    string ret;
    int n = s.size();
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
        // 元素是大循环
        for (int j = 0; j + i < n; j += cycleLen) {
            ret += s[j + i];
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                ret += s[j + cycleLen - i]; // 这个也是需要收入的元素
        }
    }
    return ret;
}
void s6() {
    cout << convert("abcdefg", 3) << endl;
}