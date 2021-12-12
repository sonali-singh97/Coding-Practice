
// Question: 450 list 
// Src: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


bool checkComponent(vector<int> adj[], vector<bool>& dfsVisit, vector<bool>& visited, int src){
        
        visited[src] = true;
        dfsVisit[src] = true;
        
        for (auto it : adj[src]){
            if (!visited[it]){
               if(checkComponent(adj, dfsVisit, visited, it))
                  return true;
            }
            else if (dfsVisit[it]) return true;
        }
        
        dfsVisit[src] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V);
        vector<bool> dfsVisit(V);
        
        for (int i =0; i < V; i ++){
            if (!visited[i]){
                bool res = checkComponent(adj, dfsVisit, visited, i);
                if(res) return true;
            }
        }
        
        return false;
    }


    /*****APPROACH****
     Time: O(V+E)
     Method 1(above): Make two array dfsVisit and visited and check if a node is visited again in the same dfs, then it's a cycle.
     Method 2: Do Topological Sort, if nodes < n then there is a cycle(Kahn's Algorithm)
     *****************/