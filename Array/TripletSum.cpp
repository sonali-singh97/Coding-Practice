 
/*Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.
Time Complexity: O(n)
Space Complexity: O(1)
*/


  bool find3Numbers(int arr[], int n, int X)
{ 
   sort(arr, arr+n);
    
     for(int k =0; k< n-2 ; k++){
        int i = k+1;
        int j = n-1;
        while(i<j){
            int sum = arr[k]+arr[i]+arr[j];
            if( sum == X){
                return true;
            }
            
            else if (sum > X){
                j--;
            }
            else{
                i++;
            }
        }
}
 return false;
}