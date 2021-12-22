/*** Question: 450 list
 Src: https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1
 ***/

   long long countWays(int n, int k){
        if (n ==1) return k;
        int mod =1000000007;
       long long same = k*1;
       long long diff= (k* (k-1)) % mod;
        long long total = same + diff;
        
        for (int i = 3; i <= n; i ++){
            same = diff;
            diff = (total * (k-1)) % mod;
            
            total = (same+ diff)%mod ;
        }
        
        return total;
    }
};

/*****APPROACH*****
 DP problem
 Time: O(n)
 Solution: https://youtu.be