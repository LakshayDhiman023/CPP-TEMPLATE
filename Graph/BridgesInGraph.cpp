#include <bits/stdc++.h>
using namespace std;

vector<int> low;
vector<int> discovery;
vector<bool> visited;
int timer = 0;
vector<vector<int>> graph;
vector<pair<int, int>> bridges;

void dfs(int node, int parent){
    discovery[node] = low[node] = timer;
    visited[node] = 1;
    timer++;
    for(int i: graph[node]){
        if(i == parent) continue;
        if(!visited[i]){
            dfs(i, node);
            low[node] = min(low[node], low[i]);
            if(low[i] > discovery[node]){
                bridges.push_back({node, i});
            }
        }
        else{
            low[node] = min(low[node], discovery[i]);
        }
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < m; i++){
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        graph = adj;
        visited.resize(n + 1, 0);
        low.resize(n + 1);
        discovery.resize(n + 1);
        dfs(1, -1);
        for(auto it: bridges){
            cout<<it.first<<" "<<it.second<<endl;
        }



    }
}