//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void path(int x, int y, string s, vector<string>& ans, vector<vector<int>> &m, int n){
        if(x == n-1 && y == n-1 && m[x][y] == 1){
            ans.push_back(s);
            return;
        }
        if(x<0 || y<0 || x>n-1 || y>n-1 || m[x][y] == 0 || m[x][y] == 7) return;
        
        int temp = m[x][y];
        m[x][y] = 7;
        path(x-1, y, s+"U", ans, m, n);
        path(x+1, y, s+"D", ans, m, n);
        path(x, y+1, s+"R", ans, m, n);
        path(x, y-1, s+"L", ans, m, n);
        m[x][y] = temp;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string s = "";
        path(0, 0, s, ans, m, n);
        if(ans.empty()){
            ans.push_back("-1");
        }
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends