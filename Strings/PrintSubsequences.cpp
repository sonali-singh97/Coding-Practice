PrintSubsequences.cpp

void printSubsequence(string str, string output){

	if(str.empty()){
	cout << output << endl;
	return;
	}

	printSubsequence(str.substr(1), output + str[0]);

	printSubsequence(str.substr(1), output );
}