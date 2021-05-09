
/*
Given an array of integers and a number x, find the smallest subarray with sum greater than the given value.
Time Complexity: O(N)
Space Complexity : O(1)
*/

    int sb(int arr[], int n, int x)
    {
        
        if ( n==1 || arr[0] > x){
           return 1; 
        }
        
        int i=0;
        int j = 1;
        int sum = arr[0];
        int min_count = n;
        
        while( j < n && i <n){
            
            
            while( sum <= x && j < n){
                sum+= arr[j];
                j++;
            
            }

            while(sum > x && i <n ){
                int count = j-i;
                if(count < min_count){
                    min_count = count;
                }
              
                sum -= arr[i];
                  i++;
            }
        }

        return min_count;
        
    }