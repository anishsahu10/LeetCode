//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        unordered_map<int,int> mp;
        int i = 0;
        int maxF = INT_MIN;
        int ans;
        while(i<size){
            mp[a[i]]++;
            i++;
        }
        for(auto freq : mp){
            maxF = max(maxF, freq.second);
        }
        for(auto value : mp){
            if(value.second == maxF){
                ans = value.first;
                break;
            }
        }
        
        if(maxF>size/2) return ans;
        return -1;
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends