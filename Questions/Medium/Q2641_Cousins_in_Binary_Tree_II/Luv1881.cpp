class Solution {
public:
    //Time Complexity: O(n)
    //Space Complexity: O(h)
    TreeNode* replaceValueInTree(TreeNode* root) {
        // Step 1: Initialize the root value to 0
        root->val = 0;

        // Step 2: Start the DFS traversal with the root node wrapped in a vector
        dfs(std::vector<TreeNode*>{root});

        // Step 3: Return the modified root of the tree
        return root;
    }

private:
    // Depth-First Search (DFS) function that operates on a level of nodes in the tree
    void dfs(std::vector<TreeNode*> arr) {
        // Base case: If the current level is empty, return
        if (arr.empty()) return;

        // Step 4: Calculate the sum of the values of all child nodes of the current level
        int sum = 0;
        for (auto node : arr) {
            if (!node) continue; // Skip null nodes
            if (node->left) sum += node->left->val;  // Add left child's value to sum
            if (node->right) sum += node->right->val; // Add right child's value to sum
        }

        // Step 5: Prepare for the next level of nodes (children of the current nodes)
        std::vector<TreeNode*> childArr;

        // Step 6: Update each child node’s value and prepare them for the next level
        for (auto node : arr) {
            int curSum = 0; // Current sum of the left and right children

            // Calculate the sum of the current node's left and right child
            if (node->left) curSum += node->left->val;
            if (node->right) curSum += node->right->val;

            // Update left child’s value if it exists
            if (node->left) {
                node->left->val = sum - curSum;  // Set left child’s value to total sum minus current sum
                childArr.push_back(node->left);  // Add left child to the next level's list
            }

            // Update right child’s value if it exists
            if (node->right) {
                node->right->val = sum - curSum; // Set right child’s value to total sum minus current sum
                childArr.push_back(node->right); // Add right child to the next level's list
            }
        }
        // Step 7: Recursively process the next level (children of the current nodes)
        dfs(childArr);
    }
};
