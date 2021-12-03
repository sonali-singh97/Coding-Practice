/****Question *****
 Src: 450 DSA List
 Link: https://www.hackerrank.com/challenges/journey-to-the-moon/problem 
  ***********/

// Time Complexity : O(V+E)
int traversePath(int n , vector<int> adj[], vector<bool>& visited, int node){
    visited[node] = true;
    int totalNodes = 1;
    for(auto it : adj[node]){
        if (!visited[it]){
            totalNodes += traversePath(n, adj, visited, it);
        }
    }
    return totalNodes;
}
long long journeyToMoon(int n, vector<vector<int>> astronaut) {
 
 vector<int> adj[n];
 int len = astronaut.size();
 for (int i =0; i < len;i ++){
     int u = astronaut[i][0];
     int v = astronaut[i][1];
     adj[u].push_back(v);
     adj[v].push_back(u);
 }
 
 unordered_map<int, int> countChildren;
 vector<bool> visited(n);
 long long totalChild = n, totalPairs = 0;
 
 for( int i = 0; i < n; i ++){
     if (!visited[i]){
         int num = traversePath(n, adj, visited, i);
         countChildren[i] = num; 
     }
 }
 
 /***Method 1****
 long long pairs = (n*(n-1))/2;
 long long samePairs = 0;
  for (auto it : countChildren){
    samePairs += (it.second * (it.second - 1))/2;
 }
 cout << pairs - samePairs << endl;
 *******/
 
 /**** Method 2 *****/
 for (auto it : countChildren){
     totalPairs += it.second * (totalChild - it.second);
     totalChild -=it.second;
 }

 return totalPairs;
}

/********APPROACH (Graph Question)*******

-> Count no of nodes in each component
Method1: Count all pairs (nC2)- Pairs from same group(No. of nodes in each group* C*2)
Merhod 2: No. of pairs =  (Σ No. of nodes in a group * (remaining no. of nodes))/2

************************/