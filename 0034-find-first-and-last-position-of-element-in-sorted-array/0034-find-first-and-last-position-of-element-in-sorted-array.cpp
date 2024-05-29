class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2);
        int lb = lowerBound(nums, target);
        if(lb == nums.size() || nums[lb] != target){
            v[0] = -1;
            v[1] = -1;
            return v;
        }
        int ub = upperBound(nums, target);
        v[0] = lb;
        v[1] = ub-1;
        return v;
    }
    
    int lowerBound(vector<int>& nums, int target) {
        
        int l = 0, h = nums.size()-1, ans = nums.size();
        
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m]>=target){
                ans = m; //maybe the answer or maybe not.
                h = m-1;
            }
            else l = m+1;
        }
        return ans;
        
    }
    
    int upperBound(vector<int>& nums, int target) {
        
        int l = 0, h = nums.size()-1, ans = nums.size();
        
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m]>target){
                ans = m; //maybe the answer or maybe not.
                h = m-1;
            }
            else l = m+1;
        }
        return ans;
        
    }
};