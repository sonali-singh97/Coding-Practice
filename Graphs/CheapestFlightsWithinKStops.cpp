/**** Question****
 Src: 450 list
 link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
 *********/

class Solution {
public:
    
    int cheapestPathHelper(vector<pair<int, int>> adj[], int n, int src, int dst, int k){
        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));
        dist[src][k] = 0;
        set<vector<int>> sq;
        sq.insert(vector<int>{0, src, k});
        
        while(!sq.empty()){
            int d =(*sq.begin())[0];
            int node = (*sq.begin())[1];
            int k = (*sq.begin())[2];
            sq.erase(sq.begin());
            
            for (auto it : adj[node]){
                int newk = k;
                if (it.first != dst) newk -=1;
                if ( newk >=0){
                   
                    if (dist[it.first][newk] > d + it.second){
                        if (dist[it.first][newk] != INT_MAX){
                          sq.erase(sq.find({dist[it.first][newk], it.first, newk}));
                        }
                        
                        dist[it.first][newk] = d +it.second;
                       // cout << it.first << " "<< dist[it.first];
                        sq.insert({dist[it.first][newk], it.first, newk});
                    }
                }

            }
            
        }
        
        int ans = INT_MAX;
        
        for (int i =0; i <=k; i++){
            ans = min(ans, dist[dst][i]);
        }
        if (ans == INT_MAX) return -1;
        else return ans;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int, int>> adj[n];
        int len = flights.size();
        for (int i =0; i < len; i ++){
            int from = flights[i][0];
            int to = flights[i][1];
            int p = flights[i][2];
            adj[from].push_back({to, p});
        }
        
        return cheapestPathHelper(adj, n , src, dst, k);
        
    }
};

/******* APPROACH ***
Method 1: Using Dijkstra's Algorithm [ O((E+V)* logV) ) **confirm ]
-> Make 2d distance array of n*(k+1)
-> For every node
    Visit all neighbours by decrementing k 
    if k >=0, compare distances and modify accordingly
    
Method 2: DFS with Pruning(remove unnecessary calls)
source : https://youtu.be/60RbWlDFsmI
-> Maintain a visited array , TotalMinCost, Current cost
    - for every node , check childrenn
            if not visited and currCost <= TotalMinCost
                if (k <0 ) return
                if (node == dst) update TotalMinPath and return
                

********************/