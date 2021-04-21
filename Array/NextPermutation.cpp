NextPermutation.cpp

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int minIndex = -1;
        int n = arr.size();
        
        for(int i = n-1; i >= 1; i--){
            if(arr[i-1] < arr[i]){
                minIndex = i-1;
                break;
            }
        }
        
        if(minIndex == -1){
               return ;
        }
        
        int next_lg = minIndex;
        
        for(int i = n-1 ; i>=minIndex ; i--){
            if(arr[i] > arr[minIndex] ){
                next_lg = i;
                break;
            }
        }
        
        int temp = arr[next_lg];
        arr[next_lg] = arr[minIndex];
        arr[minIndex] = temp;
        
        int i = minIndex+1;
        int j = n-1;
        
        while(i!=j){
         temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
            i++;
            j--;
        }
        
        
    }
};