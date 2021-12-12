/****Question: Leetcode hard***
 Src: https://leetcode.com/problems/palindrome-partitioning-ii/
 *******/

class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        vector<vector<bool>> pal(len, vector<bool>(len));
        vector<int> dp(len);
        for (int i =0; i < len; i ++)
            pal[i][i] = true;
        
        for (int i =0; i <len-1; i ++){
            if(s[i] == s[i+1]){
                pal[i][i+1] = true;
            }
            else pal[i][i+1] = false;
        }
        
        int k = 3;
        while(k <= len){
            for(int i = 0; i <= len-k; i ++){
                int j = i+k-1;
                if(s[i] == s[j] && pal[i+1][j-1]) pal[i][j] = true;
                else pal[i][j] = false;
            }
            k++;
        }
        
        dp[0] = 0;
        for (int i =1; i < len; i ++){
            if (pal[0][i]) {
                dp[i] = 0;
                continue;
            }
            int minm = INT_MAX;
            for (int j =i; j > 0; j-- ){
                if (pal[j][i]){
                    int res = 1+ dp[j-1];
                    minm = min(minm, res);
                }
            }
            dp[i] = minm;
            
        }
        
        return dp[len-1];
    }
};

/****** APPROACH******
Time Complexity: O(N*N)
Src: https://youtu.be/qmTtAbOTqcg

-> Make separate array for pallindrome and count.
-> For count make a 1d array, at index 'i' store minm count from 0 to i.
-> For i in count
      if string is pallindrome then count[i] = 0
      else
        check every suffix, if pallindrome
            then update minm value in variable (1 + count[suffixStart -1])
         count[i] = minm
-> Return count[len-1] 

2. Another DP arroach: n^3
3. Recursion: (n*2^n) or n! *n

*********************/
