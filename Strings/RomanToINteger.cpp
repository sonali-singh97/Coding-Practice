int romanToDecimal(string &str) {
    int output = 0;
    int len = str.length();
    
  map<char, int> values = {{'I', 1}, {'V', 5},{'X', 10},{'L', 50},
  {'C', 100},{'D', 500},{'M', 1000}};
  
    for(int i =0; i < len ; i++){
     if(values[str[i]] >= values[str[i+1]]){
         output +=values[str[i]];
     }
     
     else output -= values[str[i]];
    }
    
    return output;
}