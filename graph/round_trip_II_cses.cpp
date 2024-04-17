#include<bits/stdc++.h>
using namespace std;
bool found = 0;
bool dfs(int v,vector<int> adj[],vector<bool>&vis, vector<int>&cycl,int p){
    if(found)return 1;
    vis[v]=true;
    cycl.emplace_back(v);
    cout<<v<<endl;
    for(auto i:adj[v]){
        if(!vis[i]){
            if(dfs(i,adj,vis,cycl,v))return true;
        }
        else if(p!=i){
            int f = 0;
            found =1;
            // cout<<" parent"<<p<<i<<endl;
            cycl.emplace_back(i);
            for(int ii=0;ii<cycl.size();ii++){
                if(cycl[ii]==i and ii!=(int)cycl.size()-1){
                    f=1;
                    cout<<cycl.size()-ii<<endl;
                }
                if(f){
                    cout<< cycl[ii]<<" ";
                }
            }
            return true;
        }
    }
    cycl.pop_back();
    return false;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
    freopen("errorf.err", "w", stderr);
#endif
    int n, m;
    cin >> n >> m;
    vector<int>adj[n+1];
    vector<bool>vis(n+1,false);
    vector<int>cycl;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].emplace_back(v);
 
    }
    for(int i=1;i<=n;i++){
        if(!found)
        if(!vis[i]){
            // vis.resize(n+1,false);
            cout<<"NEW";
            if(dfs(i,adj,vis,cycl,-1))break;
        }
    }
    if(!found)cout<<"IMPOSSIBLE"<<endl;
}