
// Question: 450 list 
// Src: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
     vector<bool> visited(V);
     vector<int> bfs;
     visited[0] = true;
     queue<int> q;
     q.push(0);
     
     while(!q.empty()){
         int node = q.front();
         bfs.push_back(node);
         q.pop();
         
         for(auto it : adj[node]){
             if(!visited[it]){
                 visited[it] = true;
                 q.push(it);
             }
         }
     }
     
     return bfs;
     
    }