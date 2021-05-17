/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int N = height.size();
        int left = 0, right = N - 1;
        int sum = 0;
        int max_left = 0, max_right = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] > max_left)
                {
                    max_left = height[left];
                }
                else
                {
                    sum += max_left - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] > max_right)
                {
                    max_right = height[right];
                }
                else
                {
                    sum += max_right - height[right];
                }
                right--;
            }
        }
        return sum;
    }
};
// @lc code=end
