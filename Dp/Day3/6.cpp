#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
vector<int> coins;
vector<int> dp;

int countWays(int x) {
    if (x == 0) return 1;
    if (dp[x] != -1) return dp[x];

    long long ways = 0;
    for (int coin : coins) {
        if (x - coin >= 0) {
            ways = (ways + countWays(x - coin)) % mod;
        }
    }
    return dp[x] = ways;
}

int main() {
    int n, x;
    cin >> n >> x;
    coins.resize(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];

    dp.assign(x + 1, -1);
    cout << countWays(x) << endl;
    return 0;
}

//https://cses.fi/problemset/task/1635/