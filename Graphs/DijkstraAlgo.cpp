 /** Question: 450 list
  Src: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1#
  ***/

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            for (auto it : adj[node]){
                if(dist[it[0]] > dist[node] + it[1]){
                    dist[it[0]] = dist[node]+ it[1];
                    pq.push({dist[it[0]], it[0]});
                }
            }
        }
        
        return dist;
    }
    
  //  Time Complexity : O((N+E)logN)