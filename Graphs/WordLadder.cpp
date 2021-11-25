class Solution {
public:
    
    bool isSafe(string curr, string next){
        
        if(curr == next ) return false;
        int len = curr.size();
        int i =0, freq = 0;
        while(i < len){
            if (curr[i] != next[i]) freq++;
            if (freq > 1) return false;
            i++;
        }
        
        return true;
    }
    
    int minLadderHelper(string curr, string endWord, unordered_set<string>& words){
        int  length = 0;
        queue<string> q;
        q.push(curr);
        while(!q.empty()){
            int size = q.size();
            length++;   
            while(size--){
            string str = q.front();
            q.pop();
           
            int lenS = str.length();
            for (int i =0; i < lenS; i ++){
                string temp = str;
                for (char j = 'a'; j <= 'z'; j ++){
                    temp[i] = j;
                    if (temp == str)continue;
                     if(temp == endWord) return length+1;
                    if (words.find(temp)!= words.end()){
                        cout << temp <<" "<<str<<endl;
                        q.push(temp);
                        words.erase(temp);
                    }
                }
            }
           
            }
            
        }

        return 0;
          
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> words;
        bool isPresent = false;
        for (auto it : wordList){
            words.insert(it);
            if (it == endWord)isPresent = true;
        }
       
        if (!isPresent) return 0;
        
        return minLadderHelper(beginWord, endWord, words);
        
    }
};