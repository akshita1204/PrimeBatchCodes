#include<bits/stdc++.h>
using namespace std;
long long f(long long a,long long b)
{
  if(a==0 or b==0) return 0;
  if(a>=b) return a/b+f(a%b,b);
  else if(b>a) return b/a+f(a,b%a);
  
}
int main()
{
  long long a,b;
  cin>>a>>b;
  if(a==b) cout<<a<<endl;
  else cout<<f(a,b)<<endl;
  
}
//https://codeforces.com/problemset/problem/343/A#:~:text=Problem%20%2D%20343A%20%2D%20Codeforces&text=Mad%20scientist%20Mike%20is%20building,unit%20resistance%20R%200%20%3D%201.