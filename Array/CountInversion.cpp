CountInversion.cpp

// Method 1: count all numbers smaller that the number at current index
// Complexity : O(n^2)


//Method 2 : Use merge sort technique
//Complexity: O(nlogn)

class Solution{
  public:
  

long long int merge(long long arr[], long long temp[] , long long start, long long end, long long mid){
    
    long long i , j ,k;
    i =start;
    j = mid+1;
    k =start;
    long long int inv_count = 0;
    
    while( i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        
        else {
            inv_count += mid-i+1;
            temp[k++] = arr[j++];
            
        }
    }
    
    while(i <= mid){
        temp[k++] = arr[i++];
        
    }
    
    while(j <= end){
        temp[k++] = arr[j++];
    }
    

    i = start;
    
  while(i <= end){
      arr[i] = temp[i];
      i++;
  }
  
  return inv_count;
    
}

long long int mergeSort(long long arr[], long long temp[], long long start, long long end)

   { 
    if(start == end){
        return 0;
    }
    
    long long mid = (start + end)/2;
    long long int  inv_count =0;
    
    
    inv_count += mergeSort(arr, temp, start , mid ) ;
    inv_count += mergeSort(arr,temp,  mid + 1, end );
    inv_count += merge(arr, temp ,  start , end, mid);
    
    return inv_count;


}



long long int inversionCount(long long arr[], long long N)
{
    long long temp[N];
    return mergeSort(arr, temp , 0 , N-1);
}
   

};