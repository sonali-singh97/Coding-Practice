/***Question: 450 List
 Src: https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1
 ****/


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int dx[3] = {0, -1, 1};
    int dy[3] = {-1, -1, -1};
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> dp(n, vector<int>(m));
        
        for (int i =0; i < n; i ++){
            dp[i][0] = M[i][0];
        }
        
        for(int j=1; j <m; j++){
            for(int i=0; i < n; i++){
                int maxm = M[i][j];
                
                for(int d = 0; d <3; d++){
                    int newX = i + dx[d];
                    int newY = j + dy[d];
                    
                    if(newX>=0 && newY>=0 && newX < n && newY < m){
                        maxm = max(maxm, M[i][j]+ dp[newX][newY]);
                    }
                }
                
                dp[i][j] = maxm;
            }
        }
        
        int ans = -1;
        
        for(int i =0; i < n; i ++){
            ans = max(ans, dp[i][m-1]);
        }
        return ans;
    }
};

/***Approach**
 Time Complexity: O(n*m)
 - Use DP
 - Traverse column wise to calculate maxm gold till a particular column
 *************/
