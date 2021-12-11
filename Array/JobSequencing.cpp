/*** Question: Amazon
 src: https://www.geeksforgeeks.org/job-sequencing-problem/
 * ******/

#include<bits/stdc++.h>
using namespace std; 
typedef pair<int, int> pd;

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp (Job A, Job B){
        return A.dead < B.dead;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    {   
        sort(arr, arr + n, comp);
        
        priority_queue<pd, vector<pd>, greater<pd> >pq;
        for (int i =0; i < n; i ++){
             pq.push({arr[i].profit, arr[i].id});
             while(pq.size() > arr[i].dead)
                pq.pop();
        }
        
        vector<int> ans;
        ans.push_back(pq.size());
        int profit = 0;
        while(!pq.empty()){
        profit += pq.top().first;
        pq.pop();
        }
        ans.push_back(profit);
        return ans;
       
    } 
};

/*****APPROACH*******
 Time Complexity : O(nlogn)
 - Sort the array according to deadline
 - Make a min priority queue
 - Loop over array
        store the element in min queue
        while minQueue.size > cuurDeadline 
            pop out elemnets from queue
- Queue contains the required job ids.
 ********************/