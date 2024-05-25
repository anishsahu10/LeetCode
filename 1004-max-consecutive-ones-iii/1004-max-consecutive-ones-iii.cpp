class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r = 0, l = 0, maxlen = 0, z = 0;
        while(r < nums.size()){
            if(nums[r] == 0){
                z++;
            }
            if(z > k){
                if(nums[l] == 0){
                    z--;
                }
                l++;
            }
            if(z <= k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};