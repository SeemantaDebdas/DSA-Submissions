class Solution {
public:

    int FindPath(int m, int n, vector<vector<int>> &dp)
    {
        int count = 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];

        if(m == 0 && n == 0)
        {
            dp[m][n] = 1;
            return 1;
        }


        if(m > 0)
            count += FindPath(m - 1, n, dp);
        if(n > 0)
            count += FindPath(m, n - 1, dp);
        
        dp[m][n] = count;
        return count;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m, vector<int>(n, -1));
        return FindPath(m - 1, n - 1, dp);
    }
};