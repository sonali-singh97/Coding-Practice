

    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int, int> freq;
        int pairs = 0;
        
        for(int i =0; i < n; i++){
            freq[arr[i]]++;
        }
        
        for(int i =0; i< n; i++){
            if(freq.find(k -arr[i]) != freq.end()){
                if(k == 2*arr[i]){
                   pairs += freq[k-arr[i]]- 1;
                }
                
                else pairs += freq[k-arr[i]];
            }
            
            freq[arr[i]]--;
        }
        
        return pairs;
    }