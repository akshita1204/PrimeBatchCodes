#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long tree[4 * N], lazy[4 * N];

void update(int l, int r, int val, int node, int ss, int se) {

    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        if (ss != se) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (se < l || ss >= r) return;
    if (l <= ss && se < r) {
        tree[node] += val;
        if (ss != se) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }

    int mid = (ss + se) / 2;
    update(l, r, val, 2 * node, ss, mid);
    update(l, r, val, 2 * node + 1, mid + 1, se);
}

long long query(int i, int node, int ss, int se) {

    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        if (ss != se) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (ss == se) return tree[node];

    int mid = (ss + se) / 2;
    if (i <= mid) return query(i, 2 * node, ss, mid);
    else return query(i, 2 * node + 1, mid + 1, se);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            update(l, r, v, 1, 0, n - 1); 
        } else {
            int i;
            cin >> i;
            cout << query(i, 1, 0, n - 1) << '\n';
        }
    }

    return 0;
}
