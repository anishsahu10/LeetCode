class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int brk = -1;
        for(int i = nums.size()-2 ; i>=0; i--){
            if(nums[i]<nums[i+1]){
                brk = i;
                break;
            }
        }
        if(brk == -1){
            reverse(nums.begin(),nums.end());
            return nums;
        }
        for(int i = nums.size()-1; i>brk; i--){
            if(nums[i]>nums[brk]){
                swap(nums[i],nums[brk]);
                break;
            }
        }
        reverse(nums.begin()+brk+1, nums.end());
        return nums;
    }
};