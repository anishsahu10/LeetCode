class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (subarraysWithAtmostKDistinct(nums, k) - subarraysWithAtmostKDistinct(nums, k-1));
    }
    
private: 
    int subarraysWithAtmostKDistinct(vector<int>& nums, int k){
        unordered_map <int,int> m;
        int l=0, r=0, count=0;
        while(r<nums.size()){
            m[nums[r]]++;
            while(m.size() > k){
                m[nums[l]]--;
                if(m[nums[l]] == 0){
                    m.erase(nums[l]);
                }
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
};
