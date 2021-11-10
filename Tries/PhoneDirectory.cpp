class Trie {
    public:
    bool isLast;
    Trie* child[26];
    Trie (){
        isLast = false;
        for (int i =0; i < 26; i ++){
            this->child[i] = NULL;
        }
    }
    
};

  Trie * root = new Trie();
  
  void insert( string s){
      int len = s.length();
      Trie * node = root;
      for (int i =0; i < len ; i ++){
          int ind = s[i] - 'a';
          
          if (node->child[ind] == NULL){
              node->child[ind] = new Trie();
          }
          node = node->child[ind];
          
      }
     if (len) node -> isLast = true;
      
  }
   
   void displayContactsUtil(Trie* prev, string pre, vector<string>& ans){
       if(prev->isLast) {
          ans.push_back(pre);
       }
       
       for(int i =0; i < 26; i ++){
           if (prev->child[i]!= NULL){
               displayContactsUtil(prev->child[i], pre+ char(i+ 'a'), ans);
           }
       }
   }
   
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
      for (int i =0; i < n; i ++){
          insert(contact[i]);
      }
       
       Trie * prev = root;
       int len = s.length();
       string prefix = "";
       vector<vector<string>> ans(len);
       int i;
      for ( i =0; i < len; i ++){
          prefix += s[i];
          int ind = s[i] - 'a';
          if (prev -> child[ind] == NULL) break;
          prev = prev->child[ind];
          displayContactsUtil(prev, prefix, ans[i]);
      }
    
      while(i < len) {
         ans[i++].push_back("0");
      }
      
      return ans;
    }
