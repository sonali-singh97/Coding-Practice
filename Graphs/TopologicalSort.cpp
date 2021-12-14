/**Question: 450 list 
  Src: https://practice.geeksforgeeks.org/problems/topological-sort/1 ***/

void topoHelper(vector<int> adj[], vector<bool>& visited, stack<int>&st, int src){
	   visited[src]= true; 
	   
	   for(auto it : adj[src]){
	       if(!visited[it]){
	           topoHelper(adj, visited, st, it);
	       }
	   }
	   
	   st.push(src);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V);
	    vector<int> output;
	    stack<int> topo;
	    
	    for(int i =0; i <V; i ++){
	        if(!visited[i]){
	            topoHelper(adj, visited, topo, i);
	        }
	    }
	    
	    while(!topo.empty()){
	        output.push_back(topo.top());
	        topo.pop();
	    }
	    
	    return output;
	}