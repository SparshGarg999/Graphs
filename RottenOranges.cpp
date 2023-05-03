https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

// rotten Oranges  TC - O(M*N)
//SC - O(M*N)
            int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int,int>,int>>q; // row col time 
    vector<vector<int>>vis(n,vector<int>(m,0));
    
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    int cntFresh =0;
    int actual_time=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2){
                vis[i][j] =2;
                q.push({{i,j},0});
            }
            //vis[i][j] = 0;
            if(grid[i][j] ==1) 
                cntFresh++; // keep count of freshOranges
        }
    }        
int cnt = 0;
while(!q.empty()){
    auto it = q.front();
    q.pop();
    int row = it.first.first;
    int col = it.first.second;
    int time = it.second;

    actual_time = max(time,actual_time);

    for(int i =0;i<4;i++){
        int nrow = dx[i]+row;
        int ncol = dy[i] + col;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol <m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
            q.push({{nrow,ncol},time+1});
            vis[nrow][ncol] = 2;
            cnt++;
        }
    }
}
    if(cnt!= cntFresh)return -1;
return actual_time;
