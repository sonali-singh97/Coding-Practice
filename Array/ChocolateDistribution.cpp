ChocolateDistribution.cpp

class Solution{
    public:
    long long findMinDiff(vector<long long> arr, long long n, long long m){
    
     sort(arr.begin(), arr.end());
     int min_diff = INT_MAX;
     
     for(int i=0; i<=n-m; i++){
         int diff = arr[i+m-1] - arr[i];
           if(min_diff > diff){
               min_diff = diff;
           }

     }
     return min_diff;
    }   
};