// #include <bits/stdc++.h>
// using namespace std;
// vector<vector<long long>> ans;
// vector<long long> solve(int S, vector<pair<int, long long>> adj[], int n)
// {
//     vector<long long> dist(n + 1, LLONG_MAX);

//     dist[S] = 0;
//     set<pair<long long, int>> pq;
//     pq.insert(make_pair(0, S));
//     while (!pq.empty())
//     {
//         pair<long long, int> top = *pq.begin();
//         pq.erase(pq.begin());
//         int topNode = top.second;
//         long long nodeDistance = top.first;

//         for (auto &neighbour : adj[topNode])
//         {
//             if (dist[neighbour.first] > nodeDistance + neighbour.second)
//             {
//                 auto record = pq.find(make_pair(dist[neighbour.first], neighbour.first));
//                 if (record != pq.end())
//                     pq.erase(record);

//                 dist[neighbour.first] = nodeDistance + neighbour.second;

//                 pq.insert(make_pair(dist[neighbour.first], neighbour.first));
//             }
//         }
//     }
//     // for (int i = 1; i <= n; i++)
//     // {
//     //     cout << dist[i] << " ";
//     // }
//     // cout << endl;
//     return dist;
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);cout.tie(NULL);
// #ifdef LOCAL
//     freopen("inputf.in", "r", stdin);
//     freopen("outputf.out", "w", stdout);
//     freopen("errorf.err", "w", stderr);
// #endif
//     int n, m, q;
//     cin >> n >> m >> q;
//     vector<pair<int, long long>> adj[n + 1];
//     // vector<bool>vis(n+1,false);
//     // vector<int> parent(n + 1, 1);
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, c;
//         cin >> u >> v >> c;
//         adj[u].emplace_back(make_pair(v, c));
//         adj[v].emplace_back(make_pair(u, c));
//     }
//     ans.push_back({});
//     for (int i = 1; i <= n; i++)
//     {
//         ans.push_back(solve(i, adj, n));
//     }
//     for (int i = 1; i <= q; i++)
//     {

//         int u, v;
//         cin >> u >> v;
//         cout << (ans[u][v] == LLONG_MAX ? -1 : ans[u][v]) << '\n';
//     }
// }





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
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long >> matrix(n+1,vector<long long >(n+1,0x3f3f3f3f3f3f3f3f));
    for (int i = 0; i < m; i++)
    {
        long long u, v, c;
        cin >> u >> v >> c;
        matrix[u][v]=min(matrix[u][v],c);
        matrix[v][u]=min(matrix[v][u],c);

    }
    for(int i=1;i<=n;i++){
        matrix[i][i] = 0LL;
    }
    for(int via=1;via<=n;via++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                matrix[i][j] = min(matrix[i][j],matrix[i][via]+matrix[via][j]);
            }
        }
    }

    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << (matrix[u][v] == 0x3f3f3f3f3f3f3f3f ? -1 : matrix[u][v]) << '\n';
    }

}