/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        for (int first = 0; first < N - 2; first++)
        {
            if (nums[first] > 0)
            {
                return ans;
            }
            // first去重
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            int second = first + 1;
            int third = N - 1;
            while (second < third)
            {
                if (nums[first] + nums[second] + nums[third] > 0)
                {
                    third--;
                }
                else if (nums[first] + nums[second] + nums[third] < 0)
                {
                    second++;
                }
                else
                {
                    ans.push_back({nums[first], nums[second], nums[third]});
                    second++;
                    third--;
                    // second去重
                    while (second < third && nums[second] == nums[second - 1])
                    {
                        second++;
                    }
                    //third去重
                    while (third > second && nums[third] == nums[third + 1])
                    {
                        third--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
