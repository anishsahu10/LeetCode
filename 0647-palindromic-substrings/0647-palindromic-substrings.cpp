class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            int evenS = pCount(s, i, i+1);
            int oddS = pCount(s, i, i);
            ans = ans + evenS + oddS;
        }
        return ans;
    }
    
        int pCount(const string &s, int left, int right){
        int count = 0;
        while(left>=0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
            count++;
        }
        return count;
    }
    
};