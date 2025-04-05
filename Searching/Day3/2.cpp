#include <bits/stdc++.h>
using namespace std;
bool f(vector<long long>&v,int mid,int wt)
{
    long long i=0,j=0,sum=0;
    while(j<v.size())
    {
        sum+=v[j];
        if(j-i+1>mid)
        {
            sum-=v[i];
            i++;
        }
        if(j-i+1==mid && sum>=wt) return true;
        j++;
        
    }
    return false;
    
}
int main() {
    // your code goes here
    long long n;
    cin>>n;
    vector<long long>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        
        int i=1,j=n,ans=0;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(f(v,mid,x))
            {
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//https://dashboard.programmingpathshala.com/renaissance/practice/question?questionId=121&sectionId=1&moduleId=2&topicId=6&subtopicId=82&homeworkId=17