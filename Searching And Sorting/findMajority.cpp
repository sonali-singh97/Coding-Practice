  
//   Moore's Voting algorithm
  
   bool isMajority(int a[], int size, int ele){
        int freq =0;
        for(int i =0; i < size; i++){
            if(a[i] == ele){
                freq++;
            }
        }
        
        if(freq > size/2)
            return true;
            
        return false;
   }
    
    int majorityElement(int a[], int size)
    {
         int count = 0;
         int ele = 0;
    
        for(int i =0; i < size; i++){
        if(count == 0)
            ele = a[i];
        
        if(ele == a[i])
          {  count ++;}
        
        else count--;
        
        }

       if(isMajority(a, size, ele))
            return ele;
       
       return -1;
        
    }