ThreeWayPartition.cpp

// Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
// 1) All elements smaller than a come first.
// 2) All elements in range a to b come next.
// 3) All elements greater than b appear in the end.
// The individual elements of three sets can appear in any order. You are required to return the modified array

// Time Complexity : O(N)
// Space Complexity : O(1)

void threeWayPartition(int arr[], int n, int a, int b)
{
   int l , m , h;
   l=m=0;
   h= n-1;
   
   while(m<=h){
      if(arr[m] <a){
         int temp = arr[m];
         arr[m] = arr[l];
         arr[l] = temp;
          l++;
          m++;
          
      }
      else if(arr[m]>b){
          int temp = arr[m];
          arr[m] = arr[h];
          arr[h] = temp;
          h--;
      }
      
      else{
          m++;
      }
   }
}