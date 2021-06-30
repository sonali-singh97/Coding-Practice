    //Second most repeated string in a sequence 
    
    string secFrequent (string arr[], int n)
    {
        unordered_map<string, int> freq;
        int count = 0;
        int max = 0;
        int secondmax =0;
        
        for(int i =0; i <n; i++){
                freq[arr[i]]++;
        }
        
        for(auto x : freq){
           if(x.second > max){
               secondmax = max;
               max = x.second;
           }
           
           else if(x.second > secondmax && x.second != max){
               secondmax = x.second;
           }
        }
        
       for(auto x : freq){
           if(x.second == secondmax){
             return x.first;
           }
        }
        
        return "";
    }