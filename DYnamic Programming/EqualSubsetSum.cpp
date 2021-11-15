// Partition Equal Subset Sum

  int findSubset(int arr[], int n, int s){

        int dp[n+1][s+1];
        
        for (int i =0; i <= n; i ++){
            for(int j =0; j <=s; j ++){
                if (j == 0) dp[i][j] = 1;
               else if (i ==0) dp[i][j] =0;
               else if (arr[i-1]<=j)
                   dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
               
               else dp[i][j] = dp[i-1][j];
               }
            }
        
        
        return dp[n][s];
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i =0; i < N; i ++){
            sum += arr[i];
        }
        
        if (sum % 2 ) return 0;
        
        return findSubset(arr, N, sum/2);
    }