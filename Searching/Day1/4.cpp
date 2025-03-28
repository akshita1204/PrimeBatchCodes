#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int x = 0, y = 0, ans = 0;

    while (x < n && y < m) {
        if (abs(a[x] - b[y]) <= k) { 
            ans++; 
            x++; 
            y++; 
        } 
        else if (a[x] < b[y] - k) x++;
        else y++;
    }

    cout << ans << endl;
    return 0;
}

//https://cses.fi/problemset/task/108