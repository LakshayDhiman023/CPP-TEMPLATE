#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9;

vector<vector<int>> floyd_warshall(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<int>> ans = graph;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[i][k] < MOD && ans[k][j] < MOD) {
                    ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
                }
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, MOD));

    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    vector<vector<int>> distance = floyd_warshall(graph);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (distance[i][j] == MOD) {
                cout << i << " " << j << " INF" << endl;
            } else {
                cout << i << " " << j << " " <<distance[i][j] << endl;
            }
        }
    }

    return 0;
}
