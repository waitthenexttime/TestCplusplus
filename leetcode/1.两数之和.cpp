/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++)
        {
            int cut = target - nums[i];
            auto it = hashtable.find(cut);
            if (it != hashtable.end())
            {
                return {it->second, i};
            }
            else
            {
                hashtable[nums[i]] = i;
            }
        }
        return {};
    }
};
// @lc code=end
