#include<bits/stdc++.h>
using namespace std;
// #define intt long long
int dp[501][70004];
#define MOD 1000000007

long long binExpIter(long long a, long long b, int M)
{
    long long ans = 1;
    while (b) // while b>0
    {
        if (b & 1)
        {
            ans = (ans * a) % M; // if(0th bit of b is 1 then we have to take that multiple so ans = ans*a) otherwise ignore
        }
        a = (a * a) % M; // we have to always square that base to abtain -> 3^8 3^4 3^2 3^1 ... as for example
        b >>= 1;         // right shift b to get next bit
    }
    return ans;
}
long long moduloInverse(int a){
    return binExpIter(a,MOD-2,MOD);

}


int helper(int ind,int n,int total ){
    if(total ==0)return 1;
    if(ind>n)return 0;
    
    if(dp[ind][total]!=-1) return dp[ind][total];
    int ans = helper(ind+1,n,total)%MOD;
    if(ind<=total){
        ans+=helper(ind+1,n,total-ind)%MOD;
    }
    return dp[ind][total] = ans;
}
void solve(int n){

    memset(dp,-1,sizeof(dp));
    if((n*(n+1)/2)&1){
        cout<<0<<endl;
    }else{
        int t = n*(n+1)/4;
        // for(int i=0;i<=t;i++ )dp[0][i] =0;
        // for(int i=0;i<=n;i++)dp[i][0] = 1;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=t;j++){
        //         dp[i][j] = dp[i-1][j]%MOD;
        //         if(i<=j){
        //             dp[i][j] += dp[i-1][j-i]%MOD;
        //         }
        //     }
        // }
        // cout<<(dp[n][t]*moduloInverse(2))%MOD<<endl;
        cout<<(helper(1,n,t)*moduloInverse(2))%MOD<<endl;
    }

}
int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n;
    solve(n);
}