//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int brk = -1;
        for(int i=arr.size()-2; i>=0; i--){
            if(arr[i]<arr[i+1]){
                brk = i;
                break;
            }
        }
        
        if(brk == -1){
            reverse(arr.begin(), arr.end());
            return arr;
        }
        
        for(int i = arr.size()-1; i>brk; i--){
            if(arr[i]>arr[brk]){
                swap(arr[i], arr[brk]);
                reverse(arr.begin()+brk+1, arr.end());
                break;
            }
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends