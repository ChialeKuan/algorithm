#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<int> buildNext(string P) {
    int lenP = P.size();
    vector<int> next(lenP,0);
    int k = next[0] = -1;
    int j = 0;
    while (j < lenP - 1) {
        if (k < 0 || P[k] == P[j]) {
            k++;
            j++;
            next[j] = k;
        }
        else {
            k = next[k];
        }
    }
    return next;

}
int match(string T, string P) {
    int lenT = T.size(), lenP = P.size();
    vector<int> next = buildNext(P);
    int i = 0, j = 0;
    while (i < lenT && j < lenP) {
        if (j < 0 || T[i] == P[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }
    if (j < lenP)
        return -1;
    else 
        return i - j;
}


void a3() {
    string t = "acabaabaabcacaabc";
    string p = "abaabca";
    cout << match(t, p) << endl;
}