

//Median of two sorted arrays of same size

//Time Complexity: O(n)
//Space Complexity: O(1)

 

int getMedian(int arr1[],
              int arr2[], int n)
{
   int i, j , m1, m2, count;
   i = j = m1 = m2 = count =0;


    while(count <= n){
    	if(arr1[i]<= arr2[j]){
    		m1 = m2;
    		m2 = arr1[i];
    		i++;
    	}

    	else if(arr1[i] > arr2[j]){
    		m1 = m2;
    		m2 = arr2[j];
    		j++;
    	}

    	count++;
    }

    return (m1+m2)/2;
}
 
