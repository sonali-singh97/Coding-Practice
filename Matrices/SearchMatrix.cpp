
    bool searchMatrix(vector<vector<int>>& matrix, int target) {   
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(target < matrix[0][0] || target > matrix[m-1][n-1]){
            return false;
        }
        
        int row;
        for ( int i =0 ; i< m-1; i++ ){
            if(target >= matrix[i][0] && target <= matrix[i][n-1] ){
                row =i;
                break;
            }
        }
        
        int start =0;
        int end = n-1;
        
        while(start <= end) {
            int mid = (start + end)/2;
            
            if(matrix[row][mid] == target)
                return true;
            
            else if(matrix[row][mid] > target)
                end = mid-1;
            
            else start = mid+1;
        }
        
        return false; 
    
    }