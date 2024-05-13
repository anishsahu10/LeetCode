class Solution {
public:
    int maxArea(vector<int>& height) {
        int prod;
        int ans = INT_MIN;
        int i = 0;
        int j = height.size()-1;
        
        while(i<j){
            prod = min(height[i],height[j]) * (j-i);
            ans = max(prod,ans); 
            
            if(height[i]<height[j]){
                i++;
            }
            else j--;
        }
        return ans;
    }
};