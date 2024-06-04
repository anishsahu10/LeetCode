class Solution {
public:
    
    void printS(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans){
        if(index == nums.size()){
            ans.push_back(ds);
            return;
        }
        //picking the element
        ds.push_back(nums[index]);
        printS(index+1, nums, ds, ans);
        ds.pop_back();
        
        //not picking the element
        printS(index+1, nums, ds, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        printS(0, nums, ds, ans);
        return ans;
    }
};