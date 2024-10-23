#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
 vector<vector<int>> threeSum(vector<int> &nums)
 {
  vector<vector<int>> result;     // To store the unique triplets
  sort(nums.begin(), nums.end()); // Sort the array

  // Iterate over the array
  for (int i = 0; i < nums.size(); i++)
  {
   // If the current element is greater than 0, stop the loop because no three numbers can sum to 0
   if (nums[i] > 0)
    break;

   // Skip duplicates for the first element
   if (i > 0 && nums[i] == nums[i - 1])
    continue;

   // Two-pointer approach for finding pairs
   int left = i + 1;
   int right = nums.size() - 1;
   while (left < right)
   {
    int sum = nums[i] + nums[left] + nums[right];

    // If the sum is zero, we found a triplet
    if (sum == 0)
    {
     result.push_back({nums[i], nums[left], nums[right]});
     left++;
     right--;

     // Skip duplicates for the second and third elements
     while (left < right && nums[left] == nums[left - 1])
      left++;
     while (left < right && nums[right] == nums[right + 1])
      right--;
    }
    // If the sum is less than zero, move the left pointer to increase the sum
    else if (sum < 0)
    {
     left++;
    }
    // If the sum is greater than zero, move the right pointer to decrease the sum
    else
    {
     right--;
    }
   }
  }

  return result;
 }
};

int main()
{
 Solution sol;
 vector<int> nums = {-1, 0, 1, 2, -1, -4};
 vector<vector<int>> result = sol.threeSum(nums);

 // Print the result
 for (const auto &triplet : result)
 {
  cout << "[";
  for (int num : triplet)
  {
   cout << num << " ";
  }
  cout << "]" << endl;
 }

 return 0;
}
