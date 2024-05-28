class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long l = 0, r = 0, sum = 0, maxf = 1;
        while(r < nums.size()){
            sum += nums[r];
            if ((r - l + 1) * nums[r] - sum > k){
                sum -= nums[l];
                l++;
            }
            if((r - l + 1) * nums[r] - sum <= k){
                maxf = max(maxf, r-l+1);
            }
            r++;
        }
        return maxf;
    }
};