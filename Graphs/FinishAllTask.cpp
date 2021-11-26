// Question  (450 list)
// https://www.geeksforgeeks.org/find-whether-it-is-possible-to-finish-all-tasks-or-not-from-given-dependencies/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(int n , vector<int> adj[], vector<int>& inorder){
    queue<int> q;
    for (int i = 0 ; i < n; i ++){
        if (inorder[i]==0)
         q.push(i);
        
    }

    int cnt = 0;
    while(!q.empty()){
    int node = q.front();
    q.pop();
    cnt++;
    for(auto it : adj[node]){
        inorder[it]--;
        if(inorder[it] == 0){
            q.push(it);
        }
    }
    }
    
    if (cnt == n) return true;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
   vector<int> adj[n];
   vector<int> indegree(n, 0);
   int a, b;
   for(int i =1; i <=m; i ++){
       cin >> a >> b;
       adj[a].push_back(b);
       indegree[b]++;
   }
   
  cout << isPossible(n, adj, indegree);

   return 0;
}