

void duplicates(string str)
{
    unordered_map<char, int> freq;
    
    int len = str.length();
    for (int i = 0; i < len; i++) {
        freq[str[i]]++;
    }
 
    for (auto it : freq) {
        if (it.second > 1)
            cout << it.first<<" ";
    }
}