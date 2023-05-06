//https://leetcode.com/problems/surrounded-regions/

void dfs(int row,int col,int n,int m, vector<vector<char>>&mat,vector<vector<int>>&vis,int dx[],int dy[]){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            
            int nrow = dx[i] + row;// new row
            int ncol = dy[i] + col;// new col
            
//check if its and O and still not visited and check if nrow and ncol are valid or not

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
                dfs(nrow,ncol,n,m,mat,vis,dx,dy);
        }
    }

int n= mat.size();
        int m= mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        //traverse rows
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
            
         for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0|| i== n-1|| j == 0|| j== m-1){
                    if(mat[i][j] == 'O'){
                        dfs(i,j,n,m,mat,vis,dx,dy);
                    }
                }
            }
        }

        //check for 'O' which are not touched by boundary or which can be replaced
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 'O'&& !vis[i][j]) // if it is not visited and its O 
                    mat[i][j] = 'X'; //convert it
            }
        }
