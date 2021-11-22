   int dx[4] = {0,0, 1, -1};
   int dy[4] = {1, -1, 0, 0 };
   char dir[4] = {'R', 'L', 'D', 'U'};
    
    
   void findPathHelper(vector<vector<int>>& grid, int n , vector<vector<bool>> &visited, int x, int y, string path, vector<string> &output)
    {
       if (grid[x][y] == 0){
          return;
      }
      
      if (x == n-1 && y == n-1)   {
          output.push_back(path);
          return;
      }
      
      
      visited[x][y] = true;
      
      for (int i =0; i < 4; i ++){
          int newX = x + dx[i];
          int newY = y + dy[i];
          
          
          if (newX < n && newY < n && newX >=0 && newY >=0 && grid[newX][newY]!=0 && !visited[newX][newY])
        {
         findPathHelper(grid, n, visited, newX, newY, path + dir[i] , output);
        }
      }
      
      visited[x][y]= false;
      
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>> visited(n, vector<bool> (n));
        vector<string> output;
         findPathHelper(m, n, visited, 0, 0, "" , output);
         if (output.size() == 0) output.push_back("-1");
         sort(output.begin(), output.end());
         return output;
    }