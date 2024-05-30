class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size()>threshold) return -1; //if the answer is impossible.
        int l = 1, r = *max_element (nums.begin(), nums.end());
        int ans;
        while(l<=r){
            int m = (l+r)/2;
            int sum = totalSum(nums, m);
            if(sum<=threshold){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
    
    int totalSum(vector<int>& nums, int mid){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += ceil((double)nums[i]/(double)mid);
        }
        return sum;
    }
};