// Given a value N, find the number of ways to make change for N cents

    long long int count(int S[], int size, int n) {
        if (n == 0) return 1;
        if (size == 0) return 0;
        long long dp[size+1][n+1];
        
        for (int i =0; i<= size; i ++){
            for(int j =0; j <=n; j ++){
                if (j ==0) dp[i][j] =1;
               else if (i == 0)dp[i][j] = 0;
               else if (S[i-1] <= j){
                   dp[i][j] = dp[i][j - S[i-1]] + dp[i-1][j];
               }
               else dp[i][j] = dp[i-1][j];
                
            }
        }
        
        return dp[size][n];
    }