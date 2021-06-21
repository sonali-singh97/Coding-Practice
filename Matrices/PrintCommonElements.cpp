
void printCommonElements(  int m, int n , int** mat){
    unordered_map<int, int> freq;

    for(int i =0; i < m; i ++){
        for(int j =0; j < n; j++){
            
            if(freq[mat[i][j]] == i){
                freq[mat[i][j]]++;
            }
            
            if(freq[mat[i][j]] == m-1){
                cout << mat[i][j]<<" ";
            }
        }
    }
}
