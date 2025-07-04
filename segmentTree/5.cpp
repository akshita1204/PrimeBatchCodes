#include <bits/stdc++.h>
using namespace std;

const int n = 1e5;
int arr[n], tree[4 * n], lazy[4 * n];


int buildTree(int node, int ss, int se) {
    if (ss == se) {
        tree[node] = arr[ss];
        return tree[node];
    }
    int mid = ss + (se - ss) / 2;
    int lval = buildTree(2 * node, ss, mid);
    int rval = buildTree(2 * node + 1, mid + 1, se);
    tree[node] = max(lval, rval);
    return tree[node];
}


void propagate(int node, int val) {
    lazy[2 * node] += val;
    lazy[2 * node + 1] += val;
}

void update(int l, int r, int val, int node, int ss, int se) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        if (ss != se) propagate(node, lazy[node]);
        lazy[node] = 0;
    }

    if (r < ss || l > se) return; // No overlap

    if (ss >= l && se <= r) { // Complete overlap
        tree[node] += val;
        if (ss != se) propagate(node, val);
        return;
    }

    // Partial overlap
    int mid = ss + (se - ss) / 2;
    update(l, r, val, 2 * node, ss, mid);
    update(l, r, val, 2 * node + 1, mid + 1, se);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

// Query for range maximum with lazy propagation
int query(int l, int r, int node, int ss, int se) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        if (ss != se) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (r < ss || l > se) return INT_MIN; // No overlap

    if (ss >= l && se <= r) return tree[node]; // Complete overlap

    int mid = ss + (se - ss) / 2;
    int lval = query(l, r, 2 * node, ss, mid);
    int rval = query(l, r, 2 * node + 1, mid + 1, se);
    return max(lval, rval);
}

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    buildTree(1, 0, m - 1);
    cout << query(0, m - 1, 1, 0, m - 1) << endl;

    int val, l, r;
    cin >> val >> l >> r;

    // Apply the range update
    update(l, r, val, 1, 0, m - 1);

    // Query the max after the update
    cout << query(0, m - 1, 1, 0, m - 1) << endl;

    return 0;
}
//Lazy porp
