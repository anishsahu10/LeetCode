class Solution {
public:
    
    void printC(int index, int s, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds){
        if(index == candidates.size()){
            if(s == target){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[index] <= (target - s)){
            ds.push_back(candidates[index]);
            s += candidates[index];
            printC(index, s, target, candidates, ans, ds);
            s -= candidates[index];
            ds.pop_back();
        }
        printC(index+1, s, target, candidates, ans, ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int s = 0;
        printC(0, s, target, candidates, ans, ds);
        return ans;
    }
};