

//Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo

//Dutch National Flag Algorithm

#include<iostream>
#include<algorithm>
using namespace std;


void sortArray(int * arr , int n){
	int low=0;
	int mid=0;
	int high=n-1;

	while(mid<=high){
		if(arr[mid]==0){
			swap(arr[low], arr[mid]);
			low++;
			mid++;
		}
		else if(arr[mid]==2){
			swap(arr[mid], arr[high]);
			high--;
		}

		else{
			mid++;
		}
	}
}

int main(){
	int n;
	cin>>n;
	int*arr = new int(n);

	for(int i=0;i<n ; i++){
		cin>>arr[i];
	}

	sortArray(arr, n);

	for(int i=0; i<n ; i++){
		cout<<arr[i]<<" ";
	}
}
