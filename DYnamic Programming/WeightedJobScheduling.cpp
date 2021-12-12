/***** Question: Amazon
 src: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
 ****************/
class Solution {
public:
    
   static bool comp (vector<int>& a , vector<int>&b){
        return a[1] < b[1];
    }
    
    int prevInterval(vector<vector<int>> & jobs, int i){
        int start = 0, end = i -1;
        while(start <= end){
            int mid = (start+end)/2;
            
            if (jobs[mid][1] <=jobs[i][0] ){
                if (jobs[mid+1][1] <= jobs[i][0])
                    start = mid+1;
                else return mid;
            }
            else end = mid-1;
        }
        return -1;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs(n, vector<int>(3));
        
        for (int i =0; i < n; i ++){
          jobs[i] = {startTime[i], endTime[i], profit[i]};
            
        }
        
        sort(jobs.begin(), jobs.end(), comp);

        vector<int> dp(n);
        dp[0] = jobs[0][2];
        
        for (int i =1; i < n; i ++){
            int incProfit = jobs[i][2];
            int ind = prevInterval(jobs, i);
            if (ind != -1){
                incProfit += dp[ind];
            }
            int exProfit = dp[i-1];
            dp[i] = max(incProfit, exProfit);
        }
        
        return dp[n-1];
        
    }
};

/****** APPROACH: DP with Binary Search
Time: O(n*n)/// if array is sorted then O(nlogn)
Src: https://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/

*************/