class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxf = 0, maxlen = 0;
        map <char,int> mpp;
        while(r < s.size()){
            mpp[s[r]]++;
            maxf = max(maxf, mpp[s[r]]);
            if((r-l+1) - maxf > k){
                mpp[s[l]]--;
                l++;
            }
            if((r-l+1) - maxf <= k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};