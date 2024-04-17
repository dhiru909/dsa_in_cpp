#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[2501];

    int lisNLogN(vector<int> &nums)
    {
        vector<int>subsequences;
        subsequences.emplace_back(nums[0]);
        for(int ii =1;long(ii)<nums.size();ii++){
            int i = nums[ii];
            if(i>subsequences.back()){
                subsequences.emplace_back(i);
            }else{
                auto it = lower_bound(subsequences.begin(),subsequences.end(),i);
                *it=i;
            }
        }
        // for (int i = 0; i < subsequences.size(); i++)
        // {
        //     cout<<subsequences[i]<<" \n"[i==subsequences.size()-1];
        // }
        
        return  subsequences.size();
    }

    int lis(int i, vector<int> &a)
    {
        if (dp[i] != -1)
            return dp[i];
        int ans = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                ans = max(ans, lis(j, a) + 1);
            }
        }
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = max(ans, lis(i, nums));
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int te;
            cin >> te;
            a.push_back(te);
        }
        cout << s.lisNLogN(a) << endl;
    }
}