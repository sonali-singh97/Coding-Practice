MergeIntervals.cpp

//Complexity : O(nlogn)

class Solution {
public:
    
 
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int index = 0;
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
{
     return a[0] <  b[0];
});
        
        for(int i =0; i< n ; i++){
            if( intervals[index][1] >= intervals[i][0]){
                 intervals[index][1] = max(intervals[i][1] , intervals[index][1]);
                
                
            }
            else{
                index ++;
                intervals[index] = intervals[i];
            }
        }
        intervals.erase(intervals.begin()+index+1 , intervals.end());
        return intervals;
        
    }
};