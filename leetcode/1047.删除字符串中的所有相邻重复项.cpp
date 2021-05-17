/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string stk;
        for (auto it : s)
        {
            if (!stk.empty() && it == stk.back())
            {
                stk.pop_back();
            }
            else
            {
                stk.push_back(it);
            }
        }
        return stk;
    }
};
// @lc code=end
