#include<iostream>
#include<vector>
#include<algorithm>

#define DEBUG

using namespace std;



void search(vector<vector<int>>& r, vector<int>& saved, vector<int>& candidates, int n, int target){
    /*
    r result
    saved saved result
    candidates as in the question
    n place
    target
    */
#ifdef DEBUG
    cout << "n=" << n << " target=" << target << " ";
    cout << "v=[";
    for (int i : saved)
        cout << i << " ";
    cout << "]" << endl;
#endif

    if (target == 0) {
        // 匹配了
        if (saved.empty() == false)
            r.push_back(saved);
        return;
    }
    if (n >= candidates.size()) // 数量太大
        return;
 

    int candidate = candidates[n];
    int nSameCnt = 1;
    while (n + 1 < candidates.size() && candidates[n + 1] == candidates[n])
        nSameCnt++, n++;
    int i;
    for (i = 0; i < nSameCnt+1; i++){
        // 若 nSameCnt == 1
        // 那么要么选0或者1个
        int next_target = target - i * candidate;
        if (next_target < 0)
            break;
        search(r, saved, candidates, n + 1, next_target);
        saved.push_back(candidate);
    }

    while (i-- > 0)
        saved.pop_back();
}

vector<vector<int>> combinationSum2_1(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> r;
    vector<int> v;
    search(r, v, candidates, 0, target);
    return r;
}

// 更简洁
vector<vector<int>> res;

void combineDFS(vector<int>  &candidates, int target, vector<int> out, int begin) {
    if (target == 0) {
        res.push_back(out);
    }
    else {
        int i = begin;
        while (i < candidates.size()) {
            int tar = target - candidates[i];
            if (tar < 0) {
                out.pop_back();
                break;
            }
            else {
                out.push_back(candidates[i]);
                combineDFS(candidates, tar, out, i + 1);
                i++;
                while (i >= 1 && candidates[i] == candidates[i - 1]) i++;
                out.pop_back();
            }
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> out;
    combineDFS(candidates, target, out, 0);
    return res;
}

void s40() {
    vector<int> a = { 1,1,2,5,6,7,10 };
    int target = 8;
    vector<vector<int>> res = combinationSum2(a, target);
    for (vector<int> i : res) {
        for (int j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

}