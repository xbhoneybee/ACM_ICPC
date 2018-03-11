```
class Solution {
private:
    bool vis[20];
    vector<vector<int>>ans;
    void DFS(int now,int goal,vector<int>&path,vector<vector<int>>& graph){
        if(now==goal){
            this->ans.push_back(path);
            return;
        }
        for(int i=0;i<graph[now].size();i++){
            int to=graph[now][i];
            if(vis[to]==false){
                vis[to]=true;
                path.push_back(to);
                DFS(to,goal,path,graph);
                vis[to]=false;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>add;
        add.push_back(0);
        ans.clear();
        DFS(0,n-1,add,graph);
        return this->ans;
    }
};
```
