/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // key=元素值, value=出现频率
        unordered_map<int, int> counts;
        int maxCount = 0;
        for (int num : nums)
        {
            maxCount = max(maxCount, ++counts[num]); // 找到最大的频率
        }
        vector<vector<int>> buckets(maxCount + 1); // 以出现频率为桶个数
        for (auto p : counts)
        {
            buckets[p.second].push_back(p.first);
        }
        vector<int> ans;
        for (int i = maxCount; i > 0 && ans.size() < k; --i)
        {
            for (int num : buckets[i])
            {
                ans.push_back(num);
                if (ans.size() == k)
                {
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
