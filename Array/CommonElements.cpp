CommonElements.cpp

class Solution
//need changes
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
           vector<int> common;
           
           int i, j,k;
           i = j = k = 0;
           
           while(i < n1 && j < n2 && k < n3){
               if(A[i] == B[j] && B[j] ==  C[k]){
                //push only elemnts which are not present
                   common.push_back(A[i]);
                   i++;
                   j++;
                   k++;
               }
               
              else if( A[i] < B[j]){
                   i++ ;
               }
               
               else if(B[j] < C[k]) {
                   j++;
               }
               
               else{
                   k++;
               }
           }
           
            return common;
        }

};
