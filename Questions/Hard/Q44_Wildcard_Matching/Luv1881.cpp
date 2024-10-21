//Time Complexity: O(n * m)
//Space Complexity: O(n * m)
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        // Create a DP table to store match results for substrings of 's' and 'p'.
        // dp[i][j] will be true if the first i characters of 's' match the first j characters of 'p'.
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        // Base case: An empty string matches an empty pattern.
        dp[0][0] = true;
        
        // Handle cases where the pattern starts with '*' characters.
        // '*' can match any sequence of characters, including an empty sequence.
        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-1];  // '*' can act as an empty sequence, so carry over previous value.
            }
        }
        
        // Fill the DP table for substrings of 's' and 'p'.
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If characters match or the pattern has a '?', it's a match.
                if (p[j-1] == s[i-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];  // Match current characters and check previous ones.
                } 
                // If the pattern has a '*', it can match zero or more characters.
                else if (p[j-1] == '*') {
                    // '*' can either match the current character from 's' (dp[i-1][j]) 
                    // or ignore the current character from 'p' (dp[i][j-1]).
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                } 
                // Otherwise, it's not a match.
                else {
                    dp[i][j] = false;
                }
            }
        }
        
        // The result is stored in dp[n][m], which tells whether the entire string 's' matches the pattern 'p'.
        return dp[n][m];
    }
};
