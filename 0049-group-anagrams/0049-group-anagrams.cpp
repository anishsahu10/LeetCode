class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        
        for(auto s : strs){
            string t = s;
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto value : m){
            ans.push_back(value.second);
        }
        
        return ans;
    }
};