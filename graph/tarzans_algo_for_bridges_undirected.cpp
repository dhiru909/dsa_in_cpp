//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

// } Driver Code Ends
class Solution
{
public:
    //Function to find if the given edge is a bridge in graph. 
    
    void dfs(int u,int p,vector<int>adj[],int disc[],int low[],bool visited[],vector<pair<int,int>>&bridges){
        
         static int timer=0; 
         visited[u]=true; 
         disc[u]=low[u]=++timer; 
         
         for(int v:adj[u]){
             if(v==p)continue;
            if(visited[v]==false){
              
            //    cout<<v<<endl;
               dfs(v,u,adj,disc,low,visited,bridges);  
               
               
               low[u]=min(low[u],low[v]);
               
               //bridge condition
               if(low[v] > disc[u]){
                   
                   bridges.push_back({u,v});
               }
               
              
               
            }  
            else{  //backedge
                
                low[u]=min(low[u],disc[v]);
            }
         }
    }
    
    
    vector<pair<int,int>> tarzan(int V, vector<int> adj[]) 
    {
        int disc[V]; 
        int low[V]; 
        int parent[V]; 
        bool visited[V]; 
        vector<pair<int,int>>bridges;
        for(int i=1;i<V;i++){
             disc[i]=-1; 
             low[i]=-1; 
             visited[i]=false;
        }  
        
        
       int res=0; 
        
        for(int i=1;i<V;i++){
           if(visited[i]==false){
              dfs(i,-1,adj,disc,low,visited,bridges); 
           }  
        }
        
    //   for(int i=1;i<V;i++){
    //     cout<<low[i]<<" ";
    //   }
       return bridges;
    } 
    
    
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V+1];
        // int i=0;
        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        Solution obj;
    	vector<pair<int,int>> bridges = obj.tarzan(V+1, adj);
        for (int i = 0; i < bridges.size(); i++)
        {
            cout<<bridges[i].first<<" "<<bridges[i].second<<endl;
        }
        
    }

    return 0;
}


// } Driver Code Ends