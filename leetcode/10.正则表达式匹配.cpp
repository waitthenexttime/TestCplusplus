/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        auto its = s.begin();
        auto itp = p.begin();
        while (itp != p.end())
        {
            if (*itp == *its || *itp == '.')
            {
                cout << "*its == *itp" << endl;
                itp++;
                its++;
                continue;
            }
            if (*its != *itp)
            {
                cout << "*its != *itp" << endl;
                // s = "aab" p = "c*a*b"
                if (*(itp + 1) == '*')
                {
                    its++;
                    itp += 2;
                }
                // s = "aa" p = "a*"
                else if (*itp == '*')
                {
                    cout << "in" << endl;
                    while (*its == *(its - 1) || *(itp - 1) == '.')
                    {
                        cout << "A" << endl;
                        its++;
                    }
                    itp++;
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return its == s.end() ? true : false;
    }
};
// @lc code=end
