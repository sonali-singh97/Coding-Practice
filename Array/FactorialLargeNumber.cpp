
//Factorials of large numbers

   void multiply(vector<int> &ans, int no){
       int len = ans.size();
       int carry = 0;
       
       for(int j =0; j < len; j++){
           int val = ans[j] * no;
           ans[j] = (carry + val)%10;
           carry = (carry+val)/10;
       }
       
       while(carry){
           ans.push_back(carry%10);
           carry = carry/10;
       }
       
   }
   
    vector<int> factorial(int n){
        vector<int> ans;
        ans.push_back(1);
        if(n==1){
            return ans;
        }
        
        for(int i =2; i <=n; i++){
            multiply(ans, i);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }