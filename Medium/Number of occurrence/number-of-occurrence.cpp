//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int lb = lowerBound(arr, n, x);
        if(lb == n || arr[lb] != x){
            return 0;
        }
        int ub = upperBound(arr, n, x)-1;
        return (ub-lb+1);
    }
    
    int lowerBound(int arr[], int n, int x) {
        
        int l = 0, h = n-1, ans = n;
        
        while(l<=h){
            long long m = (l+h)/2;
            if(arr[m]>=x){
                ans = m; //maybe the answer or maybe not.
                h = m-1;
            }
            else l = m+1;
        }
        return ans;
        
    }
    
    int upperBound(int arr[], int n, int x) {
        
        int l = 0, h = n-1, ans = n;
        
        while(l<=h){
            long long m = (l+h)/2;
            if(arr[m]>x){
                ans = m; //maybe the answer or maybe not.
                h = m-1;
            }
            else l = m+1;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends