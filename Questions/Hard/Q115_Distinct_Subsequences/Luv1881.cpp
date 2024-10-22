class Solution {
public:
    //Time Complexity: O(n*m)
    //Space Complexity: O(m)

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        // dp[j] will store the number of distinct subsequences of t[0...j-1] in s.
        vector<double> dp(m + 1, 0);
        
        // Base case: an empty string t can be found in any string s as one distinct subsequence.
        dp[0] = 1;
        
        // Iterate through each character of string s
        for (int i = 1; i <= n; i++) {
            // Traverse dp array from right to left to ensure the current row is updated
            // without interfering with the updates for previous characters.
            for (int j = m; j >= 1; j--) {
                // If the current characters of s and t match, we add the number of ways
                // to form the first j-1 characters of t (dp[j-1]) to the number of ways
                // to form the first j characters (dp[j]) without considering the current character.
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j - 1] + dp[j];
                }
            }
        }
        
        // The result will be stored in dp[m], which gives the number of distinct subsequences
        // of the entire string t in string s.
        return (int)dp[m];
    }
};
