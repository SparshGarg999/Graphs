//https://practice.geeksforgeeks.org/problems/hamiltonian-path2522/1
/*
A Hamiltonian path, is a path in an undirected graph that visits each vertex exactly once. 
*/
Class Solution
{
    bool dfs(int node,vector<int>&vis,vector<int>adj[],int V,int cnt){
        vis[node] =1;
        cnt++;
        if(cnt == V) return true;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,adj,V,cnt) == true) return true;
            }
        }
        cnt--;
        vis[node]=0;
        return false;
    }
    public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<int>adj[N];
        for(auto it:Edges){
            int u = it[0]-1; int v = it[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(N,0);
        int cnt = 0;
        for(int i = 0;i<N;i++){
            if(!vis[i]){
                cnt= 0 ;
                if(dfs(i,vis,adj,N,cnt) == true) return true;
            }
        }
        return false;
    }
};
