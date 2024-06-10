//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        bool sign = true;
        if(dividend >= 0 && divisor < 0) sign = false;
        if(dividend < 0 && divisor > 0) sign = false;
        long long n = abs(dividend);
        long long d = abs(divisor);
        long long ans = 0;
        
        while(n>=d){
            int count = 0;
            while(n >= (d<<(count+1))){
                count++;
            }
            ans += (1<<count);
            n -= (d<<count);
        }
        if(ans == (1<<31) && sign) return INT_MAX;
        if(ans == (1<<31) && !sign) return INT_MIN;
        
        return sign ? ans : -ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends