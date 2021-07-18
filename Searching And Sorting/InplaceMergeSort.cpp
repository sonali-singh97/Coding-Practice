
#include <iostream>
#include<algorithm>
using namespace std;


void merge (int arr[], int l, int r){
    int gap = (int)ceil((r-l+1)/2.0);
    
    while( gap > 0){
        for (int i = 0; i + gap <= r; i++ ){
             int j = i + gap;
            if( arr[i] > arr[j]){
                int temp= arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        
        if(gap <=1)
            break;
        else 
            gap = (int)ceil(gap/2.0);

    }
    
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, r);
    }
}
 
int main()
{
     int n;
     cin >> n ;
     
     int nums[n];
    
     for (int i = 0; i < n; i++) {
        cin >> nums[i] ;
    }
 
    mergeSort(nums, 0, n - 1);
 
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
