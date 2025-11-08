class Solution {
public:
void dfs(int node,vector<vector<int>>&adj,vector<int>&visited){
	visited[node]=1;
	for(int j=0;j<adj.size();j++){
		if(adj[node][j]==1&&!visited[j]){
			dfs(j,adj,visited);
		}
	}
}
int findCircleNum(vector<vector<int>>& isConnected) {
	    int n=isConnected.size();
        int cnt=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
        	if(!visited[i]){
        		cnt++;
        		dfs(i,isConnected,visited);
        	}
        }
        return cnt;
    }
};