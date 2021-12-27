/** Question: 450 list
 Src: https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#
 ***/

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
      int dp[n+1];
      memset(dp, -1, sizeof dp);
      dp[0] = 0;
      
      for(int i =1; i <= n; i ++){
          if(i-x >=0 && dp[i-x] != -1 &&dp[i] < dp[i-x]+1){
              dp[i] = dp[i-x]+1 ;
          }
          
          if(i-y >= 0 &&  dp[i-y] != -1 && dp[i] < dp[i-y] + 1){
              dp[i] = dp[i-y] + 1;
          }
          
          if(i-z >= 0 &&  dp[i-z] != -1 && dp[i] < dp[i-z] + 1){
              dp[i] = dp[i-z] + 1 ;
          }
      }
    
      if(dp[n] == -1) return 0;
      return dp[n];
    }
};

/****Approach ****
  Use DP
  for every length i:
    find max (i-x, i-y, i-z) + 1
    
 *****************/