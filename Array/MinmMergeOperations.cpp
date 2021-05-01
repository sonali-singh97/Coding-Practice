

//Find minimum number of merge operations to make an array palindrome

//Time Complexity: O(n)
//Space Complexity: O(n)

int findMinOps(int arr[], int n){

	int count =0;
    int i = 0;
    int j = n-1;

    while(i<=j){
    	if(arr[i] == arr[j]){
    		i++;
    		j--;
    	}

    	else if(arr[i] > arr[j]){
    		arr[j-1] += arr[j];
    		j--;
    		count++;
    	}

    	else{
    		arr[i+1] += arr[i];
    		i++;
    		count++;
    	}
    }

    return count;

}

