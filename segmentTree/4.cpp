#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct Node {
    long long minVal;
    int count;
};

Node tree[4 * MAXN];
long long arr[MAXN];

Node combine(Node left, Node right) {
    if (left.minVal < right.minVal) return left;
    if (right.minVal < left.minVal) return right;
    return {left.minVal, left.count + right.count};
}

void build(int node, int ss, int se) {
    if (ss == se) {
        tree[node] = {arr[ss], 1};
        return;
    }
    int mid = (ss + se) / 2;
    build(2 * node, ss, mid);
    build(2 * node + 1, mid + 1, se);
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

void update(int idx, long long val, int node, int ss, int se) {
    if (ss == se) {
        arr[idx] = val;
        tree[node] = {val, 1};
        return;
    }
    int mid = (ss + se) / 2;
    if (idx <= mid)
        update(idx, val, 2 * node, ss, mid);
    else
        update(idx, val, 2 * node + 1, mid + 1, se);
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

Node query(int l, int r, int node, int ss, int se) {
    // no overlap
    if (se < l || ss >= r) return {LLONG_MAX, 0};
    // complete overlap
    if (ss >= l && se < r) return tree[node];
    // partial overlap
    int mid = (ss + se) / 2;
    Node left = query(l, r, 2 * node, ss, mid);
    Node right = query(l, r, 2 * node + 1, mid + 1, se);
    return combine(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n - 1);

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i;
            long long v;
            cin >> i >> v;
            update(i, v, 1, 0, n - 1);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            Node res = query(l, r, 1, 0, n - 1);
            cout << res.minVal << " " << res.count << '\n';
        }
    }

    return 0;
}
//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C