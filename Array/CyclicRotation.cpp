


#include<iostream>
using namespace std;

void reverseArray(int*arr, int start, int end){
	

	   while (start < end) { 
        int temp = arr[start]; 
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    } 
}


void rotateArray(int* arr , int n , int k){

	k= k % n;

reverseArray(arr, n-k, n-1);

reverseArray(arr , 0 , n-k-1);

reverseArray(arr, 0, n-1);

}

int main(){
	int n;
	cin>>n;
	int*arr = new int(n);

	for(int i=0;i<n ; i++){
		cin>>arr[i];
	}
	int k;
	 cin>>k;

	rotateArray(arr, n , k);

	for(int i=0; i<n ; i++){
		cout<<arr[i]<<" ";
	}
}


