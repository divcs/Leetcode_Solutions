#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
 void sortColors(vector<int> &nums)
 {
  class Solution
  {
  public:
   void sortColors(vector<int> &nums)
   {
    for (int i = 0; i < nums.size(); i++)
    {
     for (int j = i + 1; j < nums.size(); j++)
     {
      if (nums[i] > nums[j])
      {
       // swapping
       nums[i] = nums[i] + nums[j];
       nums[j] = nums[i] - nums[j];
       nums[i] = nums[i] - nums[j];
      }
     }
    }
   }
  };
 }
};

int main()
{
 Solution solution;
 vector<int> nums = {2, 0, 2, 1, 1, 0};
 solution.sortColors(nums);

 for (int i = 0; i < nums.size(); i++)
 {
  cout << nums[i] << " ";
 }

 return 0;
}