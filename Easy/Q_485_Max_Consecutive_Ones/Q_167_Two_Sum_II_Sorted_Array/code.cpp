class Solution
{
public:
 int findMaxConsecutiveOnes(vector<int> &nums)
 {
  int left = 0;
  int right = 0;

  for (int i = 0; i < nums.size(); i++)
  {
   if (nums[i] == 1)
   {
    left++;
   }
   else
   {
    left = 0;
   }

   right = max(right, left);
  }
  return right;
 }
};