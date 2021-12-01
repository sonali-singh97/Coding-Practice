/** Striver list
 link: https://www.geeksforgeeks.org/print-subsequences-string-iterative-method/
**/

#include <bits/stdc++.h>
using namespace std;

 // O(2^n * n)
void printSubsequences(string s){
    int n = s.length();
   for(int i =0; i < (1 << n) ; i ++){
       string temp = "";
       for (int j =0; j < n; j ++){
           if (i & (1 << j)){
               temp += s[j];
           }
       }
       cout << temp << " ";
   } 
   cout << endl;
}

// O(2^n * b) b = no. of set bits in i
// count only set bits
void optimizeApproach(string s){
   int n = s.length();
   for(int i =0; i < (1 << n) ; i ++){
       string str = "";
       int temp = i;
      while(temp > 0){
          int mask = temp & (-temp);
          int pos = log2(mask);
          str+= s[pos];
          temp -= mask;
          
      }
       cout << str << " ";
   }  
}

int main() {
    string s;
    s = "abc";
    printSubsequences(s);
    optimizeApproach(s);
	return 0;
}

/****** APPROACH **
 for number betwen 0 to 2^n - 1:
    for i in number
        if bit is on 
            include corresponding character
 ***************/