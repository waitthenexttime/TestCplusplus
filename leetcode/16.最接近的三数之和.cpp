/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int N = nums.size();
        int s = 10000;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < N - 2; first++)
        {
            int second = first + 1;
            int third = N - 1;
            while (second < third)
            {
                int tmps = nums[first] + nums[second] + nums[third];
                s = abs(target - tmps) < abs(target - s) ? tmps : s;
                if (tmps > target)
                {
                    third--;
                }
                else if (tmps < target)
                {
                    second++;
                }
                else
                {
                    return target;
                }
            }
        }
        return s;
    }
};
// @lc code=end
