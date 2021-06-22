

void rightShift( int*arr, int replace, int index){
	int temp = arr[index];

	for(int i = index-1; i >= replace; i--){
		arr[i+1] = arr[i];
	}

	arr[replace] = temp;
}

void rearrangePositiveNegative (int* arr, int n){

int replace = -1;

for(int i =0; i < n; i++){

	if(replace > -1){
     
     if((arr[replace] >= 0 && arr[i] < 0) || (arr[replace] < 0 && arr[i] >= 0) ){

     	rightShift( arr, replace, i);

     	if(i- replace >= 2){
     		replace += 2;
     	}

     	else {
     		replace = -1;
     	}
     }
	}

	if(replace == -1){
		if((i%2 == 0 && arr[i] >= 0) || (i%2 != 0 && arr[i] < 0)){
			replace = i;
		}

	}
}
}

