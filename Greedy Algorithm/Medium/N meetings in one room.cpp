//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool smallerEndTime(pair<int,int> &a, pair<int, int> &b)
    {
        if(a.second == b.second)
            return a.first < b.first;

        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> meetPairs;
        
        for(int i = 0 ; i < n ; i++)
        {
            meetPairs.push_back(make_pair(start[i], end[i]));
        }
        
        sort(meetPairs.begin(), meetPairs.end(), smallerEndTime);
        
        int count = 1;
        int lastEnd = meetPairs[0].second;
        
        for(int i = 1; i < n; i++)
        {
            if(meetPairs[i].first > lastEnd){
                count++;
                lastEnd = meetPairs[i].second;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends