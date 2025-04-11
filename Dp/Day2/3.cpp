
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int countWays(const string& s, const vector<int>&a) {
    int n= s.length();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int mini= INT_MAX;
        for (int j = i; j >= 1; --j) {
            int ch = s[j - 1] - 'a';
            mini = min(mini, a[ch]);
            if (i-j +1 > mini) break;
            dp[i] = (dp[i] + dp[j-1]) % MOD;
        }
    }
    return dp[n];
}

int Length(const string& s, const vector<int>& a) {
    int n = s.length();
    int maxi = 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        int mini= INT_MAX;
        for (int j = i; j >= 1; --j) {
            int ch = s[j - 1] - 'a';
            mini = min(mini, a[ch]);
            if (i - j + 1 > mini) break;
            if (dp[j - 1]) {
                maxi = max(maxi, i - j + 1);
                dp[i] = 1;
            }
        }
    }
    return maxi;
}

int Parts(const string& s, const vector<int>& a) {
    int n = s.length();
    vector<int> minparts(n + 1, INT_MAX);
    minparts[0] = 0;

    for (int i = 1; i <= n; ++i) {
        int mini= INT_MAX;
        for (int j = i; j >= 1; --j) {
            int ch = s[j - 1] - 'a';
            mini = min(mini, a[ch]);
            if (i - j + 1 > mini) break;
            if (minparts[j - 1] != INT_MAX)
                minparts[i] = min(minparts[i], minparts[j - 1] + 1);
        }
    }
    return minparts[n];
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>a(26);
    for (int i = 0; i < 26; ++i) cin >> a[i];

    cout << countWays(s, a) << '\n';
    cout << Length(s, a) << '\n';
    cout << Parts(s, a) << '\n';

    return 0;
}


//https://codeforces.com/problemset/problem/766/C