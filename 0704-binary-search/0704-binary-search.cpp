class Solution {
public:
    int search(vector<int>& nums, int target) {
        return bs(nums, 0, nums.size()-1, target);
    }
    
    int bs(vector<int>& nums, int l, int h, int target){
        if(l > h) return -1;
        
        int m = (l+h)/2;
        if(nums[m]==target) return m;
        else if(target > nums[m]) return bs(nums, m+1, h, target);
        else return bs(nums, l, m-1, target);
    }
};