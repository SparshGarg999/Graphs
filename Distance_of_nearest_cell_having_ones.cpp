//https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

    //distance of nearest cell having 1's
// approach 1 bfs and 2nd dfs
    void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis,vector<vector<int>>&dist,int steps){
        vis[row][col] =1;
        //steps++;
        dist[row][col] = steps;
        int dx[4] = {-1,0,1,0};
        int n = grid.size();
        int m = grid[0].size();
	    int dy[4] = {0,1,0,-1};
        for(int i =0;i<4;i++){
	            
	            int nrow = row+dx[i];
	                    
	            int ncol = col+dy[i];
	            
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0){ steps++;
                    dfs(nrow,ncol,grid,vis,dist,steps);
            }
        }
    }
    vector<vector<int>>nearest(vector<vector<int>>grid)
	{
                int n = grid.size(); int m = grid[0].size();

        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j= 0;j<m;j++){
            if(grid[i][j] == 1){
                q.push({{i,j},0});
                vis[i][j] =1;
            }
        }
    }
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int row = it.first.first;
        int col = it.first.second;
        int step = it.second;

        dist[row][col] =step; 
        for(int i=0;i<4;i++){
            int nrow = dx[i] + row;
            int ncol = dy[i] + col;
            if(nrow>= 0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol]){
                q.push({{nrow,ncol},step+1});
                vis[nrow][ncol] =1;
            }
        }
    }
    return dist;
      	    return dist;*/
	    /*int n = grid.size();int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        int steps=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1&& !vis[i][j])
                    dfs(i,j,grid,vis,dist,steps);
            }
        }
        return dist;*/
	}
