//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        bool *vis = new bool[V];
        memset(vis, false, V);
        bool *curS = new bool[V];
        memset(curS, false, V);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (isCyclicUtil(i, adj, vis, curS))
                {
                    delete[] vis;
                    delete[] curS;
                    return true;
                }
            }
        }
        delete[] vis;
        delete[] curS;
        return false;
    }

    bool isCyclicUtil(int v, vector<int> adj[], bool *vis, bool *curS)
    {
        vis[v] = true;
        curS[v] = true;
        for (auto i : adj[v])
        {
            if (!vis[i])
            {
                if (isCyclicUtil(i, adj, vis, curS))
                    return true;
            }
            else if (curS[i])
                return true;
        }
        curS[v] = false;
        return false;
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

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends