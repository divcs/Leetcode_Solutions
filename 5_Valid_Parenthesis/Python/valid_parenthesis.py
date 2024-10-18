class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []  # Initialize an empty stack
        bracket_map = {
            ")": "(",
            "}": "{",
            "]": "[",
        }  # Mapping of closing to opening brackets
        opening_brackets = set(
            bracket_map.values()
        )  # Set of opening brackets for fast lookup

        for char in s:
            if char in opening_brackets:  # If it's an opening bracket
                stack.append(char)  # Push onto stack
            elif char in bracket_map:  # If it's a closing bracket
                if (
                    not stack or stack.pop() != bracket_map[char]
                ):  # Check for matching with one condition
                    return False  # Invalid

        return not stack  # Ensure all opening brackets are closed
