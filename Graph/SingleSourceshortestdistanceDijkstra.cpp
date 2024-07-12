#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void dijkstra(vector<vector<pair<int, int>>> &graph, vector<int> &distance, vector<int> &parent, int start) {
    int n = graph.size();
    distance.assign(n, INF);
    parent.assign(n, -1);
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (dist > distance[u]) continue;
        
        for (auto &edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
}

int main() {
    int n, m; // number of nodes and edges
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // If the graph is undirected
    }
    
    int start;
    cin >> start;
    
    vector<int> distance, parent;
    dijkstra(graph, distance, parent, start);
    
    for (int i = 0; i < n; ++i) {
        if (distance[i] == INF) {
            cout << "Node " << i << ": unreachable" << endl;
        } else {
            cout << "Node " << i << ": " << distance[i] << endl;
        }
    }
    
    return 0;
}
