#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int ans = 1;
int find(int i, int *parent)
{
    if (parent[i] == -1)
        return i;

    return parent[i] = find(parent[i], parent);
}

void merge(int u, int v, int *rank, int *parent)
{
    u = find(u, parent);
    v = find(v, parent);
    if (u != v)
    {
        if (rank[u] > rank[v])
        {
            parent[v] = u;
            rank[u]+=rank[v];
            rank[v]=0;
            ans = max(ans,rank[u]);
        }
        else if (rank[u] < rank[v])
        {
            parent[u] = v;
            rank[v]+=rank[u];
            rank[u]=0;
            ans = max(ans,rank[v]);
        }
        else
        {
            parent[v] = u;
            rank[u]+=rank[v];
            rank[v]=0;
            ans = max(ans,rank[u]);
        }
    }
    // cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
    freopen("errorf.err", "w", stderr);
#endif

    int n, m;
    cin >> n >> m;
    int rank[n + 1];
    int parent[n + 1];
    for (int i = 0; i <= n; i++)
    {
        rank[i] = 1;
        parent[i] = -1;
    }
    vector<pair<int, pair<int, int>>> edges;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({0, {x, y}});
    }
    // sort(edges.begin(), edges.end());
    int seg = n;
    for (auto edge : edges)
    {
        if(seg==1)break;
        int z = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        
        if (find(u,parent) != find(v,parent))
        {
            // cout << z << " " << u << " " << v << endl;
            ans += (long long)z;
            seg--;
            
            merge(u, v, rank, parent);
        }
        cout<<seg<<" "<<ans<<endl;
    }
    // cout << ans;
    // if (seg == 1)
    //     cout << ans << endl;
    // else
    //     cout << "IMPOSSIBLE" << endl;
}