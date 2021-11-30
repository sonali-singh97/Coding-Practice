/***
 Leetcode Problem 1048 : https://leetcode.com/problems/longest-string-chain/
***/


/* Complexity: O(n*l^2 + n*l) = O(n*l^2) */
class Solution {
public:
     /* O(n*l) => n nodes and every node can have atmost l edges */
    int maxLength(string src, unordered_map<string, vector<string>>& graph, unordered_map<string, int>& count  ){
        if (count[src]) return count[src];
        count[src] = 1;
        int maxm = 1;
        for (auto node : graph[src] ){
            maxm = max(maxm, maxLength(node, graph, count) + 1 );
        }
        
        count[src] = maxm;
        return maxm;
    }
    
    int longestStrChain(vector<string>& words) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, bool> nodes;
        
        for (auto it : words){  // n
            nodes[it] = true;
        }
        
        for (auto it : words){ // n*l*l
            int len = it.length();
            for (int i =0; i < len ; i ++){
                string temp = it.substr(0, i) + it.substr(i+1);
                if (nodes[temp]){
                    graph[it].push_back(temp);
                   }
            }
        }
        
        
        unordered_map<string, int> count;
        int maxm = 0;
        for (auto it : words){ 
            if (!count[it])
            {
                maxm = max(maxm,  maxLength(it, graph, count));
            }
        }
     
        return maxm;
    }
    
    /***** APPROACH*******
    Video : https://youtu.be/zqe_zIkyVGQ
    
    Graph Question: find the longest path between nodes
    Convert to graph, for every string
    1. Add 'a-z' to all positions  (n*l*26*l)
    2. Drop letter at each position one by one and check (n*l^2)
    
    Maintain a count hashmap for memoization and run dfs to find maxm path length
    **********************/
};