class Solution {
public:
    int countSA(vector<int>& nums, int maxSum){
        int subArr = 1, sum = 0;
        for(int i = 0; i<nums.size(); i++){
            if(sum + nums[i]<=maxSum) sum += nums[i];
            else{
                subArr++;
                sum = nums[i];
            }
        }
        return subArr;
    }
    
    
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
        int ans = -1;
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);
        
        while(l<=h){
            int m = (l+h)/2;
            int noOfSA = countSA(nums, m);
            if(noOfSA == k){
                ans = m;
                h = m-1;
            }
            else if(noOfSA > k) l = m+1;
            else h = m-1;
        }
        return l;
    }
};