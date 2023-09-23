//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
vector<int>dx={1,-1,0,0};
vector<int>dy={0,0,1,-1};
class Solution{
public:
vector<vector<int>>dp;
vector<vector<bool>>vis;
int helper(int r,int c,vector<vector<char>> &cVill,int n,int m){
    if(cVill[r][c]=='N')return -1;
    if(cVill[r][c]=='W')return 0;
    if (dp[r][c] != -2) return dp[r][c];
    int ans=INT_MAX;
    vis[r][c]=1;
    for(int i=0;i<4;i++){
        int nr=r+dx[i];
        int nc=c+dy[i];
        
        if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc]){
            int temp=helper(nr,nc,cVill,n,m);
            if(temp!=-1)ans=min(ans,temp+1);
        }
        
    }
    vis[r][c]=0;
    dp[r][c] = (ans == INT_MAX ? -1 : ans);
    return dp[r][c];
    
}
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        dp.resize(n,vector<int>(m,-2));
        vis.resize(n,vector<bool>(m,false));


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-2)
                dp[i][j]=helper(i,j,c,n,m);
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // if(dp[i][j]==-2)
               if(c[i][j]=='.')dp[i][j]=0;
            }
        }
        return dp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends