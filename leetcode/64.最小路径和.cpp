/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[0] = grid[0][0];
                }
                else if (i == 0)
                {
                    dp[j] = dp[j - 1] + grid[0][j];
                }
                else if (j == 0)
                {
                    dp[0] = dp[0] + grid[i][0];
                }
                else
                {
                    dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
                }
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end
