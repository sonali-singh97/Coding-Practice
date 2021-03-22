

#include<iostream>
#include<queue>
using namespace std;

struct Pair {
	int max;
	int min;


};


struct Pair getMaxMin( int*arr, int n, int k){

  priority_queue<int> maxQueue;
 priority_queue<int, vector<int> , greater<int> > minQueue;
  Pair minmax ;

 for(int i =0;i<k; i++){
 	maxQueue.push(arr[i]);
 	minQueue.push(arr[i]);
 }

 for(int i=k; i<n;i++){

 	int minTop= minQueue.top();
 	int maxTop = maxQueue.top();

    if(arr[i] > minTop){
    	minQueue.pop();
    	minQueue.push(arr[i]);
    }

    if(arr[i] < maxTop){
    	maxQueue.pop();
    	maxQueue.push(arr[i]);

    }
 }


 minmax.min = maxQueue.top();
 minmax.max = minQueue.top();


  return minmax;

}


int main(){
		int n,k;
	cin>>n>>k;

	int*arr = new int(n);

	for(int i=0;i<n ; i++){
		cin>>arr[i];
	}

	Pair result = getMaxMin(arr, n,k);

    cout<< result.max<<endl;
    cout<< result.min ;
}