class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = *min_element (bloomDay.begin(), bloomDay.end());
        int h = *max_element (bloomDay.begin(), bloomDay.end());
        int ans = -1;
        
        while(l<=h){
            int mid = (l+h)/2;
            if(possible(bloomDay, mid, m, k)){
                ans = mid;
                h = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
    
    bool possible(vector<int>& bloomDay, int mid, int m, int k){
        int count = 0; 
        int noOfB = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=mid) count++;
            else{
                noOfB += (count/k);
                count = 0;
            }
        }
        noOfB += (count/k);
        if(noOfB >= m) return true;
        else return false;
    }
};