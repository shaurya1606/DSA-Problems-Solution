class Solution {
public:

    int solve(string &s, int i, int j, vector<vector<int>> &dp) {
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if(i >= j) {
            return 0;
        }

        else if(s[i] == s[j]) {
            return dp[i][j] = 0 + solve(s, i+1, j-1, dp);
        }

        return dp[i][j] = 1 + min(solve(s, i, j-1, dp), solve(s, i+1, j, dp));
    }

    int minInsertions(string s) {
        int i = 0;
        int n = s.size();
        int j = s.size() - 1;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(s, i, j, dp);
    }
};