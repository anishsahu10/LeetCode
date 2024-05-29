//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    map<int,int> mpp;
	    for(int i =0; i<n; i++){
	        mpp[arr[i]] = i;
	    }
	    
	    return mpp[findMin(arr, n)];
	}
	
	int findMin(int arr[], int n) {
        int l = 0, h = n-1, ans = INT_MAX;
        while(l<=h){
            int m = (l+h)/2;
            if(arr[l]<=arr[m]){
                ans = min(ans,arr[l]);
                l = m+1;
            }
            else{
                ans = min(ans,arr[m]);
                h = m-1;
            }
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends