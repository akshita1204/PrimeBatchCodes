/* 
class Solution {
    public:
        int kthGrammar(int n, int k) {
          //Binry Search Approach 
          int low=1, high=pow(2,n-1);
          int ans=0;
          while(low!=high)
          {
            int mid=low+(high-low)/2;
            if(k<=mid) high=mid;
            else 
            {
                low=mid+1;
                ans=1-ans;
            }
          }
          return ans;
            
        }
    };

*/

//https://leetcode.com/problems/k-th-symbol-in-grammar/description/