PalindromeString.cpp

//Find whether the string is a pallindrome or not

class Solution{
public:	
	
	
	int isPlaindrome(string S)
	{
	    // Your code goes here
	
    int len = S.length();
    
    int i =0;
    int j = len-1;
    
    while(i<=j){
        if(S[i]!= S[j]){
            return 0;
        }
        i++;
        j--;
    }
    
    return 1;

	}

};