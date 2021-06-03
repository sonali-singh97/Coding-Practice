
 vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {

    int ri, re, ci, ce;
    ri = re = ci = ce = 0;
    
    re = r;
    ce = c;

    vector<int> result;
    
    while ( ri < re && ci < ce){
        
        for(int i = ci ; i < ce ; i++){
            result.push_back(matrix[ri][i]);
        }
        ri++;
        
          for(int j = ri ; j < re ; j++){
           result.push_back(matrix[j][ce - 1]);
        }
        ce--;
        
        if(ri < re){
          for(int i = ce-1 ; i >= ci ; i--){
           result.push_back(matrix[re-1][i]);
        }
        re--;
        
        }
        
        if(ci < ce){
          for(int j = re-1 ; j >= ri ; j--){
           result.push_back(matrix[j][ci]);
        }
        ci ++;
        }
    }
   
     return result;
        
    }