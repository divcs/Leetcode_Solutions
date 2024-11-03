class Solution {
public:
//traverse from last and find the such that arr[i]<arr[i+1] let then that i = a
// traverse again find first element from such that arr[i] > arr[a] and swap both indices
//reverse everything after a

    void swap(vector<int> &arr,int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    void reverse(vector<int> &arr,int i, int j){
        while(i<j){
            swap(arr,i++,j--);
        }
    }
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while(i >=0 && nums[i] >= nums[i+1]) i--;
        if(i>=0){
        int j = nums.size()-1;

        while(nums[j] <= nums[i]) j--;
        swap(nums,i,j);
        }
        reverse(nums,i+1,nums.size()-1);
    }
};