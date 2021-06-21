
/* Time Complexity :- O(n^2) */

    int minJumps(int arr[], int n){

        if ( n == 0){
            return 0;
        }
        
        if( arr[0] == 0){
            return -1;
        }
        
        
        int steps[n];
        
        for(int i =0; i < n; i++){
            steps[i] = INT_MAX;
        }
        
        steps[0] = 0;
        
        for( int i =0; i < n; i ++){
            for(int j =0; j < i; j++){
                
                if( i <= j + arr[j]){
                    steps[i] = min(steps[i], steps[j]+1);
                }
            }
            
            if(steps[i] > pow(){

                steps[i] = -1;
            }
        }
        
        return steps[n-1];
        
    }
 

 /* Time Complexity : O(n) */

    int minJumps(int arr[], int n){
     
     if(n == 0) return 0;
     if( arr[0] == 0) return -1;
     
     int maxRange = arr[0];
     int steps = arr[0];
     int jumps = 1;
     
     for(int i =1; i < n ; i++){
         if( i == n-1){
             return jumps;
         }
         
         maxRange = max(maxRange, arr[i]+i);
         steps --;
         
         if(steps == 0){
             jumps ++;
             
             if( i >= maxRange) {
                 return -1;
             }
             
             steps = maxRange - i;
         }
     }
     
     return jumps;
        
    }