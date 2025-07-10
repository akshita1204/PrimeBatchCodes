#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;          
const int L = 20;           
vector<int> adj[N];
int up[N][L];               

void dfs(int node, int par) {
    up[node][0] = par;           // 2^0 = 1, immediate parent

    for (int i = 1; i < L; i++) {
        up[node][i] = up[up[node][i - 1]][i - 1];
    }

    for (int child : adj[node]) {
        if (child != par)
            dfs(child, node);
    }
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

    dfs(1, 1); // root node is 1, parent of root is itself

    int q;
    cin >> q;
    while (q--) {
        int node, k;
        cin >> node >> k;
        for (int i = 0; i < L; i++) {
            if (k & (1 << i)) {
                node = up[node][i];
            }
        }
        cout << node << '\n';
    }

    return 0;
}
