#include <iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<climits>
#include<queue>
#include<set>
#include<cmath>
#include<algorithm>
#define pb push_back
#define N (lli)(2e5)
#define lli  long long int
#define mod (lli)(1e9+7)
#define INF lli_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
// THOR>>>HULK


vector<int>p2(N);
int ns,ne;

void dfs2(int x,vector<vector<int>>&adj,vector<int>&parent,vector<int>&level,vector<int>&cycle,vector<int>&tree)
{
    for(int node : adj[x])
    {
        if(cycle[node]==0)
        {
            parent[node] = x;
            level[node] = level[x]+1;
            tree[node] = tree[x];
            dfs2(node,adj,parent,level,cycle,tree);
        }
    }
}


bool lca_superfast(int u,int v,vector<int>&level,vector<int>&parent,vector<vector<int>>&sparse)
{
    if(u==v) return true;
    if(level[u]<level[v]) return false;
    int diff = level[u] - level[v];
    while(diff!=0)
    {
        int pw = p2[diff];
        diff = diff - (1<<pw);
        u = sparse[u][pw];
    }
    if(u==v) return true;
    return false;
    
}

void dfs(int x,vector<int>&vis,vector<int>&to)  // cycle detection
{
    vis[x] = 1;
    int y = to[x];
    
    
    if(vis[y]==1)
    {
        ns = y;
        ne = x;
    }
    else if(vis[y]==0)
        dfs(y,vis,to);
    
    vis[x] = 2;
}

int  main()
{
    fast_io;
    int n,q;
    cin>>n>>q;
    vector<int>to(n+1);
    vector<vector<int>>rgr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>to[i];
        rgr[to[i]].pb(i);                     // keeps reverse graph
    }
    
    int prev_cycle = 0;                      // keeps account of current cycle number
    int cur = 0;                             // keeps current number of node within a cycle
    
    vector<int>cycle(n+1,0);                 // keeps record of cycle number of a node;
    vector<int>in_cycle(n+1,0);              // keeps number of a cycle node within a cycle
    vector<int>vis(n+1,0);
    vector<int>tot(n+1,0);                   // keeps total number of nodes in a cycle
    
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            ns = ne = -1;
            dfs(i,vis,to);
            if(ns==-1) continue;
            
            
            prev_cycle++;
            cur = 0;
            
            int t = ns;
            while(t!=ne)
            {
                cycle[t] = prev_cycle;
                in_cycle[t] = ++cur;
                t = to[t];
            }
            
            cycle[t] = prev_cycle;
            in_cycle[t] = ++cur;
            t = to[t];
            tot[prev_cycle] = cur;
        }
    
    
    p2[1] = 0;
    for(int i=2;i<N;i++) p2[i] = p2[i/2] + 1;
    vector<int>tree(n+1,0);                                 // keeps inverted tree number of the node
    vector<int>parent(n+1,0);                               // keeps parent of each node in inverted tree
    vector<int>level(n+1,0);                                // keeps level of each node in inverted tree
    vector<vector<int>>sparse(n+1,vector<int>(31,0));      // keeps super parents of each node
    
    
    
    for(int i=1;i<=n;i++)
    {
        if(cycle[i])
        {
            tree[i] = i;
            dfs2(i,rgr, parent, level,cycle,tree);
        }
    }
    
    
    
    for(int i=1;i<=n;i++) if(!cycle[i]) sparse[i][0] = parent[i];
    
    for(int j=1;j<31;j++)
        for(int i=1;i<=n;i++)
            if(!cycle[i])
                sparse[i][j] = sparse[sparse[i][j-1]][j-1];
    
    
    //    for(int i=1;i<=n;i++)
    //    {
    //        for(int j=0;j<5;j++) cout<<sparse[i][j]<<" ";
    //        cout<<endl;
    //    }
    
    int a,b;
    while(q--)
    {
        cin>>a>>b;
        if(cycle[a]==0)
        {
            if(cycle[b]==0)
            {
                int x1 = tree[a];
                int x2 = tree[b];
                if(x1!=x2) cout<<-1;
                else
                {
                    bool p = lca_superfast(a, b, level, parent, sparse);
                    if(!p) cout<<-1;
                    else cout<<level[a]-level[b];
                }
            }
            else
            {
                int x1 = tree[a];
                int c1 = cycle[x1];
                int c2 = cycle[b];
                if(c1!=c2) cout<<-1;
                else
                {
                    int t = tot[c1];
                    int y1 = in_cycle[x1];
                    int y2 = in_cycle[b];
                    if(y2>=y1) cout<<y2-y1+level[a];
                    else cout<<t-(y1-y2)+level[a];
                }
            }
            
        }
        else
        {
            if(cycle[b]==cycle[a])
            {
                int x1 = in_cycle[a];
                int x2 = in_cycle[b];
                int t = tot[cycle[a]];
                if(x2>=x1) cout<<x2-x1;
                else cout<<t-(x1-x2);
            }
            else cout<<-1;
        }
        
        cout<<endl;
    }
    
    
}





/*


#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1, logN = 20;

bool vis[maxN];
int N, Q, ds[maxN], d[maxN], comp[maxN], cyc[maxN], p[logN][maxN];
vector<int> cycleSeeds, G[maxN];

int find(int u){
    if(ds[u] < 0)   return u;
    ds[u] = find(ds[u]);
    return ds[u];
}

bool merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v)  return false;
    if(ds[u] < ds[v])   swap(u, v);
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}

void init_parents(){
    for(int i = 1; i < logN; i++)
        for(int j = 1; j <= N; j++)
            p[i][j] = p[i-1][p[i-1][j]];
}

int travel(int u, int k){
    int v = u;
    for(int i = logN-1; i >= 0; i--)
        if(k&(1<<i))
            v = p[i][v];
    return v;
}

void dfs(int u, int compID){
    vis[u] = true;
    comp[u] = compID;
    for(int v : G[u]){
        if(!vis[v]){
            d[v] = d[u]+1;
            dfs(v, compID);
        } else cyc[u] = d[u]+1;
        cyc[u] = max(cyc[u], cyc[v]);
    }
}

int query(int a, int b){
    if(a == b)  return 0;

    // Start and end are on different components
    if(comp[a] != comp[b])  return -1;

    // Start is on cycle
    if(cyc[a]){
        if(!cyc[b]) return -1;
        return (d[a]-d[b]+cyc[a]) % cyc[a];
    }

    // Start and end are on tree (must check if same tree)
    if(!cyc[b]){
        if(d[a] <= d[b])    return -1;
        int dist = d[a]-d[b];
        return (travel(a, dist) == b) ? dist : -1;
    }

    // Start is on tree and end is on cycle
    int root = a;
    for(int i = logN-1; i >= 0; i--){
        int par = p[i][root];
        if(!cyc[par])
            root = par;
    }
    root = p[0][root];

    return (d[a]-d[root]) + query(root, b);
}

int main(){
    scanf("%d %d", &N, &Q);
    fill(ds+1, ds+N+1, -1);
    for(int i = 1, x; i <= N; i++){
        scanf("%d", &x);
        p[0][i] = x;
        G[x].push_back(i);
        if(!merge(x, i))
            cycleSeeds.push_back(x);
    }

    init_parents();
    int compID = 1;
    for(int seed : cycleSeeds)
        dfs(seed, compID++);

    for(int i = 0, a, b; i < Q; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", query(a, b));
    }
}



*/