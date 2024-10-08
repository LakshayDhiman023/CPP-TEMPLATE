#include <bits/stdc++.h>
using namespace std;





int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    vector<vector<int>> sparseTable(n, vector<int> (log2(n) + 1));
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        sparseTable[i][0] = v[i];
    }



    for(int i = 1; i < log2(n) + 1; i++){
        for(int j = 0; j + (1 << i) - 1 < n; j++){
            sparseTable[j][i] = min(sparseTable[j][i - 1], sparseTable[j + (1 << (i - 1))][i - 1]);
        }
    }

    int q;
    cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b;
        int len = b - a + 1;

        int k = log2(len);

        cout<<min(sparseTable[a][k], sparseTable[b - (1 << k) + 1][k])<<endl;

    }


}