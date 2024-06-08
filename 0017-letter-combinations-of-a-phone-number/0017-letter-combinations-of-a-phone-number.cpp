class Solution {
public:
    
    vector<string> solve(string digits, map<int, string>& numpad, vector<string>& ans){
        if(digits.size() == 0) return {};
        ans.push_back("");
        
        for(auto digit : digits){
            vector<string> temp;
            for(auto alphabet : numpad[digit-'0']){
                for(auto s : ans){
                    temp.push_back(s + alphabet);
                }
            }
            ans.swap(temp);
            
        }
        return ans;
    }
    
    vector<string> letterCombinations(string digits) {
        map<int, string> numpad = {{2,"abc"}, {3,"def"}, {4,"ghi"}, {5,"jkl"}, {6,"mno"}, {7,"pqrs"}, {8, "tuv"}, {9,"wxyz"}};
        vector<string> ans;
        vector<string> answer = solve(digits, numpad, ans);
        return answer;
    }
};