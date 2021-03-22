


//Time complexity
//Iterative Method :O(n)
//Tournament Method:O(n)
//Compare in pairs: O(n)



#include<iostream>
using namespace std;

struct Pair{
	int max;
	int min;
};

struct Pair getMaxMin(int * arr , int n){

struct Pair minmax ;
int i;

if(n%2==0){
	if(arr[0]<arr[1]){
		minmax.max = arr[1];
		minmax.min = arr[0];
	}

	else{
		minmax.max = arr[0];
		minmax.min = arr[1];
	}

	i=2;
}
else{
	minmax.max= arr[0];
	minmax.min = arr[1];
	i=1;
}

while(i<n-1){

	if(arr[i]>arr[i+1]){

		if(arr[i] > minmax.max){
			minmax.max= arr[i];
		}

		if(arr[i+1] < minmax.min){
			minmax.min= arr[i+1];
		}
	}

	else{
		if(arr[i+1] > minmax.max){
          minmax.max = arr[i+1];
		}

		if(arr[i] < minmax.min){
          minmax.min = arr[i];
		}
	}
	i+=2;
}

return minmax;

}

int main(){
	
	int n;
	cin>>n;

	int*arr = new int(n);

	for(int i=0;i<n ; i++){
		cin>>arr[i];
	}

	Pair result = getMaxMin(arr, n);

    cout<< result.max<<endl;
    cout<< result.min ;
}


// Tournament method(recursive):
// - Divide the array in two half
// - Compare the max and min of both half and the max and min of whole array
