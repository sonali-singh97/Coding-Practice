/** Question: 450 list
 Src: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1 ***/

 bool detectCycle(vector<int> adj[], vector<bool>& visited, int src){
        queue<pair<int, int>> q;
        q.push({src, -1});
        visited[src] = true;
        
        while(!q.empty()){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for (auto it: adj[node]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (it!= par )
                    return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V);
        
        for (int i =0; i < V; i ++){
            if(!visited[i] && detectCycle(adj, visited, i )){
                return true;
            }
        }
        
        return false;
    }