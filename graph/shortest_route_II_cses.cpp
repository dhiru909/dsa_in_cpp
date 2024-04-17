#include <bits/stdc++.h>
using namespace std;
 
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
    vector<pair<int, long long>> adj[n + 1];
    // vector<bool>vis(n+1,false);
    vector<int> parent(n + 1, 1);
    parent[1] = -1;
    vector<long long> dist(n + 1, LLONG_MAX);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(make_pair(v, c));
    }
    dist[1] = 0;
    set<pair<long long, int>> pq;
    pq.insert(make_pair(0, 1));
    while (!pq.empty())
    {
        pair<long long, int> top = *pq.begin();
        pq.erase(pq.begin());
        int topNode = top.second;
        long long nodeDistance = top.first;
 
        for (auto &neighbour : adj[topNode])
        {
            if (dist[neighbour.first] > nodeDistance + neighbour.second)
            {
                auto record = pq.find(make_pair(dist[neighbour.first], neighbour.first));
                if (record != pq.end())
                    pq.erase(record);
 
                dist[neighbour.first] = nodeDistance + neighbour.second;
                parent[neighbour.first] = top.second;
 
                pq.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
 
    for (int i=1;i<=n;i++)
    {
        cout << dist[i] << " ";
    }
}