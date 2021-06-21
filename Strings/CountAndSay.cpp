
    string helperFn (string str){
        string output = "";
        int len = str.length();
        int i =0;
        
        while(i < len){
            int count = 1;
            char prev = str[i];
            i++;
            
            while(i < len && str[i] == prev){
                count ++;
                i ++;
            }
            
            output += to_string(count);
            output += prev;
        }
        
        return output;
    }
    
    string countAndSay(int n) {
        
        if(n==1){
            return "1";
        }
            
        int curr = 1;
        string no = "1";
        while( curr < n){
            no = helperFn(no);
            curr ++;
        }
            
        return no;
    }