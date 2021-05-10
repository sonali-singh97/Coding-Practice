

/*
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
Time Complexity : O(N)
Space Complexity : O(N)
*/


 int maxSubarraySum(int arr[], int n){
        if(n==0)
         return 0;
        
       int max_till_now = arr[0];
       int max_so_far = arr[0];
       
       for(int i =1; i< n ; i++){
            
           if(max_till_now < 0){
               max_till_now = 0;
           }

           max_till_now += arr[i];
           max_so_far = max(max_till_now , max_so_far);
           
       }
       
       return max_so_far;
        
    }