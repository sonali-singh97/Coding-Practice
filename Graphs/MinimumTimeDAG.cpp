/*
 Question: https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void minTimeHelper(int n , vector<int> adj[], vector<int>& inorder, vector<int>& time){
    queue<int> q;
    for (int i = 0 ; i <= n; i ++){
        if (inorder[i]==0)
         q.push(i);
        
    }
    
    int level =0;
    
    while(!q.empty()){
        int size  = q.size();
        level ++;
        while(size--){
        int node = q.front();
        q.pop();
        time[node] = level;
        for (auto it: adj[node]){
            inorder[it]--;
            if (inorder[it]==0){
                q.push(it);
            }
        }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
   vector<int> adj[n+1];
   vector<int> inorder(n+1, 0);
   int a, b;
   for(int i =0; i < m; i ++){
       cin >> a >> b;
       adj[a].push_back(b);
       inorder[b]++;
   }
   
   vector<int> time(n+1, 0);

  minTimeHelper(n, adj, inorder, time);
   
   for (int i =0; i <= n; i ++){
       cout <<  time[i]<<" ";
   }
   return 0;
}