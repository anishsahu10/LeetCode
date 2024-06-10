//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int XORA = 0;
        for(int i = 0; i<nums.size(); i++){
            XORA = XORA ^ nums[i];
        }
        int rightmost_bit = (XORA & (XORA - 1)) ^ XORA;
        int b1 = 0, b2 = 0;
        for(int j = 0; j<nums.size(); j++){
            if(nums[j] & rightmost_bit) b1 = b1 ^ nums[j];
            else b2 = b2 ^ nums[j];
        }
        return {min(b1,b2), max(b1,b2)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends