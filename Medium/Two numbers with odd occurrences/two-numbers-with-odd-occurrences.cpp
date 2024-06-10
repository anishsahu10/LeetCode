//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long XORA = 0;
        for(long long i = 0; i<N; i++){
            XORA = XORA ^ Arr[i];
        }
        long long rightmost_bit = (XORA & (XORA - 1)) ^ XORA;
        long long b1 = 0, b2 = 0;
        for(long long j = 0; j<N; j++){
            if(Arr[j] & rightmost_bit) b1 = b1 ^ Arr[j];
            else b2 = b2 ^ Arr[j];
        }
        return {max(b1,b2), min(b1,b2)};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends