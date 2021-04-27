SubarrayWithZeroSum.cpp


class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_map<int,int> count;
        int sum =0;
        for(int i=0; i<n ; i++){
            sum += arr[i];
            arr[i] = sum;
            count[sum]++;
        }
        
        for(int i=0; i<n ; i++){
            
            if(arr[i]==0)
            {
                return true;
            }
            
           else if(i!=0 && arr[i]-arr[i-1] == 0){
                return true;
            }
            
            else if(count[arr[i]] > 1){
                return true;
            }
        }
        
        return false;
    }
};