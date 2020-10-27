/*
 * @Description: leetcode 1
 * @Author: Chiale
 * @Date: 2019-09-16 10:24:40
 * @LastEditTime: 2020-10-26 20:22:35
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> indices;
    for (int i = 0; i != nums.size(); ++i) indices[nums[i]] = i;

    for (int i = 0; i != nums.size(); ++i) {
        int left = target - nums[i];
        if (indices.count(left) && indices[left] != i) {
            return {i, indices[left]};
        }
    }
    return {-1, -1};
}

// O(n^2)
vector<int> twoSum_1(vector<int>& nums, int target) {
    for (int i = 0; i != nums.size(); ++i) {
        for (int j = i + 1; j != nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main() {
    int n;
    int num;
    int target;
    vector<int> nums;
    nums.reserve(10);
    vector<int> res;
    while (cin >> n) {
        nums.clear();
        for (int i = 0; i != n; ++i) {
            cin >> num;
            nums.push_back(num);
        }
        cin >> target;
        res = twoSum(nums, target);
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}
