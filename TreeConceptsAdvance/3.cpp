#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LOG = 20;

vector<int> adj[N];
int up[N][LOG];
int tin[N], tout[N], timer = 1;

void dfs(int node, int par) {
    tin[node] = timer++;
    up[node][0] = par;

    for (int i = 1; i < LOG; i++) {
        if (up[node][i - 1] == -1)
            up[node][i] = -1;
        else
            up[node][i] = up[up[node][i - 1]][i - 1];
    }

    for (int child : adj[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }

    tout[node] = timer++;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != -1 && !isAncestor(up[u][i], v)) {
            u = up[u][i];
        }
    }

    return up[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
        adj[i].push_back(boss);
    }

    dfs(1, -1); // root is 1

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}
//basic structure