

// Reverse the given array

// Time Complexity
// Using Iteration: O(n)
// Using Recusrsion : O(n)


//code

void reverseArray(int*arr, int start, int end){
	if(start>=end)
	return;

	int temp = arr[start];
	arr[start] = arr[end];
	arr[end]= temp;

	reverseArray(arr, start+1 , end-1);
}



