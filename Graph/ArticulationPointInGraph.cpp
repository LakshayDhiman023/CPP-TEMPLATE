#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> discovery;
vector<int> low;
vector<bool> visited;
int timer = 0;
vector<int> articulationPoints;

void dfs(int node, int parent){
    low[node] = discovery[node] = timer;
    visited[node] = 1;
    timer++;
    int children = 0;
    for(int i: graph[node]){
        if(i == parent) continue;
        if (visited[i]) {
            low[node] = min(low[node], discovery[i]);
        } else {
            dfs(i, node);
            low[node] = min(low[node], low[i]);
            if (low[i] >= discovery[node] && parent!=-1)
                articulationPoints.push_back(node);
            ++children;
        }
    }
    if(parent == -1 && children > 1){
        articulationPoints.push_back(node);
    }
}






int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        // vector<vector<int>> adj(n + 1);
        graph.resize(n + 1);

        for(int i = 0; i < m; i++){
            int a, b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        visited.resize(n + 1, 0);
        low.resize(n + 1, -1);
        discovery.resize(n + 1, -1);
        // timer = 0;
        for(int i= 1; i < n + 1; i++){
            if(!visited[i]){
                dfs(i, -1);
            }
        }
        dfs(1, -1);
        for(auto it: articulationPoints){
            cout<<it<<" ";
        }
    }
}