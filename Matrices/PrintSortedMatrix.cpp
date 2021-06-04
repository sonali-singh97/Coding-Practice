
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        
        int arr[N*N];
        int index =0;
        
        for(int i =0; i<N ; i++){
           for(int j =0; j<N ; j++){
               arr[index++] = Mat[i][j];
           }
        }
        
        sort(arr, arr+index);
        
        index =0;
        for(int i =0; i< N;i++ ){
            for(int j =0; j <N ; j++){
                Mat[i][j] = arr[index++];
            }
        }
        
        return Mat;
    }