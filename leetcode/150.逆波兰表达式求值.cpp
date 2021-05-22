/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        unordered_map<string, int> Hash =
            {
                {"+", 1},
                {"-", 2},
                {"*", 3},
                {"/", 4}};
        for (auto it : tokens)
        {
            if (Hash.count(it))
            {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                int tmp;
                switch (Hash[it])
                {
                case 1:
                    tmp = a + b;
                    break;
                case 2:
                    tmp = a - b;
                    break;
                case 3:
                    tmp = a * b;
                    break;
                case 4:
                    tmp = a / b;
                    break;
                default:
                    break;
                }
                stk.push(tmp);
            }
            else
            {
                stk.push(stoi(it));
            }
        }
        return stk.top();
    }
};
// @lc code=end
