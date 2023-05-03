//https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm
    //Flood Fill Algorithm 
    // approach -1 dfs TC - O(N*M) *4 where 4 is for directions
    //sc O(M*N)
    void dfsfloodFill(int row,int col,vector<vector<int>>& image,vector<vector<int>>& res,int init_color,int newColor
    ,int dx[],int dy[],int n,int m){
        res[row][col]=newColor;
        for(int i=0;i<4;i++){
            int nrow= dx[i]+row;
            int ncol = dy[i]+col;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == init_color && res[nrow][ncol]!= newColor)
                dfsfloodFill(nrow,ncol,image,res,init_color,newColor,dx,dy,n,m);
        }
    }

        void bfsfloodFill(int r,int c,vector<vector<int>>& ans,vector<vector<int>>&image,int init_color,int newColor)
    {
        queue<pair<int,int>>q;
        q.push({r,c});
        ans[r][c] = newColor;
        
        int n = image.size(),m = image[0].size();
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i =0;i<4;i++){
                int nrow = dx[i]+row;
                int ncol = dy[i]+col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=newColor && image[nrow][ncol]==init_color){
                    q.push({nrow,ncol});
                    ans[nrow][ncol]=newColor;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>>res = image;
        int n = image.size(),m = image[0].size();
        int init_color= image[sr][sc];
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        dfsfloodFill(sr,sc,image,res,init_color,newColor,dx,dy,n,m);
        // bfs(sr,sc,res,image,init_color,newColor);
        return res;
    }
