class Solution {
public:
    //Time Complexity: O(N)
    //Space Complexity: O(1)
    
    // Function to calculate trapped water given the height of bars
    int trap(vector<int>& height) {
        // Initialize two pointers, 'l' starting from the left and 'r' from the right
        int l = 0, r = height.size() - 1;
        
        // Initialize 'maxl' and 'maxr' to track the maximum height encountered from the left and right respectively
        int maxl = height[l], maxr = height[r];
        
        // Variable to store the total amount of trapped water
        int water = 0;
        
        // Continue until the two pointers meet
        while (r > l) {
            // If the maximum height on the left is greater than the maximum height on the right
            if (maxl > maxr) {
                // Move the right pointer one step to the left
                r--;
                // Update the maximum height encountered from the right
                maxr = max(maxr, height[r]);
                // Calculate the trapped water at the current position on the right
                water += maxr - height[r];
            } else {
                // Move the left pointer one step to the right
                l++;
                // Update the maximum height encountered from the left
                maxl = max(maxl, height[l]);
                // Calculate the trapped water at the current position on the left
                water += maxl - height[l];
            }
        }
        // Return the total trapped water
        return water;
    }
};
