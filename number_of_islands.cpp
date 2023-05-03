//Find the number of islands
//approach -1 dfs
    void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis,int n,int m){
        vis[row][col] =1;
        int dx[8] = {-1,-1,0,1,1,1,0,-1};
        int dy[8] = {0,1,1,1,0,-1,-1,-1};
        for(int i= 0;i<8;i++){
            int nrow = row+dx[i];
            int ncol = col+ dy[i];
            if(nrow>=0&& nrow<n && ncol>= 0 && ncol<m &&
            !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow,ncol,grid,vis,n,m);   
            }
        }
    }

void bfsnumIslands(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis,int n,int m){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int dx[8] = {-1,-1,0,1,1,1,0,-1};
        int dy[8] = {0,1,1,1,0,-1,-1,-1};

        /*
        Instead of using dx and dy we could've used 
        for(int delRow = -1;delRow<=1;delRow++){
            for(int delCol =-1;delCol<=1;delCol++){
                and same find nrow using delRow + r
                and delCol + c
        */
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i= 0;i<8;i++)
            {
                int nrow = dx[i]+r;
                int ncol = dy[i]+c;
                if(nrow>=0&& nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    vis[nrow][ncol] =1;
                    q.push({nrow,ncol});
                }
            }
        }
    }

int numIslands(vector<vector<char>>& grid) {
//dfs
    int n = grid.size(); int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,grid,vis,n,m);
                }
            }
        }
        return cnt;
// bfs
        int n = grid.size();int m = grid[0].size(); int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]== '1'){
                    cnt++;
                    bfsnumIslands(i,j,grid,vis,n,m);
                }
            }
        }
        return cnt;
        
    }
