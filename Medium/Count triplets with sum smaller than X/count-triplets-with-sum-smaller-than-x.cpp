//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr, arr+n);
	    long long count = 0;
    
        int i, j, k;
        
        for(int i=0; i<n; i++)
        {
            j = i+1;
            k = i+2;
            
            while(i<j && j<k && k<n)
            {
                if(arr[i] + arr[j] + arr[k] == sum)
                {
                    j--;
                }
                else if(arr[i] + arr[j] + arr[k] > sum)
                {
                    j--;
                }
                else
                {
                    count += j-i;
                    j++;
                    k++;
                }
            }
        }    
        return count;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends