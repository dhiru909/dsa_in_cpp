#include<bits/stdc++.h>
using namespace std;

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
    vector<int>parent(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    int dist = 1;
    queue<int>q;
    q.push(1);
    vis[1] = true;
    parent[1] = -1;
    while(!q.empty()){
        // cout<<q.front();
        dist++;
        int si = q.size();
        
        
        while(si--){
            int node = q.front();q.pop();
            
            for(auto &x:adj[node]){
                if(!vis[x]){
                    vis[x]=true;
                    parent[x] = node;
                    q.push(x);
                    if(x==n)goto go;
                    
                }
            }
        } 
    }
    go:
    // cout<<vis[n];
    vector<int>anss;
    if(vis[n]){
        cout << dist<<endl;
        anss.push_back(n);
        for(int i=n;;){
            if(parent[i]==-1)break;
            anss.push_back(parent[i]);
            i=parent[i];
        }
        reverse(anss.begin(),anss.end());
        for(auto &i:anss){
            cout<<i<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}