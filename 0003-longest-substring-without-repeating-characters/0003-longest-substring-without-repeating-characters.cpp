class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> d;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (d.count(s[right]) == 0 || d[s[right]] < left) {
                d[s[right]] = right;
                ans = max(ans, right - left + 1);
            } else {
                left = d[s[right]] + 1;
                d[s[right]] = right;
            }
        }
        return ans;
    }
};