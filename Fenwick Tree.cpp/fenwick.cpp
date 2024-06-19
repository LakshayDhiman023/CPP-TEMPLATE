#include <bits/stdc++.h>
using namespace std;


int next(int i){
    return i + (i & -i);
}

int prev(int i){
    return i - (i & -i);
}


void update(vector<int> &fenwik, int i, int add){
    while(i < fenwik.size()){
        fenwik[i] += add;
        i = next(i);
    }
}

int sum(vector<int> &fenwick, int i){
    int ans = 0;
    while(i > 0){
        ans += fenwick[i];
        i = prev(i);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> fenwick(n + 1, 0);
    for(int i = 1; i < n + 1; i++){
        int a;
        cin>>a;
        update(fenwick, i, a);
    }

    int q;
    cin>>q;
    while(q--){
        int l , r;
        cin>>l>>r;
        cout<<sum(fenwick, r) - sum(fenwick, l - 1)<<endl;
    }
}