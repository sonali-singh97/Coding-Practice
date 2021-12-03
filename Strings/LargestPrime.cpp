/*** Prev year Barclays test
 Source: GFG(https://www.geeksforgeeks.org/largest-prime-number-possible-from-a-subsequence-of-a-binary-string/)
 ***/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num){
    if (num <= 1)return false;
    
    for (int i = 2; i*i <= num; i ++){
        if (num%i == 0) return false;
    }
    return true;
}
 // 2^n * n
void largestPrime(string s){
    vector<pair<string, int>> subsequence;
    subsequence.push_back({"", 0});
    int ans = 0;
    int len = s.length();
    for (int i = 0; i < len ; i ++){
        int size = subsequence.size();
        for ( int j =0; j < size; j ++){
            pair<string, int> it = subsequence[j];
            string str = it.first;
            int dec = it.second;
            
            str += s[i];
            if (s[i] == '1') {
                dec = (dec << 1) + 1;
            }
            else dec = (dec << 1);
            
            if (isPrime(dec)){
                ans = max(ans, dec );
            }
            
            subsequence.push_back({str, dec});
        }
    }

    if (ans == 0) {
        cout << -1 << endl;
    }
   else cout << ans<< endl;
    
}

int main()
{
    string s = "1011";
    largestPrime(s);
 
    return 0;
}

/******* APPROACH *****
 - For all subsequence check the decimal notation
 - Create a vector of pair<string, int> containing only one item {"", 0}
 - For ch in string s:
    for it in vector:
        append ch to all it.first
        calculate new decimal value
        check for Prime
        insert in vector
    
    Note: If we are on index "i" of string, then vector contains all the subsequences till i-1.    
        
 **********************/