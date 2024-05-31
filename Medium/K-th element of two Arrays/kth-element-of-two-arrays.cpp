//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int a[], int b[], int n, int m, int k)
    {
        if(n>m) return kthElement(b, a, m, n, k);
        int low = max(0, k-m), high = min(n,k);
        while(low<=high){
            int m1 = (low+high)/2;
            int m2 = k - m1;
            int l1 = INT_MIN, l2= INT_MIN;
            int r1 = INT_MAX, r2= INT_MAX;
            if(m1<n) r1 = a[m1];
            if(m2<m) r2 = b[m2];
            if(m1-1>=0) l1 = a[m1-1];
            if(m2-1>=0) l2 = b[m2-1];
            if(l1 <= r2 && l2 <= r1){
                return max(l1,l2); //kth element
            }
            else if(l1>r2) high = m1-1; //more than needed elements are on the left side from arr a.
            else if(l2>r1) low = m1+1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends