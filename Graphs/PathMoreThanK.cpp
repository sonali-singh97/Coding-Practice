/** Question: 450 list 
  Src: https://www.codingninjas.com/codestudio/problems/find-if-there-is-a-path-of-more-than-k-length-from-a-source_1229512?leftPanelTab=1 
**/


bool pathHelper(int k, vector<pair<int, int>> adj[], vector<bool>& visited, int src , int dist)  {
    if(dist> k) return true;
    
    for (auto it : adj[src]){
        if(!visited[it.first])
        {   visited[it.first] = true;
            if(it.second > k) return true;
            if(pathHelper(k, adj, visited, it.first, dist+ it.second))
        		return true;
            visited[it.first] = false;
        }  
    }
    
    return false;
}

string pathMoreThanK(int n, int m, int k, vector<vector<int>>& edges)
{
    vector<pair<int, int>> adj[n];
    
    for(int i =0; i < m; i ++){
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    
    vector<bool> visited(n);
    visited[0] = true;
     if (pathHelper(k, adj, visited, 0 , 0))return "YES";
    else return "NO";
}

/**** Approach****
Time Complexity: N! (every node is connected to eavery node)

Use Backtracking
- call function for every children 
	if path exits true
    Otherwise backtrack and call on other children
******************/