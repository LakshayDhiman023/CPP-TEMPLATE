#include <bits/stdc++.h>
using namespace std;

class SGTree{
    vector<int> segTree;
    vector<int> arr;
    public:
        SGTree(int n, vector<int> &a){
            segTree.resize(4 * n);
            arr = a;
        }

        void build(int ind, int l, int r){
            if(l == r){
                segTree[ind] = arr[l];
                return;
            }
            int mid = (l + r) / 2;
            build(2 * ind + 1, l, mid);
            build(2 * ind + 2, mid + 1, r);
            segTree[ind] = max(segTree[2 * ind + 1], segTree[2 * ind + 2]);
        }


        int query(int ind, int left, int right, int l, int r){
            if(l > right | r < left){
                return INT_MIN;
            }
            if(l >= left && r <= right){
                return segTree[ind];
            }
            int mid = (l + r) /2;
            int lt = query(2 * ind + 1, left, right, l, mid);
            int rt = query(2 * ind + 2, left, right, mid + 1, r);
            return segTree[ind] = max(lt, rt);
        }

        void update(int ind, int l, int r, int idx, int val){
            if(l == r){
                segTree[ind] = val;
                arr[idx] = val;
                return;
            }
            int mid = (l + r) / 2;
            update(2 * ind + 1, l, mid, idx, val);
            update(2 * ind + 2, mid + 1, r, idx, val);
            segTree[ind] = max(segTree[2 * ind + 1], segTree[2 * ind + 2]);
        }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    SGTree t1(n, arr);
    int q;
    cin>>q;
    t1.build(0, 0, n - 1);

    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int a, b;
            cin>>a>>b;
            cout<<t1.query(0, 0, n - 1, a, b)<<endl;
        }
        else{
            int idx, val;
            cin>>idx>>val;
            idx--;
            t1.update(0, 0, n - 1, idx, val);
        }
    }
    return 0;
}