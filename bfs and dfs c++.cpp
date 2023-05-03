vector<int>bfsGraph(int V,vector<int>adj[]){
    int vis[V] = {0};
    vector<int>bfs;
    queue<int>q;
    q.push(0); // 0 based indexing---
    vis[0]=1;
    while(!q.empty()){
        int node = q.front(); q.pop();
        bfs.push_back(node);
        for(auto it:adj[node]){
            vis[node] = 1;


            q.push(it);
        }
    }
    return bfs;
}

void dfs(int node,int vis[],vector<int>adj[],vector<int>&ans){
    vis[node] = 1;
    ans.push_back(node);
    for(auto it:adj[node]){ 
        if(!vis[it])
            dfs(it,vis,adj,ans);
    }
}

vector<int>dfsGraph(int V,vector<int>adj[]){
    int start = 0;
    vector<int>ans;
    int vis[V] = {0};
    dfs(start,vis,adj,ans);
    return ans;
}
