#include <bits/stdc++.h>
using namespace std;
int val[1005];
bool dp[1005][1005];
bool subset_sum(int i,int max)
{
    if(i<0)
    {
        if(max==0)return true;
        else return false;
    }
    if(val[i]<=max)
    {
        bool op1=subset_sum(i-1,max-val[i]);
        bool op2=subset_sum(i-1,max);
        dp[i][max]=op1 || op2;
        return dp[i][max];
    }
    else
    {
        dp[i][max]=subset_sum(i-1,max);
        return dp[i][max];
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>val[i];
    int m;
    cin>>m;
    memset(dp,-1,sizeof(dp));
    if(subset_sum(n-1,m))cout<<"yes\n";
    else cout<<"no\n";
    return 0;
}