//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long dp[n];
        int curr = 0, maxi = INT_MIN;
        for(int i=0;i<n;i++){
            curr+=a[i];
            maxi = max((int)a[i],curr);
            dp[i] = maxi;
            curr = curr<0?0:curr;
        }
        int sumi = 0;
        for(int i=0;i<k;i++){
            sumi+=a[i];
        }
        int ans = sumi;
        for(int i=k;i<n;i++){
            sumi = sumi+a[i]-a[i-k];
            ans = max(ans,sumi);
            ans = max((long long int)ans,sumi+dp[i-k]);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends