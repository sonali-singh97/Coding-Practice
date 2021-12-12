
// Question: 450 list
// Src: https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool isPallindrome(string s){
        int len = s.length();
        
        int i =0, j = len-1;
        
        while(i < j){
            if (s[i]!= s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;  
    }
    
    void partitionHelper(string s, vector<string>& curr, vector<vector<string>>& output ){
        int len = s.length();

        if(len == 0){
            output.push_back(curr);
            return;
        }
        
        for (int i =1; i <=len; i ++){
           if(isPallindrome(s.substr(0,i))){
               curr.push_back(s.substr(0,i));
               partitionHelper(s.substr(i), curr, output);
               curr.pop_back();
           }
        }
        
        return ;
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> pal;
        partitionHelper(s, curr, pal);
        return pal;
    }
};

/***Approach****
Time Complexity: O(n* (2^n));
-> Check for all palindromic prefix and then recursively call on rest of the string
***************/
