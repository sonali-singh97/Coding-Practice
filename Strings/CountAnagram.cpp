        bool comp(vector<int> pat, vector<int> txt){

        for(int i = 0; i < 256; i++){
          if(pat[i] != txt[i])
          {
            return false;
          }
        }
        return true;
    }
	int search(string p, string t) {

    int c = 0;
    int len1 = p.length();
    int len2 = t.length();
    
      if(len1 < 0 || len2 < 0 || len1 > len2){
        return c;
      }
    vector<int> txt(256, 0);
     vector<int> pat(256, 0);;
      
    for(int i = 0 ; i < len1 ; i++){
          (pat[p[i]])++;
          (txt[t[i]])++;
      }
   
      for(int i = len1; i < t.length();i++){
          if(comp(pat,txt))
          {
            c++;
          }
          txt[t[i]]++;
          txt[t[i-len1]]--;
         
      }
        
      if(comp(pat,txt)){
         c = c + 1;
      }
    return c; 
	}