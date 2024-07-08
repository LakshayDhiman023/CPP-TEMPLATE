#include <bits/stdc++.h>
using namespace std;

void dfs1(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &order, int node) {
    vis[node] = 1;
    for(int it : adj[node]) {
        if(!vis[it]) {
            dfs1(adj, vis, order, it);
        }
    }
    order.push_back(node);
}

void dfs2(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &component, int node) {
    vis[node] = 1;
    component.push_back(node);
    for(int it : adj[node]) {
        if(!vis[it]) {
            dfs2(adj, vis, component, it);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> order;
    vector<bool> vis(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs1(adj, vis, order, i);
        }
    }

    reverse(order.begin(), order.end());

    vector<vector<int>> adjT(n + 1);
    for(int i = 1; i <= n; i++) {
        vis[i] = 0;
        for(auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }

    vector<vector<int>> scc;
    for(int i : order) {
        if(!vis[i]) {
            vector<int> component;
            dfs2(adjT, vis, component, i);
            scc.push_back(component);
        }
    }

    cout << scc.size() << endl;
    for(auto &comp : scc) {
        for(int node : comp) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
