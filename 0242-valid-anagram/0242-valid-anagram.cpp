class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int ans = s.compare(t);
        if(ans != 0){
            return false;
        }
        else{
            return true;
        }
    }
};