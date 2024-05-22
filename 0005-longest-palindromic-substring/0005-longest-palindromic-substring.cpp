class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        for(int i = 0; i<s.size(); i++){
            string even = pString(s, i, i+1);
            string odd = pString(s, i, i);
            if(even.size() > odd.size() && max(even.size(), odd.size()) > ans.size()){
                ans = even;
            }
            else if(even.size()<odd.size() && max(even.size(), odd.size()) > ans.size()){
                ans = odd;
            }
        }
        return ans;
    }
    
    string pString(const string &s, int left, int right){
        string pal;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            pal = s.substr(left, right - left+1);
            left--;
            right++;
        }
        return pal;
    }
};