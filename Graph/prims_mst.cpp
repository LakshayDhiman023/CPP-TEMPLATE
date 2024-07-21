#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int weight;
    int node;
    int parent;
};

void primesAlgo(vector<vector<pair<int, int>>> &graph, int startNode)
{
    int n = graph.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<pair<int, int>> mstEdges;
    pq.push({0, {startNode, -1}});
    vector<bool> vis(n, 0);
    int mstWeight = 0;
    while (!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();
        if(vis[node]) continue;
        mstWeight += weight;
        vis[node] = 1;
        if(parent != -1){
            mstEdges.push_back({node, parent});
        }
        for(auto it: graph[node]){
            if(!vis[it.first]){
                pq.push({it.second, {it.first, node}});
            }
        }

        
    }
    cout<<"MST WEIGHT: "<<mstWeight<<endl;
    cout<<"MST Edges "<<endl;
    for(auto it: mstEdges){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
void printGraph(vector<vector<pair<int, int>>> &graph){
    int n = graph.size();
    for(int i = 1; i < n; i++){
        cout<<i<<" ";
        for(auto it: graph[i]) cout<<it.first<<" ";
        cout<<endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    // printGraph(graph);
    
    primesAlgo(graph, 1);
}