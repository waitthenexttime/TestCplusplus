/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;
        while (x)
        {
            int pop = x % 10;
            if (rev > INT_MAX / 10 || rev == INT_MAX / 10 && pop > 7)
            {
                return 0;
            }
            if (rev < INT_MIN / 10 || rev == INT_MIN / 10 && pop < -8)
            {
                return 0;
            }
            x /= 10;
            rev = rev*10+pop;
        }
        return rev;
    }
};
// @lc code=end
