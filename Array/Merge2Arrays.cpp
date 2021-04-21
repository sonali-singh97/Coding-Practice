

//Merge 2 sorted arrays without using Extra space.


// Gap method
//complexity - nlogn

#include<iostream>
using namespace std;

void mergeArrays(int gap, int* arr1, int* arr2, int m, int n){

	if(gap ==1)
		return;

 int newGap = (int)gap/2 + gap%2;

 int i =0;
 for(i=0; i+gap < m ; i++) {
 	if(arr1[i] > arr1[i+gap]){
 		int temp = arr1[i];
 		arr1[i] = arr1[i+gap];
 		arr1[i+gap] = temp;
 	}

}
int j;
 for( j = gap > m ? gap-m : 0 ; i<m && j<n ; i++, j++ ){
    	if(arr1[i] > arr2[j]){
 		int temp = arr1[i];
 		arr1[i] = arr2[j];
 		arr2[j] = temp;
 	}
      
 }

 if(j<n){

 	 for(j=0; j+gap<n; j++){
 	    if(arr2[j] > arr2[j+gap]){
 		int temp = arr2[j];
 		arr2[j] = arr2[j+gap];
 		arr2[j+gap] = temp;
 	}

 	 }
 }



 mergeArrays(newGap , arr1 , arr2, m,  n);

}

int main(){
	int arr1[]= {0, 1, 2, 7};
	int arr2[] = {5 , 6, 7 , 8 , 9};
    
	int m = 4;
	int n = 5;

	 mergeArrays(m+n, arr1 , arr2, m, n);

	 for(int i=0; i<m ; i++){
       cout<<arr1[i]<<" ";
	 }
	 for(int j =0; j<n ; j++ ){
	 	cout<<arr2[j]<<" ";
	 }

}

// 1.Traverse arr1 and compare each element of arr1 to the first element of the arr2.
// 2. If arr1[i] > arr2[j],  then we will swap both the elements and place the new element in arr2 to its correct position .
// 3. If the first element of arr2 is not smaller than the current element of arr1, then we will move to the next element of arr1.

//complexity: O(n)



