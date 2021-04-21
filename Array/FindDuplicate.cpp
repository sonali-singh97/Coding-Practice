

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n= arr.size();
        
        unordered_map<int, bool> freq;
        int val;
        
        for(int i=0; i<n; i++)
        {
            if(freq.find(arr[i]) == freq.end()){
              
                 freq[arr[i]] = true;
            }
            
             else  {
                 val = arr[i];
                 break;
             } 
            
                   }
        
        return val;
    }
};