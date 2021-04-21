
#include<iostream>
#include<climits>
using namespace std;


int minDiff(int*arr , int n, int k){
 
  int min= INT_MAX;
  int max= INT_MIN;

  for(int i =0; i<n ; i++){

  	if(arr[i]>max)
  		max= arr[i];

  	if(arr[i]<min)
  		min=arr[i];
  }
  
  return max-min-2*k;
}

int main(){
	int n,k;
	cin>>n;
	int*arr = new int[n];

	for(int i=0;i<n ; i++){
		cin>>arr[i];
	}

    cin>>k;
	

	cout << minDiff(arr, n ,k);

}