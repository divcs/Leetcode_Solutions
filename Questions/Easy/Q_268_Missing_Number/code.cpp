#include <iostream>
#include <vector>

int missingNumber(const std::vector<int> &nums)
{
 int n = nums.size();
 int expectedSum = n * (n + 1) / 2; // Calculate expected sum from 0 to n
 int actualSum = 0;

 // Calculate the actual sum of numbers in the array
 for (int num : nums)
 {
  actualSum += num;
 }

 // The missing number is the difference between expected and actual sum
 return expectedSum - actualSum;
}

int main()
{
 std::vector<int> nums1 = {3, 0, 1};
 std::cout << "Missing number: " << missingNumber(nums1) << std::endl; // Output: 2

 std::vector<int> nums2 = {0, 1};
 std::cout << "Missing number: " << missingNumber(nums2) << std::endl; // Output: 2

 std::vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
 std::cout << "Missing number: " << missingNumber(nums3) << std::endl; // Output: 8

 return 0;
}