

#include<iostream>
#include<vector>
using namespace std;

void printResult(int* arr1, int* arr2, int n , int m){
 int i,j,k;
 i=j=k=0;

 vector<int> unionArray;
 vector<int> intersection;

while(i<m && j<m){
	if(arr1[i]> arr2[j]){
		unionArray.push_back(arr2[j]);
		j++;
	}

	else if(arr1[i] < arr2[j]){
		unionArray.push_back(arr1[i]);
		i++;
	}

	else{
		intersection.push_back(arr1[i]);
		unionArray.push_back(arr1[i]);
		i++;
		j++;
	}

}

while(i<n){
	unionArray.push_back(arr1[i++]);
}

while(j<m){
	unionArray.push_back(arr2[j++]);
}

int l1= unionArray.size();
int l2= intersection.size();

for(int p=0; p<l1 ; p++){
	cout<<unionArray[p] <<" ";
}

cout<<endl;

for(int p=0; p<l2 ; p++){
	cout<<intersection[p] <<" ";
}




}


int main() 
{ 
    int arr1[] = {1, 3, 4, 5, 7}; 
    int arr2[] = {2, 3, 5, 6} ;
  
    int m = sizeof(arr1) / sizeof(arr1[0]); 
    int n = sizeof(arr2) / sizeof(arr2[0]); 
  
    printResult(arr1, arr2, m, n); 
  
    return 0; 
}

