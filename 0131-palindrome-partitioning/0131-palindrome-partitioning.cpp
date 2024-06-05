class Solution {
public:
    
    bool isPalindrome(int l, int r, string s){
        while(l<=r){
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
    
    void palSubStr(int index, string s, vector<string>& ds, vector<vector<string>>& ans){
        if(index == s.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i = index; i<s.size(); i++){
            if(isPalindrome(index, i, s)){
                ds.push_back(s.substr(index, i-index+1));
                palSubStr(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> ans;
        palSubStr(0, s, ds, ans);
        return ans;
    }
};