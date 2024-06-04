class Solution {
public:
    
    void printC(int index, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[index] <= target){
            ds.push_back(candidates[index]);
            printC(index, target - candidates[index], candidates, ans, ds);
            ds.pop_back();
        }
        
        printC(index+1, target, candidates, ans, ds);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        printC(0, target, candidates, ans, ds);
        return ans;
    }
};