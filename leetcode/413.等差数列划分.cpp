/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int count = 0;
        for (int s = 0; s < nums.size() - 2; s++)
        {
            int d = nums[s + 1] - nums[s];
            for (int e = s + 2; e < nums.size(); e++)
            {
                int i = 0;
                for (i = s + 1; i <= e; i++)
                {
                    if (nums[i] - nums[i - 1] != d)
                    {
                        break;
                    }
                }
                if (i > e)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end
