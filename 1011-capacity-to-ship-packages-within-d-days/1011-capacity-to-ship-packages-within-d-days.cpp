class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element (weights.begin(), weights.end()), h = accumulate(weights.begin(), weights.end(), 0);
        int ans;
        while(l<=h){
            int m = (l+h)/2;
            int noOfDays = totalDays(weights, m);
            if(noOfDays<=days){
                ans = m;
                h = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
    
    int totalDays(vector<int>& weights, int capacity){
        int d = 1, load = 0;
        for(int i=0; i<weights.size(); i++){
            load += weights[i];
            if(load>capacity){
                d++;
                load = weights[i];
            }
        }
        return d;
    }
};