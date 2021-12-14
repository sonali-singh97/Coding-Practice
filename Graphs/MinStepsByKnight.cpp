/**Question: 450 list 
  Src: https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#
***/


    int dx[8]= {2, 2, -2, -2, -1, -1, 1,1};
    int dy[8] = {-1, 1, -1, 1, 2, -2, 2,-2};
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	      queue<pair<int, int>>q;
	      vector<vector<bool>> visited(N+1, vector<bool>(N+1));
	      int steps = 0;
	      int startX =  KnightPos[0], startY = KnightPos[1];
	      q.push({startX, startY});
	     visited[startX][startY] = true;
	      
	      while(!q.empty()){
	         int currSize = q.size();
	         
	         while(currSize--){
	            int x = q.front().first;
	            int y = q.front().second;
	            q.pop();
              
	         if (x == TargetPos[0] && y == TargetPos[1]) return steps;
	          for (int i =0; i < 8 ; i ++){
	              int newx = x + dx[i];
	              int newy = y + dy[i];
	              if( newx > 0 && newx <=N && newy >0 && newy<=N&& !visited[newx][newy]){
	                  visited[newx][newy] = true;
	                  q.push({newx, newy});
	              }
	          }
	         }
	          steps++;
	      }
	   
	   return steps;
	      
	}
	
	/****Aproach***
	 - Use BFS to find out minimum distance
	 Time: O(n*n)
	 Space: O(n*n)
	 *************/