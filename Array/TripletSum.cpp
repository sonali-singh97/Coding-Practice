  bool find3Numbers(int arr[], int n, int X)
{ 
   

   sort(arr, arr+n);
    
     for(int k =0; k< n-2 ; k++){
        int i = k+1;
        int j = n-1;
        while(i<j){
            int sum = arr[k]+arr[i]+arr[j];
            if( sum == X){
                return 1;
            }
            
            else if (sum > X){
                j--;
            }
            else{
                i++;
            }
        }
        return 0;
}

}
