https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
//detect cycle in undirected graph 
//TC - O(V+E) +O(N)
//SC - O(N)
bool bfs(int node,vector<int>adj[],vector<int>&vis){
    queue<pair<int,int>>q; // node parent
    q.push({node,-1});
    vis[node]=1;
    while(!q.empty()){
        int curr = q.front().first;
        int par = q.front().second;
        q.pop();

        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it,node});
            }else if(par!= it) return true;
        }
    }
}
bool dfsisCycle(int node,int parent,vector<int>adj[],int vis[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfsisCycle(it,node,adj,vis) == true) return true;
        }else if(it!= parent){
            return true;
        }
    }
}
bool isCycle(int V, vector<int> adj[]) {
    int vis[V];
    memset(vis,0,V);
    //vector<int>vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfsisCycle(i,-1,adj,vis) == true) return true;
        }
    }
    return true;
    }
