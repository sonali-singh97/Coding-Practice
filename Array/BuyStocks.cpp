BuyStocks.cpp

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int minIndex = -1;
        int min = INT_MAX;
        int profit = 0;
        int n = arr.size();
        
        for(int i =0 ; i<n ; i++){
            if(arr[i] < min){
                min = arr[i];
            }
            
            else if(profit < arr[i]-min){
                profit = arr[i]-min;
            }
        }
         return profit;
    }
};