#include<bits/stdc++.h>
using namespace std;
void dfs(int v,vector<int> adj[],vector<bool>&vis){
    vis[v]=true;
    for(auto & i:adj[v]){
        if(!vis[i])
        dfs(i,adj,vis);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
    freopen("errorf.err", "w", stderr);
#endif
    
    int n,m;cin>>n>>m;
    vector<int> adj[n+1];
    vector<bool>vis(n+1, false);
    vector<pair<int,int>>ans;
    for (int i = 0;i < m;i++) {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int temp = -1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(temp!=-1){
                ans.push_back({temp,i});
                
            }
            temp = i;
            dfs(i,adj,vis);

        }
        
    }
    cout<<ans.size()<<endl;
    for(auto &i:ans){
        cout<<i.first<<" "<<i.second<<endl;
    }


}