#include <bits/stdc++.h>
using namespace std;
bool f(vector<long long>&v,int mid,int d)
{
    int c=1,sum=0;
    for(int i=0;i<v.size();i++)
    {
        if(sum+v[i]<=mid)
        {
            sum=sum+v[i];
        }
        else
        {
            c++;
            sum=v[i];
        }
    }
    return c<=d;
}
int main() {
   int n;
   cin>>n;
   vector<long long>v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   int t;
   cin>>t;
   while(t--)
   {
       int w;
       cin>>w;
       int i=*max_element(v.begin(),v.end());
       int j=accumulate(v.begin(),v.end(),0);
       int ans=-1;
       while(i<=j)
       {
           int mid=(i+j)/2;
           if(f(v,mid,w))
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
//https://dashboard.programmingpathshala.com/renaissance/practice/question?questionId=122&sectionId=1&moduleId=2&topicId=6&subtopicId=82&homeworkId=1