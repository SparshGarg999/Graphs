
//Number of Provinces
//approach-1 DFS 
/*
TC - O(V+E) + O(N)
SC - O(N) + O(2*E)
*/
void dfsNumberofProvinces(int node,vector<int>&vis,vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it])
            dfsNumberofProvinces(it,vis,adj);
    }
}
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        /*DisjointSet st(V);
        for(int i=0;i<V;i++){+
            for(int j =0;j<V;j++){
                if(adj[i][j] == 1) st.SizeByUnion(i,j);
            }
        }
        int cnt=0;
        for(int i = 0; i< V;i++)if(st.parent[i] == i) cnt++;return cnt;*/
        
        vector<int>adjL[V];
        for(int i=0;i<V;i++){
            for(int j = 0;j<V;j++){
                if(adj[i][j]){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        int cnt= 0;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfsNumberofProvinces(i,vis,adjL);
            }
        }
        return cnt;
    //approach -2 
    /*
    TC - O(V+E) + O(N)
    Sc - O(2*E) + O(N)
    */ 
        queue<int> q;
        vector<int> vis(V,0);
        int cnt=0;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                vis[i] =1;
                q.push(i);
                cnt++;
            while(!q.empty()){
                int node = q.front();q.pop();
                for(auto it:adjL[node]) {
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
        }
    }
    return cnt;
} 
