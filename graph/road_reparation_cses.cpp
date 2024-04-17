#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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
        }
        else if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
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
        rank[i] = 0;
        parent[i] = -1;
    }
    vector<pair<int, pair<int, int>>> edges;
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({z, {x, y}});
    }
    sort(edges.begin(), edges.end());
    long long ans = 0;
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
    }
    // cout << ans;
    if (seg == 1)
        cout << ans << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}