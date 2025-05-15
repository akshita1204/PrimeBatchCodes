/*

class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>v;
        int n=speed.size();
        for(int i=0;i<n;i++)
        {
            double time=(double)(target-position[i])/speed[i];
            v.push_back({position[i],time});
        }
        sort(v.rbegin(),v.rend());
        int ans=0;
        double maxi=0;
        for(int i=0;i<n;i++)
        {
            if(v[i].second>maxi)
            {
                maxi=v[i].second;
                ans++;
            }
        }
        return ans;

    }
};
*/
//https://leetcode.com/problems/car-fleet/