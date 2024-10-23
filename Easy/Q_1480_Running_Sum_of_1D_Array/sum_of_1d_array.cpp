// Time Complexity: O(N)
// Space Complexity:O(1)
// in both cases

// in-place changes: OPTIMIZED
#include <vector>
using namespace std;

class Solution
{
public:
 vector<int> runningSum(vector<int> &nums)
 {
  for (int i = 1; i < nums.size(); i++)
  {
   nums[i] += nums[i - 1]; // Update nums in-place
  }
  return nums; // Return the modified input vector
 }
};

// sum of array using another array
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
 vector<int> runningSum(vector<int> &sums)
 {
  int n = sums.size();
  vector<int> results(n);
  if (n == 0)
   return results; // return empty if input is empty

  results[0] = sums[0];

  for (int i = 1; i < n; i++)
  {
   results[i] = results[i - 1] + sums[i];
  }
  return results;
 }
};

int main()
{
 Solution solution;
 vector<int> nums = {1, 2, 3, 4};
 vector<int> result = solution.runningSum(nums);

 for (int num : result)
 {
  cout << num << " ";
 }
 return 0;
}