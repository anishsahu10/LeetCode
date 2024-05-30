class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size()>h) return -1; //if the answer is impossible.
        int l = 1, r = *max_element (piles.begin(), piles.end());
        int ans;
        while(l<=r){
            int m = (l+r)/2;
            long long totalH = timeTaken(piles, m);
            if(totalH<=h){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
    
    long long timeTaken(vector<int>& piles, int mid){
        long long totalH = 0;
        for(int i=0; i<piles.size(); i++){
            totalH += ceil((double)piles[i]/(double)mid);
        }
        return totalH;
    }
};