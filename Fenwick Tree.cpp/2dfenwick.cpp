#include <bits/stdc++.h>
using namespace std;


int next(int i){
    return i + (i & -i);
}

int prev(int i){
    return i - (i & -i);
}


void update(int x, int y, int add, vector<vector<int>> &v){
    int xdash = x;
    while(xdash < v.size()){
        int ydash = y;
        while(ydash < v[0].size()){
            v[xdash][ydash] += add;
            ydash = next(ydash);
        }
        xdash = next(xdash);
    }
}

int prefixSum (int x, int y, vector<vector<int>> &v){
    int sum = 0;
    int xdash = x;
    while(xdash > 0){
        int ydash = y;
        while(ydash > 0){
            sum += v[xdash][ydash];
            ydash = prev(ydash);
        }
        xdash = prev(xdash);
    }
    return sum;
}

int query(int x1, int y1, int x2, int y2, vector<vector<int>> &v){
    int inc1 = prefixSum(x2, y2, v);
    int exc1 = prefixSum(x1 - 1, y2, v);
    int exc2 = prefixSum(x2, y1 - 1, v);
    int inc2 = prefixSum(x1 - 1, y1 - 1, v);
    return inc1 - exc1 - exc2 + inc2;

}




int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n + 1, vector<int> (m + 1, 0));

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            int a;
            cin>>a;
            update(i, j, a, v);
        }
    }
    for(auto it: v){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int q;
    cin>>q;
    while(q--){
        int l1, r1, l2, r2;
        cin>>l1>>r1>>l2>>r2;
        cout<<query(l1, r1, l2, r2, v)<<endl;
        // cout<<1<<endl;
    }
}