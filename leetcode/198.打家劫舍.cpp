/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        int p = nums[0];
        int q = max(nums[0], nums[1]);
        int cur;
        for (int i = 2; i < n; i++)
        {
            cur = max(p + nums[i], q);
            p = q;
            q = cur;
        }
        return cur;
    }
};
// @lc code=end
