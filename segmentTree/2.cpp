#include <bits/stdc++.h>
using namespace std;

const long long maxi=1e5;
long long arr[maxi],tree[4*maxi];

long long buildTree(long long node, long long ss, long long se) {
    if (ss==se) {
        tree[node]=arr[ss];
        return tree[node];
    }
    long long mid = (ss + se) / 2;
    long long lval = buildTree(2 * node, ss, mid);
    long long rval = buildTree(2 * node + 1, mid + 1, se);
    tree[node] = lval + rval;
    return tree[node];
}

void update(long long idx, long long val, long long node, long long ss, long long se) {
    if (ss == se) {
        arr[idx] = val;
        tree[node] = val;
        return;
    }
    long long mid = (ss + se) / 2;
    if (idx <= mid)
        update(idx, val, 2 * node, ss, mid);
    else
        update(idx, val, 2 * node + 1, mid + 1, se);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

long long query(int l, int r, int node, int ss, int se) {
    // complete overlap
    if (ss >= l && se <= r - 1) return tree[node];
    // no overlap
    if (se < l || ss > r - 1) return 0;
    // partial overlap
   else
   {
    long long mid = (ss + se) / 2;
    long long left = query(l, r, 2 * node, ss, mid);
    long long right = query(l, r, 2 * node + 1, mid + 1, se);
    return left + right;
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildTree(1, 0, n - 1);

    while (m--) {
        long long type;
        cin >> type;
        if (type == 1) {
            long long i, v;
            cin >> i >> v;
            update(i, v, 1, 0, n - 1);
        } else if (type == 2) {
            long long l, r;
            cin >> l >> r;
            cout << query(l, r, 1, 0, n - 1) << '\n';
        }
    }

    return 0;
}
