
#include<iostream>
using namespace std;


int maxSum(int*arr , int n){
 int max= arr[0];

 for(int i=1; i<n; i++){
 	arr[i]+= arr[i-1];
 	if(arr[i]> max){
 		max=arr[i];
 	}
 }



 for(int i =0; i<n-1 ; i++){
 	for(int j= i+1 ; j<n ; j++){
 		int val = arr[j]- arr[i];

 		if(val>max){
 			max=val;
 		}

 		 	}
 }

 return max;

}

int main(){
	int n;
	cin>>n;
	int*arr = new int[n];

	for(int i=0;i<n ; i++){
		cin>>arr[i];
	}
	

	cout << maxSum(arr, n );

}
