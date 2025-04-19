//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
             if(n <= 2) return 0;
        
        vector<int> inc(n,1);
        vector<int> dec(n,1);
        
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    inc[i] = max(inc[i],1+inc[j]);
                }
                
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[j] < nums[i]){
                    dec[i] = max(dec[i],1+dec[j]);
                }
            }
        }

        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dec[i] > 1 && inc[i] > 1){
                ans = max(ans,dec[i] + inc[i] -1);
            }
        }
        
        return ans;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends







//https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1