CountOccurence.cpp

//Time complexity: O(n)
//space complexity: O(n)


// Function to find elements with count more than n/k times
// arr: input array
class Solution{
  public:
    int countOccurence(int arr[], int n, int k) {
        // Your code here
        
        int no = n/k;
        unordered_map<int, int>  frequency;
        
        for(int i =0 ; i< n ; i++){
            frequency[arr[i]]++;
        }
        
        int count =0;
        for(auto x : frequency){
            if(x.second > no){
                count++;
            }
        }
       return count; 
        
    }
};