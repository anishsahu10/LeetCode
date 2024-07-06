//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int mod = 1e9 + 7;
    
    long long int memoization(int n, vector<long long int> &dp){
        if(n<=1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (memoization(n-1,dp) + memoization(n-2, dp))%mod;
    }
    
    long long int topDown(int n) {
        vector<long long int> dp(n+1,-1);
        return memoization(n,dp);
    }
    long long int bottomUp(int n) {
        int prev1 = 1, prev2 = 0;
        for(int i = 2; i<n+1; i++){
            int curr = (prev1 + prev2)%mod;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends