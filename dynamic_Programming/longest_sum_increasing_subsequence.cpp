//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		//we can use any of the function both works well.

	public:
	int dp[1010];

	int lis(int i,int a[]){
        if(dp[i]!=-1)return dp[i];
        int ans=a[i];
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                ans=max(ans,lis(j,a)+a[i]);
            }
            
        }
        return dp[i]=ans;
    }
    int longestSumIncreasingSubsequence(int nums[],int n) {
        // int n = nums.size();
        vector<int> dp(n, 0);
        int maxSum = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = nums[i];
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + nums[i]);
                }
            }
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }

	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	   // memset(dp,-1,sizeof(dp));
	   // int ans=0;
    //     for(int i=0;i<n;i++){
    //         ans=max(ans,lis(i,arr));
    //     }
        // return ans;
        return longestSumIncreasingSubsequence(arr,n);
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
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends