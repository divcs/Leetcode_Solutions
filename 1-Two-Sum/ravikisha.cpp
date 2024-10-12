class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> umap;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            int pairNum = target - nums[i];
            if (umap.find(pairNum) != umap.end())
            {
                return {umap[pairNum], i};
            }
            umap.insert(pair<int, int>(nums[i], i));
        }
        return {-1, -1};
    }
};