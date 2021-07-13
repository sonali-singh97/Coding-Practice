
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        long long int prod = 1;
        long long count =0;

        for(int i =0; i < n; i++){
            if(nums[i]!= 0)
             prod *= nums[i];
             
             else count++;
        }
        
        for(int i =0; i < n; i++){
           if(nums[i]!= 0 && count || nums[i]==0 && count>=2 )
              nums[i] = 0;
            
            else if(nums[i] ==0)
              nums[i] = prod;
              
            else nums[i] = prod/nums[i];
        }
        
        return nums;
    }