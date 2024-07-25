#include <bits/stdc++.h>
using namespace std;

class DisJointSet {
private:
    vector<int> rank, parent;

public:
    DisJointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if (parent[u] != u)
            parent[u] = findParent(parent[u]);
        return parent[u];
    }

    void unionByRank(int u, int v) {
        int u_p = findParent(u);
        int v_p = findParent(v);

        if (u_p == v_p) return;

        if (rank[u_p] < rank[v_p]) {
            parent[u_p] = v_p;
        } else if (rank[u_p] > rank[v_p]) {
            parent[v_p] = u_p;
        } else {
            parent[v_p] = u_p;
            rank[u_p]++;
        }
    }
};

int kruskalMST(int n, vector<pair<int, pair<int, int>>> &edges, vector<pair<int, pair<int, int>>> &mstEdges) {
    sort(edges.begin(), edges.end());
    DisJointSet ds(n);
    int mstWeight = 0;

    for (auto &edge : edges) {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (ds.findParent(u) != ds.findParent(v)) {
            ds.unionByRank(u, v);
            mstWeight += wt;
            mstEdges.push_back(edge);
        }
    }

    return mstWeight;
}

void SecondBestMST(vector<pair<int, pair<int, int>>> &edges, int n) {
    vector<pair<int, pair<int, int>>> mstEdges;
    int mstWeight = kruskalMST(n, edges, mstEdges);
    int secondBestMSTWeight = INT_MAX;
    vector<pair<int, pair<int, int>>> secondBestMstEdges;

    for (int i = 0; i < mstEdges.size(); i++) {
        DisJointSet ds(n);
        int currentWeight = 0;
        vector<pair<int, pair<int, int>>> currentMstEdges;
        int edgeCount = 0;

        for (int j = 0; j < edges.size(); j++) {
            if (edges[j] == mstEdges[i]) continue;

            int wt = edges[j].first;
            int u = edges[j].second.first;
            int v = edges[j].second.second;

            if (ds.findParent(u) != ds.findParent(v)) {
                ds.unionByRank(u, v);
                currentWeight += wt;
                currentMstEdges.push_back(edges[j]);
                edgeCount++;
            }
        }

        if (edgeCount == n - 1 && currentWeight < secondBestMSTWeight) {
            secondBestMSTWeight = currentWeight;
            secondBestMstEdges = currentMstEdges;
        }
    }
    cout<<endl;

    if (secondBestMSTWeight == INT_MAX) {
        cout << "No second-best MST exists." << endl;
    } else {
        cout << "Second-best MST weight: " << secondBestMSTWeight << endl;
        cout << "Second-best MST edges:" << endl;
        for (auto &edge : secondBestMstEdges) {
            cout << edge.second.first << " " << edge.second.second << " " << edge.first << endl;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    SecondBestMST(edges, n);
    return 0;
}
