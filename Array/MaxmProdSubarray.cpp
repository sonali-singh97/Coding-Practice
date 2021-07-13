    //Maximum Product Subarray
    
    long long max(long long a, long long b){
        if(a > b){
            return a;
        }
        return b;
    }
    
      long long min(long long a, long long b){
        if(a < b){
            return a;
        }
        return b;
    }
    
	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    long long maxm = INT_MIN;
	    
	    long long max_till_now= 1;
	    long long min_till_now= 1;
	    
	    for (int i =0; i<n ; i++){
	        
	        long long temp = max_till_now;
	        
	        if(arr[i]==0){
	            max_till_now = 1;
	            min_till_now = 1;
	        }
	        
	        int ele = arr[i];
	        max_till_now = max(arr[i], max( max_till_now * ele, min_till_now* ele ) );
	        
	        
	        min_till_now = min(arr[i], min( min_till_now * arr[i], temp * arr[i] ));
	        maxm = max(max_till_now, maxm);
	       
	    }
	    
	    
	     return maxm;
	    
	}