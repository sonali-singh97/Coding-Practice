// Question: 450 List 
// Src: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
 
  void dfsHelper(vector<int> adj[] , vector<bool>& visited, int src, vector<int>& dfs){
        
        visited[src] = true;
        dfs.push_back(src);
        
        for (auto it : adj[src]){
            if(!visited[it]){
                dfsHelper(adj, visited, it, dfs);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<bool> visited(V);
        vector<int> dfs;
        
        for (int i =0;i < V; i ++){
            if(!visited[i]){
                dfsHelper(adj, visited, i, dfs);
            }
        }
        
        return dfs;
    }