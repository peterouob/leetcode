#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> track;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int> &nums, int start)
    {
        res.push_back(nums);
        for (int i = start; i < nums.size(); i++)
        {
            track.push_back(nums[i]);
            backtrack(nums, i + 1);
            track.pop_back();
        }
    }
};