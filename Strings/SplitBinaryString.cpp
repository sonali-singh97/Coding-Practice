

/* Split the binary string into substrings with equal number of 0s and 1s */

int maxmSubstr(string str){
	int n = str.length();

	int coun0 = 0;
	int count1 = 0;
	int total = 0;

	for(int i =0; i < n; i++){
		if(str[i] == 0){
			count0 ++;
		}
		else {
			count1 ++;
		}

		if(count0 == count1){
			total ++;
		}
	}

	return total;

}