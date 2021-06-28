// Convert a sentence into its equivalent mobile numeric keypad sequence

#include <iostream>
using namespace std;

string numericKeypad (string* arr, string input){

int len = input.length();
string output = "";

if(len ==0){
    return output;
}

for(int i =0; i < len; i++){
    if(input[i] == ' '){
        output += "0";
    }

    else {
        int index = input[i] - 'A';
        output += arr[index];
    }
}

return output;
}

int main(){
    string input;
    getline(cin, input);

    string keys[] ={"2","22","222",
                    "3","33","333",
                    "4","44","444",
                    "5","55","555",
                    "6","66","666",
                    "7","77","777","7777",
                    "8","88","888",
                    "9","99","999","9999"
                   };

    cout << numericKeypad(keys, input);
}