//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    void findSubset(vector<int> &arr, int n, int sum, vector<int>& res)
    {
        if(n == -1)
        {
            res.push_back(sum);
            return;
        }
        

        findSubset(arr, n - 1, sum + arr[n], res);
        findSubset(arr, n - 1, sum, res);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        
        vector<int> res;
        
        findSubset(arr, n - 1, 0, res);
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends