/*** 
 * Question: Best Time to Buy and Sell Stocks - Two Transaction Allowed
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 ***/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<int> profitUptoNow(n);
        int minm = prices[0], profitLeft = 0;
        for (int i =1; i < n; i ++){
            if(prices[i] > minm){
                profitLeft = max(profitLeft, prices[i]- minm);
            }
            else minm = prices[i];
            profitUptoNow[i] = profitLeft;
        }
        
        vector<int> profitFromNow(n);
        int maxm = prices[n-1], profitRight = 0;
        for (int i =n-2; i >= 0; i--){
            if(prices[i] < maxm){
                profitRight = max(profitRight, maxm - prices[i]);
            }
            else maxm = prices[i];
            profitFromNow[i] = profitRight;
        }
        
        int maxProfit = 0;
        for (int i =0; i < n; i ++){
            int total =profitUptoNow[i] + profitFromNow[i];
            maxProfit = max(maxProfit, total);
        }
        
        return maxProfit;
    }
};


/****** APPROACH *******
Time : O(n)
Space: O(n)
Src: https://youtu.be/wuzTpONbd-0

- Create two arrays to store profits
- In profitTillNow store maximum profit till that index
- In profitFromNow store maximum profit from that index
- Then find out the maximum sum of both arrays at an index.

## Optimizations
- Only one array can be used
************************/


