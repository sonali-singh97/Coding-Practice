
bool checkRotation(string str1, string str2){
    
    if(str1.length() != str2.length()){
       return 0;
    }

    string target = str1 + str1;
    
    if(target.find(str2) != string::npos){
        return 1;
    }
    
    return 0;
}