#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int tree[4 * N], lazy[4 * N];
bool isLazySet[4 * N]; // true if lazy[node] is a pending assignment

void push(int node, int ss, int se) {
    if (isLazySet[node]) {
        tree[node] = lazy[node];
        if (ss != se) {
            isLazySet[2 * node] = true;
            isLazySet[2 * node + 1] = true;
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        isLazySet[node] = false;
    }
}

void update(int l, int r, int val, int node, int ss, int se) {
    push(node, ss, se);

    if (se < l || ss >= r) return; // No overlap

    if (l <= ss && se < r) { // Complete overlap
        isLazySet[node] = true;
        lazy[node] = val;
        push(node, ss, se);
        return;
    }

    int mid = (ss + se) / 2;
    update(l, r, val, 2 * node, ss, mid);
    update(l, r, val, 2 * node + 1, mid + 1, se);
    tree[node] = -1; // Doesn't matter for point query use-case
}

int query(int i, int node, int ss, int se) {
    push(node, ss, se);

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
            update(l, r, v, 1, 0, n - 1); // r is exclusive
        } else {
            int i;
            cin >> i;
            cout << query(i, 1, 0, n - 1) << '\n';
        }
    }

    return 0;
}
