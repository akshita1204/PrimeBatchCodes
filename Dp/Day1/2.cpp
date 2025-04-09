#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int dp[1000001];

int f(int num) {
    if (num == 0) return 1;
    if (dp[num] != -1) return dp[num];

    int ways = 0;
    for (int i = 1; i <= 6; i++) {
        if (num - i >= 0) {
            ways += f(num - i);
            ways %= mod;
        }
    }
    return dp[num] = ways;
}

int main() {
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(n);
}





//https://cses.fi/problemset/task/1633