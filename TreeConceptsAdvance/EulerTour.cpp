#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int timein[N], timeout[N], timer = 1;

bool isAncestor(int u, int v) {
    return timein[v] >= timein[u] && timeout[v] <= timeout[u];
}

void dfs(int node, int par) {
    timein[node] = timer;
    timer++;
    for (int child : adj[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }
    timeout[node] = timer;
    timer++;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    // example queries
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (isAncestor(u, v))
            cout << "YES: " << u << " is an ancestor of " << v << '\n';
        else
            cout << "NO: " << u << " is NOT an ancestor of " << v << '\n';
    }

    return 0;
}
