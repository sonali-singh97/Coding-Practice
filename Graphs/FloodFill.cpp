
 int dx[4] = {0, 0,1, -1 };
 int dy[4] = {1, -1, 0, 0};
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       int row = image.size();
        int col = image[0].size();
        vector<vector<bool>> visited(row, vector<bool> (col));
        queue<pair<int, int>> q;
        q.push({sr,sc});
        int prevColor = image[sr][sc];
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            visited[x][y] = true;
            image[x][y] = newColor;
            
            for (int i = 0; i < 4; i ++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX < row && newY < col && newX>= 0 && newY >= 0 && !visited[newX][newY] && image[newX][newY] ==prevColor ){
                    q.push({newX, newY});
                }
            }

            
        }
        return image;
        
    }