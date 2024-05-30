//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    int l = 1, h = m;
	    while(l<=h){
	        int mid = (l+h)/2;
	        if(NthPower(mid, n, m) == 1) return mid;
	        else if(NthPower(mid, n, m) == 0) h = mid-1;
	        else l = mid+1;
	    }
	    return -1;
	}
	
	int NthPower(int mid, int n, int m){
	    long long ans =1;
	    for(int i =1; i<=n; i++){
	        ans *= mid;
	        if(ans>m) return 0;
	    }
	    if(ans == m) return 1;
	    else return 2;
	   
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends