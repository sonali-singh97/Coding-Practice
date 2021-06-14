
/*
Print all the duplicates in the input string 
*/

void prinrDuplicates(string str)
{
    map<char, int> count;
    int len = str.length();
    for (int i = 0; i < len; i++) {
        count[str[i]]++;
    }
 
    for (auto it : count) {
        if (it.second > 1)
            cout << it.first << " ";
    }
    cout<<endl;
}