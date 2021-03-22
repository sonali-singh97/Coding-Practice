
//Move all the negative elements to one side of the array 

 #include<iostream>
#include<algorithm>
using namespace std;


void moveElements(int * arr , int n){
 int i =0;
 int j = n-1;

 while(i<j){
 	while(arr[i]<0 && i<j){
 		i++;
 	}

 	while(arr[j]>=0 && j>i){
 		j--;
 	}

 	swap(arr[i], arr[j]);
 	i++;
 	j--;
 }


return;

}

int main(){
	int n;
	cin>>n;
	int*arr = new int(n);

	for(int i=0;i<n ; i++){
		cin>>arr[i];
	}

	moveElements(arr, n);

	for(int i=0; i<n ; i++){
		cout<<arr[i]<<" ";
	}
}
