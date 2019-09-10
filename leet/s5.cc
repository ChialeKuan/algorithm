#include<iostream>
#include<string>
#include<vector>

using namespace std;

// ������չ
// o��n^2)
int expandAroundCenter(string s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L - 1;
}

string longestPalindrome_1(string s) {

    if (s.length() <= 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i); // bab
        int len2 = expandAroundCenter(s, i, i + 1); // bbaabb
        int len = (len1 > len2) ? len1 : len2;
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
}


// ��̬�滮
// o(n^2)
string longestPalindrome_2(string s) {
    int n = s.length();
    int start = 0, end = 0;
    vector<vector<bool> > pal(n, vector<bool>(n));
    //pal[i][j] ��ʾs[i...j]�Ƿ��ǻ��Ĵ�
    int maxLen = 0;
    for (int i = 0; i < n; i++)  // i��Ϊ�յ�
        for (int j = i; j != 0; j--) // j ��Ϊ���
            if (s[j] == s[i] && (i - j < 2 || pal[j + 1][i - 1])) {
                pal[j][i] = true;
                if (i - j + 1 > maxLen) {
                    maxLen = i - j + 1;
                    start = j;
                }
            }
    return s.substr(start, maxLen);
}


// o(n)
string longestPalindrome(string s) {
    int n = s.length();
    int start = 0, end = 0;
    vector<vector<bool> > pal(n, vector<bool>(n));
    //pal[i][j] ��ʾs[i...j]�Ƿ��ǻ��Ĵ�
    int maxLen = 0;
    for (int i = 0; i < n; i++)  // i��Ϊ�յ�
        for (int j = i; j != 0; j--) // j ��Ϊ���
            if (s[j] == s[i] && (i - j < 2 || pal[j + 1][i - 1])) {
                pal[j][i] = true;
                if (i - j + 1 > maxLen) {
                    maxLen = i - j + 1;
                    start = j;
                }
            }
    return s.substr(start, maxLen);
}



void s5() {
    cout << longestPalindrome("abcbcbde") << endl;
}