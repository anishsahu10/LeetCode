class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0, l=0, r=0;
        unordered_map<char,int> m;
        for(r=0; r<s.size(); r++){
            m[s[r]]++;
            while(m['a'] && m['b'] && m['c']){
                count += s.size() - r;
                m[s[l]]--;
                l++;
            }
        }
        return count;
    }
};