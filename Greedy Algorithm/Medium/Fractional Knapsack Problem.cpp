//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    
    static bool sortOnRatio(Item a, Item b)
    {
        return ((double)a.value / a.weight) > ((double)b.value / b.weight);
    }
    
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        
        sort(arr, arr + n, sortOnRatio);
        
        double profit = 0;
        
        for(int i = 0; i < n ; i++)
        {
            //cout<<w<<endl;
            if(arr[i].weight <= w)
            {
                w -= arr[i].weight;
                profit += arr[i].value;
            }
            else
            {
                double unitVal = (double)arr[i].value / arr[i].weight;
                double val = unitVal * w;
                profit += val;
                break;
            }
        }
        
        return profit;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends