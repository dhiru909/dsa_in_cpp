//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adjj[], int S)
    {
        // Code here
        // create adjacency list
        unordered_map<int, list<pair<int, int>>> adj;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adjj[i].size(); j++)
            {
                adj[i].push_back({adjj[i][j][0], adjj[i][j][1]});
            }
        }
        // vector to store shortest distance firstly intialize all value to infinite
        vector<int> dist(V);
        vector<int> prev(V, S);
        prev[S] = -1;
        for (int i = 0; i < V; i++)
        {
            dist[i] = INT_MAX;
        }
        // make distance of source to 0
        dist[S] = 0;
        set<pair<int, int>> st;
        //  insert first record to set(0,S) first is distance and second is vertex
        st.insert(make_pair(0, S));
        // Iterate while set is not empty
        while (!st.empty())
        {
            // fetch top record i.e record with weight minimum
            auto u = *(st.begin());
            int nodeDistance = u.first;
            int topNode = u.second;
            // remove top record now
            st.erase(st.begin());
            // travers through neighbour
            for (auto neighbour : adj[topNode])
            {
                if (neighbour.second + nodeDistance < dist[neighbour.first])
                {
                    auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                    // if record found then erase from set
                    if (record != st.end())
                    {
                        st.erase(record);
                    }

                    // distance update
                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    prev[neighbour.first] = topNode;
                    // record push
                    st.insert(make_pair(nodeDistance + neighbour.second, neighbour.first));
                }
            }
        }
        // return distance
        return dist;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends