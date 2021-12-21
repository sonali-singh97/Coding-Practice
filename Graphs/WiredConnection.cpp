/***Question: 450 list
 Src: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
 ***/


class Solution {
public:
    void dfs (vector<int> adj[], vector<bool>& visited, int src  ){
       visited[src]= true;
        
    for (auto it : adj[src]){
        if(!visited[it]){
            dfs(adj, visited, it);
        }
    }

    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<bool> visited(n, false);
        int comp = 0;
        
        vector<int> adj[n];
        int edges = connections.size();
        
        for ( int i =0; i < edges ; i ++){
            int x = connections[i][0];
            int y = connections[i][1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        
        for (int i = 0; i < n; i ++){
            if (!visited[i]){
              dfs(adj, visited, i);
               comp++;
            }
        }
       int minm = comp -1;
       int extra = edges- (n-1) +(minm);
        
        if (extra >= minm ){
            return minm;
        }
        else
            return -1;
        
    }
};