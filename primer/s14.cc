#include<string>
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

bool isCommonPrefix(vector<string> strs, int len) {
    string str1 = strs[0].substr(0, len);
    for (string::size_type i = 1; i < strs.size(); i++)
        if (strs[i].find(str1) != 0)
            return false;
    return true;
}

// binary search
string longestCommonPrefix(vector<string>& strs) {
    if (strs.size()==0)
        return "";
    int minLen = INT_MAX;
    for (string str : strs)
        minLen = min(minLen, (int)str.size());
    int low = 1;
    int high = minLen;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (isCommonPrefix(strs, middle))
            low = middle + 1;
        else
            high = middle - 1;
    }
    return strs[0].substr(0, (low + high) / 2);
}



void s14() {
    vector<string> strs = { "chiale","chial","chiam" };
    cout << longestCommonPrefix(strs) << endl;
}