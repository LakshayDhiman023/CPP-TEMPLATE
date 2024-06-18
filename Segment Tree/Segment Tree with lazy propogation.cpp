#include <bits/stdc++.h>
using namespace std;

class SGTree {
    vector<int> segTree;
    vector<int> lazy;
    vector<int> arr;

public:
    SGTree(int n, vector<int> &a) {
        segTree.resize(4 * n);
        lazy.resize(4 * n, 0);
        arr = a;
    }

    void build(int ind, int l, int r) {
        if (l == r) {
            segTree[ind] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * ind + 1, l, mid);
        build(2 * ind + 2, mid + 1, r);
        segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
    }

    void propagate(int ind, int l, int r) {
        if (lazy[ind] != 0) {
            segTree[ind] += (r - l + 1) * lazy[ind];
            if (l != r) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
    }

    void update(int ind, int l, int r, int left, int right, int val) {
        propagate(ind, l, r);
        if (l > right || r < left) {
            return;
        }
        if (l >= left && r <= right) {
            lazy[ind] += val;
            propagate(ind, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * ind + 1, l, mid, left, right, val);
        update(2 * ind + 2, mid + 1, r, left, right, val);
        segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
    }

    int query(int ind, int l, int r, int left, int right) {
        propagate(ind, l, r);
        if (l > right || r < left) {
            return 0;
        }
        if (l >= left && r <= right) {
            return segTree[ind];
        }
        int mid = (l + r) / 2;
        int lt = query(2 * ind + 1, l, mid, left, right);
        int rt = query(2 * ind + 2, mid + 1, r, left, right);
        return lt + rt;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    SGTree t1(n, arr);

    t1.build(0, 0, n - 1);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            cin >> a >> b;
            cout << t1.query(0, 0, n - 1, a, b) << endl;
        } else {
            int a, b, val;
            cin >> a >> b >> val;
            t1.update(0, 0, n - 1, a, b, val);
        }
    }
    return 0;
}
