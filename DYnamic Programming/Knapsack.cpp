
/*
 You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.

 Time Complexity: n*m
 Space Complexity: n*m
 */


    int knapSack(int W, int wt[], int val[], int n) 
    { 
       
     
       int arr[n+1][ W+1];
       
       for(int i =0; i<= n; i++){
           for(int j =0; j<=W ; j++){
               
               if( i ==0 || j==0){
                   arr[i][j]=0;
               }
               
                else if(wt[i-1] <= j ){
                   arr[i][j] = max(arr[i-1][j] , val[i-1] + arr[i-1][j-wt[i-1]]);
               }
               else{
                 
                   arr[i][j] = arr[i-1][j];
               }
               
           }
       }
       
   
     return arr[n][W];

    
    }