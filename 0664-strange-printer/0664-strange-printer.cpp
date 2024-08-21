class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        // Base case: Single character
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        // Fill the dp table
        for (int len = 2; len <= n; ++len) { // Length of the substring
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                
                // Case 1: Print s[i]...s[j] in one turn if s[i] == s[j]
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                }
                
                // Case 2: Try splitting the substring at every possible position
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};
