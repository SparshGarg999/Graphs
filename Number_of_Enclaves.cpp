//https://leetcode.com/problems/number-of-enclaves/
class Solution {
public:
void dfs(int row,int col,int n,int m, vector<vector<int>>&mat,vector<vector<int>>&vis,int dx[],int dy[]){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            
            int nrow = dx[i] + row;
            int ncol = dy[i] + col;
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol] == 1)
                dfs(nrow,ncol,n,m,mat,vis,dx,dy);
        }
    }

int numEnclaves(vector<vector<int>>& grid) {

            //BFS
        /*int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        //traverse rows
        int dx[4] = {-1,0,1,0}; //left and right
        int dy[4] = {0,1,0,-1};// bottom and top
        queue<pair<int,int>>q; // row col
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){*/
       /*------Boundary Traversal--------*/
// i==0 first col and i == n-1 is for last col
// j==0 first row and j == m-1 is for last row            
                /*if(i== 0 || i== n-1 || j == 0 || j== m-1){
                    if(grid[i][j] == 1){ 
                    q.push({i,j});
                    vis[i][j] = 1;
                    }
                }
               // vis[i][j] =0;
            }
        }
        

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r+dx[i];
                int ncol = c+dy[i];
        //check for valid row and col and check if cell is 1 and it should not we visited.
                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&& grid[nrow][ncol] == 1&&!vis[nrow][ncol])
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] =1;
                }
            }
            
        }
        // to manually count the valid 1's 
        // i.e it should not be a boundary cell or neighbour to it 
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){ 
                    cnt++;
                }
            }
        }
        return cnt;
  */
  // DFS
    for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0|| i== n-1|| j == 0|| j== m-1){
                    if(grid[i][j] == 1){
                        dfs(i,j,n,m,grid,vis,dx,dy);
                    }
                }
            }
        }
        int cnt=0;
        //check for 'O' which are not touched by boundary or which can be replaced
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]) // if it is not visited and its O 
                    cnt++; //convert it
            }
        }
        return cnt;
}
};
