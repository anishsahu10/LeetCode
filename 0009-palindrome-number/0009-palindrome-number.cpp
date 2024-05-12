class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long revN = 0;
        int ld;

        if(x<0){
            return false;
        }

        while(x>0){
            ld = x % 10;
            revN = (revN*10) + ld;
            x = x/10;
        }
        return revN == temp;
    }
};