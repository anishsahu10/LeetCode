//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], long long l, long long m, long long r, long long &count)
    {
        vector<long long>temp;
        long long left = l;
        long long right = m+1;
        while(left<=m && right<=r){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                count = count + (m-left+1); //to account for all possible inversions after initial left <= right
                right++;
            }
        }
        
        while(left<=m){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<=r){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(long long i = l; i<=r; i++){
            arr[i] = temp[i-l];
        }
    }
    public:
    void mergeSort(long long arr[], long long l, long long r, long long &count)
    {
        if(l >= r){
            return;
        }
        long long m = l + (r-l)/2;
        mergeSort(arr, l, m, count);
        mergeSort(arr, m+1, r, count);
        merge(arr, l, m, r, count);
    }
    
    
    long long int inversionCount(long long arr[], long long n)
    {
        long long count = 0;
        mergeSort(arr, 0, n-1, count);
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends