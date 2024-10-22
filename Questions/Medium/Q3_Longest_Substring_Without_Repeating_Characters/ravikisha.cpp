class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> charIndex; // To store the last index of each character
        int maxLength = 0, start = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (charIndex.find(s[i]) != charIndex.end() && charIndex[s[i]] >= start)
            {
                // If the character is already in the map and is in the current window
                start = charIndex[s[i]] + 1; // Move the start pointer after the duplicate
            }
            charIndex[s[i]] = i;                       // Update the index of the current character
            maxLength = max(maxLength, i - start + 1); // Update the maximum length
        }

        return maxLength;
    }
};