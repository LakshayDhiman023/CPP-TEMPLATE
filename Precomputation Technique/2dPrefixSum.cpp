#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> prefixSum2D(vector<vector<int>> &v){
    int n = v.size(), m = v[0].size();
    vector<vector<int>> prefixSum (n + 1, vector<int> (m + 1, 0));
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + v[i - 1][j - 1];
        }
    }
    for(auto it: prefixSum){
        for(auto i: it) cout<<i<<" ";
        cout<<endl;
    }
    return prefixSum;
} 


void test_case(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>v[i][j];
        }
    }
    prefixSum2D(v);
}


int main(){
    int t= 1;
    // cin>>t;
    while(t--){
        test_case();
    }
    return 0;
}