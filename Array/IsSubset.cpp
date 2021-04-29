IsSubset.cpp

//Time complexity: O(n)
//Space complexity: O(n)

string isSubset(int a1[], int a2[], int n, int m) {
    
    unordered_map<int, int> freq;
    
    for(int i =0; i<n; i++){
        freq[a1[i]]++;
    }
    
   for(int i = 0; i < m ; i++){
       if(freq[a2[i]] <= 0){
           return "No";
       }
       freq[a2[i]]--;
   }
   
   return "Yes";
    
}