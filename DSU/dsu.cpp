#include <bits/stdc++.h>
using namespace std;


class dsu{
    private: 
        vector<int> rank, parent;
    public:
        dsu(int n){
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            for(int i = 1; i < n + 1; i++) parent[i] = i;
        }

        int findParent(int u){
            if(u == parent[u]) return u;
            return parent[u] = findParent(parent[u]);
        }

        void unionByRank(int u, int v){
            int u_p = findParent(u);
            int v_p = findParent(v);

            if(u_p == v_p) return ;
            if(rank[u_p] < rank[v_p]){
                parent[u] = v;
            }
            else if(rank[v_p] < rank[u_p]){
                parent[v] = u;
            }
            else{
                parent[v] = u;
                rank[u]++;
            }
        }

};


int main(){
    int n, m;
    cin>>n>>m;
    dsu g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        if(i == m - 2){
            if(g.findParent(a) == g.findParent(b)) cout<<"SAME"<<endl;
            else cout<<"NOT SAME";
        }
        g.unionByRank(a, b);
        if(i == m - 2){
            if(g.findParent(a) == g.findParent(b)) cout<<"SAME"<<endl;
            else cout<<"NOT SAME";
        }
        
    }
}