//Longest Common Subsequence

    int lcs(int x, int y, string s1, string s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        
        vector<vector<int>> mat (len1+1, vector<int>(len2+1, 0));
        
        for(int i = 1; i < len1+1; i ++){
            for(int j =1; j <len2+1; j++){
                if(s1[i-1] == s2[j-1]){
                    mat[i][j] = mat[i-1][j-1] +1;
                }
                else{
                    mat[i][j] = max(mat[i-1][j-1], max(mat[i-1][j], mat[i][j-1]));
                }
            }
        }
        
        return mat[len1][len2];
    }
};