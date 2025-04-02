#include <bits/stdc++.h>
using namespace std;

int lower(vector<int>& arr, int start, int target) {
    int left = start, right = arr.size(), ans=arr.size();
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target)
            {
                ans=mid;
                right = mid-1;
            }
        else
            left = mid + 1;
    }
    return ans;
}

int upper(vector<int>& arr, int start, int target) {
    int left = start, right = arr.size(), ans=arr.size();
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target)
            {
                ans=mid;
                right = mid-1;
            }
        else
            left = mid + 1;
    }
    return left;
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    
    long long count = 0;

    for (int i = 0; i < n; i++) {
        int left = lower(a, i + 1, l - a[i]);  //pehla index jisme "target ya usse bada" element ho
        int right = upper(a, i + 1, r - a[i]); //pehla index jisme target se bada hoga to usse pehle tk ke hi count me aayeng

        count += (right - left); 
    }

    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


//https://codeforces.com/problemset/problem/1538/C