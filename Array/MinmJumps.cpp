
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