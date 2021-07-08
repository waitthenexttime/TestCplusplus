/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> LeftMax(n);
        vector<int> RightMax(n);
        int Max;
        // 该数到左边界的最大值
        for (int i = 0; i < n; i++)
        {
            if (i % k == 0)
            {
                Max = INT_MIN;
            }
            Max = max(Max, nums[i]);
            LeftMax[i] = max(Max, nums[i]);
        }
        // 该数到右边界的最大值
        Max = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            if ((i + 1) % k == 0)
            {
                Max = INT_MIN;
            }
            Max = max(Max, nums[i]);
            RightMax[i] = max(Max, nums[i]);
        }
        vector<int> ans;
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            ans.push_back(max(RightMax[i], LeftMax[j]));
        }
        return ans;
    }
};
// @lc code=end
