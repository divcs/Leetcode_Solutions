class Solution {
public:
    //Time Complexity: O(n * m * log(m)) 
    //Space Complexity: O(n * m) 
    vector<vector<pair<int, int>>> preprocessTop3(vector<vector<int>>& points) {
        // Initialize a 2D vector 'top3' where each row will store the top 3 elements of the corresponding row from 'points'.
        vector<vector<pair<int, int>>> top3(points.size(), vector<pair<int, int>>(3, {-1, -1}));

        // Iterate over each row of 'points'.
        for (int i = 0; i < points.size(); ++i) {
            vector<pair<int, int>> elements; // Stores pairs of (value, column index) for each element in the row.

            // Iterate over each element in the row.
            for (int j = 0; j < points[0].size(); ++j) {
                elements.push_back({points[i][j], j}); // Store value and its column index.
            }

            // Sort elements in descending order by value to get the top 3 largest elements.
            sort(elements.rbegin(), elements.rend());

            // Copy the top 3 elements (or fewer if the row has less than 3 elements) into 'top3'.
            for (int k = 0; k < 3 && k < elements.size(); ++k) {
                top3[i][k] = {elements[k].second, elements[k].first}; // Store (column index, value).
            }
        }

        // Return the processed 'top3' vector.
        return top3;
    }

    //Time Complexity: O(n * m^2 * 3) 
    //Space Complexity: O(n * m^2 * 4) 
    long long solve(vector<vector<pair<int, int>>>& top3, int row, int col1, int col2, int k, vector<vector<vector<vector<long long>>>>& dp) {
        // Base case: If we've processed all rows and k elements have been chosen.
        if (row >= top3.size()) {
            if (k == 0) {
                return 0; // If exactly k elements have been chosen, return 0 (base case success).
            }
            return -1e18; // If k elements haven't been chosen, return a very negative value (invalid state).
        }

        // If this state has been computed before, return the cached result from the DP table.
        if (dp[row][col1 + 1][col2 + 1][k] != -1) {
            return dp[row][col1 + 1][col2 + 1][k];
        }

        long long ans = -1e18; // Initialize answer to a very negative value.

        // Try selecting one of the top 3 elements from the current row.
        for (int i = 0; i < 3; ++i) {
            int currentCol = top3[row][i].first; // Column of the current element.
            long long currentValue = top3[row][i].second; // Value of the current element.

            if (currentCol == -1) continue; // Skip if there's no valid element in this position.

            // Check if the current element can be selected without violating the constraints (no overlap in columns).
            if (k == 3 || (k == 2 && currentCol != col1) || (k == 1 && currentCol != col1 && currentCol != col2)) {
                // Recur to the next row, updating the column positions and decrementing k.
                long long sP = solve(top3, row + 1, k == 3 ? currentCol : col1, k == 2 ? currentCol : col2, k - 1, dp);

                // Update the answer if a valid solution was found.
                if (sP != -1e18) {
                    ans = max(ans, sP + currentValue);
                }
            }
        }

        // Recur without selecting any element from the current row.
        long long sP = solve(top3, row + 1, col1, col2, k, dp);
        if (sP != -1e18) {
            ans = max(ans, sP);
        }

        // Cache the result in the DP table and return the answer.
        return dp[row][col1 + 1][col2 + 1][k] = ans;
    }

    //Time Complexity: O(n * m * log(m) + n * m^2 * 3) 
    //Space Complexity: O(n * m^2 * 4) 
    long long maximumValueSum(vector<vector<int>>& board) {
        int n = board.size(); // Number of rows.
        int m = board[0].size(); // Number of columns.

        // Preprocess to get the top 3 elements for each row.
        vector<vector<pair<int, int>>> top3 = preprocessTop3(board);

        // DP table to store the results of subproblems.
        vector<vector<vector<vector<long long>>>> dp(n, vector<vector<vector<long long>>>(m + 1, vector<vector<long long>>(m + 1, vector<long long>(4, -1))));

        // Start solving from the first row, no columns chosen, and k = 3 elements to choose.
        return solve(top3, 0, -1, -1, 3, dp);
    }
};
