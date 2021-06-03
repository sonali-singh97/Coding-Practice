TrappingRainWter.cpp


class Solution{

    public:
    int trappingWater(int arr[], int n){
        int temp =0;
        int prev =0;
        int water =0;
        
        for(int i = 0; i < n ; i++){
            if(arr[i] >= prev){
                prev = arr[i];
                temp =0;
            }
            else{
                water += prev - arr[i];
                temp += prev - arr[i];
            }
        }
        
        water = water - temp;
        temp =0;
        int leftMax = prev;
        prev =0;
        
        for (int j = n-1 ; arr[j]!= leftMax ; j--){
            if(arr[j] > prev){
                prev = arr[j];
            }
            
            else {
                water += prev - arr[j];
            }
        }
        
        return water;
    }
};
